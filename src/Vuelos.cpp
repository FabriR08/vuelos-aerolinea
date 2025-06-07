#include "../include/Vuelos.h" 
#include <iostream>
#include <limits> //



void agregarVuelo(std::vector<Vuelo>& lista) { 
    Vuelo v;
    std::cout << "--- Agregar Nuevo Vuelo ---\n";
    std::cout << "Código del vuelo: ";
    std::getline(std::cin >> std::ws, v.codigo); 
    std::cout << "Origen: ";
    std::getline(std::cin, v.origen);
    std::cout << "Destino: ";
    std::getline(std::cin, v.destino);
    std::cout << "Hora de salida (HH:MM): ";
    std::getline(std::cin, v.horaSalida);
    std::cout << "Hora de llegada (HH:MM): ";
    std::getline(std::cin, v.horaLlegada);
    std::cout << "Capacidad: ";
    while (!(std::cin >> v.capacidad)) {
        std::cout << "Entrada invalida. Ingrese un numero: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Tipo de avion: ";
    std::getline(std::cin, v.tipoAvion);
    v.activo = true;

    lista.push_back(v);
    std::cout << "Vuelo agregado a la memoria. Guarde para persistir.\n";
}

void editarVuelo(std::vector<Vuelo>& lista) { 
    std::string codigoBuscar;
    std::cout << "--- Editar Vuelo ---\n";
    std::cout << "Codigo del vuelo a editar: ";
    std::getline(std::cin >> std::ws, codigoBuscar);

    bool encontrado = false;
    for (Vuelo& v : lista) {
        if (v.codigo == codigoBuscar && v.activo) {
            std::cout << "Vuelo encontrado. Ingrese nuevos datos:\n";
            std::cout << "Nuevo origen (actual: " << v.origen << "): ";
            std::getline(std::cin, v.origen);
            std::cout << "Nuevo destino (actual: " << v.destino << "): ";
            std::getline(std::cin, v.destino);
            std::cout << "Nueva hora de salida (actual: " << v.horaSalida << "): ";
            std::getline(std::cin, v.horaSalida);
            std::cout << "Nueva hora de llegada (actual: " << v.horaLlegada << "): ";
            std::getline(std::cin, v.horaLlegada);
            std::cout << "Nueva capacidad (actual: " << v.capacidad << "): ";
            while (!(std::cin >> v.capacidad)) {
                std::cout << "Entrada invalida. Ingrese un numero: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Nuevo tipo de avión (actual: " << v.tipoAvion << "): ";
            std::getline(std::cin, v.tipoAvion);
            std::cout << "Vuelo actualizado en memoria. Guarde para persistir.\n";
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        std::cout << "Vuelo no encontrado o inactivo.\n";
    }
}

void eliminarVuelo(std::vector<Vuelo>& lista) { 
    std::string codigoBuscar;
    std::cout << "--- Eliminar Vuelo ---\n";
    std::cout << "ingrese codigo del para vuelo eliminar: ";
    std::getline(std::cin >> std::ws, codigoBuscar);

    bool encontrado = false;
    for (Vuelo& v : lista) {
        if (v.codigo == codigoBuscar && v.activo) {
            v.activo = false;
            std::cout << "vuelo marcado como inactivo en memoria (Guarde para confirmar)\n";
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        std::cout << "vuelo no encontrado o se encuentra inactivo.\n";
    }
}

void consultarVuelos(const std::vector<Vuelo>& lista) { 
    std::cout << "\n--- Lista de Vuelos Activos ---\n";
    if (lista.empty()) {
        std::cout << "no hay vuelos registrados.\n";
        return;
    }
    for (const Vuelo& v : lista) {
        if (v.activo) {
            std::cout << "Codigo: " << v.codigo
                      << " | Origen: " << v.origen
                      << " | Destino: " << v.destino
                      << " | Salida: " << v.horaSalida
                      << " | Llegada: " << v.horaLlegada
                      << " | Capacidad: " << v.capacidad
                      << " | Tipo: " << v.tipoAvion << "\n";
        }
    }
    std::cout << "----------------------------------\n";
}
