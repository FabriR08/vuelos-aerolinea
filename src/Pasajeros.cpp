#include "../include/Pasajeros.h" // Cambiado de Pasajero.h a Pasajeros.h
#include <iostream>
#include <limits> // Para std::numeric_limits

void agregarPasajero(std::vector<Pasajero>& lista) { // Función modificada para aceptar lista
    Pasajero p;
    std::cout << "--- Agregar Nuevo Pasajero ---\n";
    std::cout << "ID: ";
    while (!(std::cin >> p.id)) {
        std::cout << "Entrada invalida. Por favor, ingrese un numero para el ID: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar buffer

    std::cout << "Nombre: ";
    std::getline(std::cin, p.nombre);
    std::cout << "DUI: ";
    std::getline(std::cin, p.dui);
    std::cout << "Nacionalidad: ";
    std::getline(std::cin, p.nacionalidad);
    std::cout << "Vuelo reservado: ";
    std::getline(std::cin, p.vueloReservado);
    std::cout << "Asiento: ";
    std::getline(std::cin, p.asiento);
    p.checkIn = false; // Por defecto no ha hecho check-in
    p.activo = true;   // Por defecto está activo

    lista.push_back(p);
    std::cout << "Pasajero agregado con éxito a la memoria. Guarde para persistir.\n";
}

void editarPasajero(std::vector<Pasajero>& lista) { // Función modificada
    int idBuscar;
    std::cout << "--- Editar Pasajero ---\n";
    std::cout << "Ingrese el ID del pasajero a editar: ";
    while (!(std::cin >> idBuscar)) {
        std::cout << "Entrada invalida. Por favor, ingrese un numero para el ID: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    bool encontrado = false;
    for (Pasajero& p : lista) {
        if (p.id == idBuscar && p.activo) {
            std::cout << "Pasajero encontrado. Ingrese nuevos datos:\n";
            std::cout << "Nuevo Nombre (actual: " << p.nombre << "): ";
            std::getline(std::cin, p.nombre);
            std::cout << "Nuevo DUI (actual: " << p.dui << "): ";
            std::getline(std::cin, p.dui);
            std::cout << "Nueva Nacionalidad (actual: " << p.nacionalidad << "): ";
            std::getline(std::cin, p.nacionalidad);
            std::cout << "Nuevo Vuelo Reservado (actual: " << p.vueloReservado << "): ";
            std::getline(std::cin, p.vueloReservado);
            std::cout << "Nuevo Asiento (actual: " << p.asiento << "): ";
            std::getline(std::cin, p.asiento);
            char res;
            std::cout << "¿Ha realizado Check-in? (s/n, actual: " << (p.checkIn ? "Si" : "No") << "): ";
            std::cin >> res;
            p.checkIn = (res == 's' || res == 'S');
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar buffer después de cin >> char
            std::cout << "Pasajero actualizado en memoria. Guarde para persistir.\n";
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        std::cout << "Pasajero con ID " << idBuscar << " no encontrado o inactivo.\n";
    }
}

void eliminarPasajero(std::vector<Pasajero>& lista) { // Función modificada
    int idBuscar;
    std::cout << "--- Eliminar Pasajero (Logico) ---\n";
    std::cout << "Ingrese el ID del pasajero a eliminar: ";
    while (!(std::cin >> idBuscar)) {
        std::cout << "Entrada invalida. Por favor, ingrese un numero para el ID: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    bool encontrado = false;
    for (Pasajero& p : lista) {
        if (p.id == idBuscar && p.activo) {
            p.activo = false; // Marcar como inactivo
            std::cout << "Pasajero con ID " << idBuscar << " marcado como inactivo en memoria. Guarde para persistir.\n";
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        std::cout << "Pasajero con ID " << idBuscar << " no encontrado o ya estaba inactivo.\n";
    }
}

void consultarPasajero(const std::vector<Pasajero>& lista) { // Función modificada
    int idBuscar;
    std::cout << "--- Consultar Pasajero por ID ---\n";
    std::cout << "Ingrese el ID del pasajero a consultar: ";
    while (!(std::cin >> idBuscar)) {
        std::cout << "Entrada invalida. Por favor, ingrese un numero para el ID: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    bool encontrado = false;
    for (const Pasajero& p : lista) {
        if (p.id == idBuscar && p.activo) {
            std::cout << "\n--- Detalle del Pasajero ---\n";
            std::cout << "ID: " << p.id << "\n";
            std::cout << "Nombre: " << p.nombre << "\n";
            std::cout << "DUI: " << p.dui << "\n";
            std::cout << "Nacionalidad: " << p.nacionalidad << "\n";
            std::cout << "Vuelo Reservado: " << p.vueloReservado << "\n";
            std::cout << "Asiento: " << p.asiento << "\n";
            std::cout << "Check-in: " << (p.checkIn ? "Realizado" : "Pendiente") << "\n";
            std::cout << "Estado: " << (p.activo ? "Activo" : "Inactivo") << "\n";
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        std::cout << "Pasajero con ID " << idBuscar << " no encontrado o inactivo.\n";
    }
}

void listarPasajeros(const std::vector<Pasajero>& lista) { // Función modificada
    std::cout << "\n--- Lista de Pasajeros Activos ---\n";
    if (lista.empty()) {
        std::cout << "No hay pasajeros registrados.\n";
        return;
    }
    for (const Pasajero& p : lista) {
        if (p.activo) {
            std::cout << "ID: " << p.id
                      << " | Nombre: " << p.nombre
                      << " | DUI: " << p.dui
                      << " | Vuelo: " << p.vueloReservado
                      << " | Asiento: " << p.asiento
                      << " | Check-in: " << (p.checkIn ? "Si" : "No") << "\n";
        }
    }
    std::cout << "----------------------------------\n";
}