#include "../include/Rutas.h"
#include <iostream> 
#include <limits> 


void agregarRuta(std::vector<Ruta>& lista) { // Funcion modificada
    Ruta nueva;
    std::cout << "--- Agregar Nueva Ruta ---\n";
    std::cout << "Codigo de ruta: ";
    while (!(std::cin >> nueva.codigo)) {
        std::cout << "Entrada invalida. Ingrese un numero: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Origen: ";
    std::getline(std::cin, nueva.origen);

    std::cout << "Destino: ";
    std::getline(std::cin, nueva.destino);

    std::cout << "Duracion (horas): ";
    while (!(std::cin >> nueva.duracion)) {
        std::cout << "Entrada invalida. Ingrese un numero: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Tarifa base: ";
    while (!(std::cin >> nueva.tarifaBase)) {
        std::cout << "Entrada invalida. Ingrese un numero: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    nueva.activa = true;

    lista.push_back(nueva);
    std::cout << "Ruta agregada a la memoria.\n";
}

void mostrarRutas(const std::vector<Ruta>& lista) { 
    std::cout << "\n--- Lista de Rutas Activas ---\n";
    if (lista.empty()) {
        std::cout << "No hay rutas registradas.\n";
        return;
    }
    for (const Ruta& r : lista) {
        if (r.activa) {
            std::cout << "Codigo: " << r.codigo
                      << " | Origen: " << r.origen
                      << " | Destino: " << r.destino
                      << " | Duración: " << r.duracion << "h"
                      << " | Tarifa Base: $" << r.tarifaBase << "\n";
        }
    }
    std::cout << "----------------------------------\n";
}

void editarRuta(std::vector<Ruta>& lista) {
    int codigo;
    std::cout << "--- Editar Ruta ---\n";
    std::cout << "Código de la ruta a editar: ";
    while (!(std::cin >> codigo)) {
        std::cout << "Entrada invalida. Ingrese un numero: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    bool encontrada = false;
    for (Ruta& r : lista) {
        if (r.codigo == codigo && r.activa) {
            std::cout << "Ruta encontrada. Ingrese nuevos datos:\n";
            std::cout << "Nuevo origen (actual: " << r.origen << "): ";
            std::getline(std::cin, r.origen);

            std::cout << "Nuevo destino (actual: " << r.destino << "): ";
            std::getline(std::cin, r.destino);

            std::cout << "Nueva duración (actual: " << r.duracion << "): ";
            while (!(std::cin >> r.duracion)) {
                std::cout << "Entrada invalida. Ingrese un numero: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cout << "Nueva tarifa base (actual: " << r.tarifaBase << "): ";
            while (!(std::cin >> r.tarifaBase)) {
                std::cout << "Entrada invalida. Ingrese un numero: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            encontrada = true;
            std::cout << "Ruta editada en memoria. Guarde para persistir.\n";
            break;
        }
    }

    if (!encontrada) {
        std::cout << "Ruta no encontrada o inactiva.\n";
    }
}

void eliminarRutaLogicamente(std::vector<Ruta>& lista) { 
    int codigo;
    std::cout << "--- Eliminar Ruta (Logico) ---\n";
    std::cout << "Codigo de la ruta a eliminar: ";
    while (!(std::cin >> codigo)) {
        std::cout << "Entrada invalida. Ingrese un numero: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    bool encontrada = false;
    for (Ruta& r : lista) {
        if (r.codigo == codigo && r.activa) {
            r.activa = false;
            encontrada = true;
            std::cout << "Ruta marcada como inactiva en memoria. )Guarde para confirmar).\n";
            break;
        }
    }

    if (!encontrada) {
        std::cout << "Ruta no encontrada o ya estaba inactiva.\n";
    }
}