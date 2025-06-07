#include "../include/Reservas.h" 
#include <iostream>
#include <limits> 



void agregarReserva(std::vector<Reserva>& lista) { 
    Reserva r;
    std::cout << "--- Agregar Nueva Reserva ---\n";
    std::cout << "Numero de reserva: ";
    while (!(std::cin >> r.numeroReserva)) {
        std::cout << "Entrada invalida. Ingrese un numero: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Fecha de reserva (dd/mm/yyyy): ";
    std::getline(std::cin, r.fechaReserva);
    char pagoChar;
    std::cout << "Estado de pago (s=Pagado, n=No pagado): ";
    std::cin >> pagoChar;
    r.estadoPago = (pagoChar == 's' || pagoChar == 'S');
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "DUI del pasajero: ";
    std::getline(std::cin, r.duiPasajero);
    std::cout << "Codigo de vuelo: ";
    std::getline(std::cin, r.codigoVuelo);
    r.activo = true;
    lista.push_back(r);
    std::cout << "Reserva agregada a la memoria. Guarde para persistir.\n";
}

void editarReserva(std::vector<Reserva>& lista) { 
    int num;
    std::cout << "--- Editar Reserva ---\n";
    std::cout << "Ingrese numero de reserva a editar: ";
    while (!(std::cin >> num)) {
        std::cout << "Entrada invalida. Ingrese un numero: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    bool encontrada = false;
    for (auto &r : lista) {
        if (r.numeroReserva == num && r.activo) {
            std::cout << "Reserva encontrada. Ingrese nuevos datos:\n";
            std::cout << "Nueva fecha de reserva (actual: " << r.fechaReserva << "): ";
            std::getline(std::cin, r.fechaReserva);
            char pagoChar;
            std::cout << "Nuevo estado de pago (s=Pagado, n=No pagado, actual: " << (r.estadoPago ? "Pagado" : "No pagado") << "): ";
            std::cin >> pagoChar;
            r.estadoPago = (pagoChar == 's' || pagoChar == 'S');
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Nuevo DUI del pasajero (actual: " << r.duiPasajero << "): ";
            std::getline(std::cin, r.duiPasajero);
            std::cout << "Nuevo codigo de vuelo (actual: " << r.codigoVuelo << "): ";
            std::getline(std::cin, r.codigoVuelo);
            std::cout << "Reserva editada en memoria. (Guarde para confirmar).\n";
            encontrada = true;
            break;
        }
    }
    if (!encontrada) {
        std::cout << "Reserva no encontrada o inactiva.\n";
    }
}

void eliminarReserva(std::vector<Reserva>& lista) { // Función modificada
    int num;
    std::cout << "--- Eliminar Reserva (Logico) ---\n";
    std::cout << "Ingrese numero de reserva a eliminar: ";
    while (!(std::cin >> num)) {
        std::cout << "Entrada invalida. Ingrese un numero: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    bool encontrada = false;
    for (auto &r : lista) {
        if (r.numeroReserva == num && r.activo) {
            r.activo = false;
            std::cout << "Reserva marcada como inactiva en memoria. Guarde para persistir.\n";
            encontrada = true;
            break;
        }
    }
    if (!encontrada) {
        std::cout << "Reserva no encontrada o ya inactiva.\n";
    }
}

void consultarReservas(const std::vector<Reserva>& lista) { // Función modificada
    std::cout << "\n--- Lista de Reservas Activas ---\n";
    if (lista.empty()) {
        std::cout << "No hay reservas registradas.\n";
        return;
    }
    for (const auto &r : lista) {
        if (r.activo) {
            std::cout << "Numero: " << r.numeroReserva
                 << " | Fecha: " << r.fechaReserva
                 << " | Pago: " << (r.estadoPago ? "Pagado" : "No pagado")
                 << " | DUI Pasajero: " << r.duiPasajero
                 << " | Codigo Vuelo: " << r.codigoVuelo << "\n";
        }
    }
    std::cout << "----------------------------------\n";
}