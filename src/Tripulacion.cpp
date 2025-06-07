#include "../include/Tripulacion.h" 
#include <iostream>
#include <limits> 


void agregarTripulante(std::vector<Tripulante>& lista) { 
    Tripulante t;
    std::cout << "--- Agregar Nuevo Tripulante ---\n";
    std::cout << "Ingrese codigo del tripulante: ";
    std::getline(std::cin >> std::ws, t.codigo);
    std::cout << "Ingrese nombre: ";
    std::getline(std::cin, t.nombre);
    std::cout << "Ingrese rol (piloto, copiloto, azafata, etc.): ";
    std::getline(std::cin, t.rol);
    t.vuelosAsignados.clear(); 
    t.activo = true;
    lista.push_back(t);
    std::cout << "Tripulante agregado a la memoria. Guarde para persistir.\n";
}

void editarTripulante(std::vector<Tripulante>& lista) { 
    std::string codigoBuscar;
    std::cout << "--- Editar Tripulante ---\n";
    std::cout << "Ingrese codigo del tripulante a editar: ";
    std::getline(std::cin >> std::ws, codigoBuscar);

    bool encontrado = false;
    for (auto &t : lista) {
        if (t.codigo == codigoBuscar && t.activo) {
            std::cout << "Tripulante encontrado. Ingrese nuevos datos:\n";
            std::cout << "Nuevo nombre (actual: " << t.nombre << "): ";
            std::getline(std::cin, t.nombre);
            std::cout << "Nuevo rol (actual: " << t.rol << "): ";
            std::getline(std::cin, t.rol);
            // nose si podrias agregar logica para editar vuelos asignados si es necesario
            std::cout << "Tripulante actualizado en memoria. (Guarde para confirmar).\n";
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        std::cout << "Tripulante no encontrado o inactivo.\n";
    }
}

void eliminarTripulante(std::vector<Tripulante>& lista) { 
    std::string codigoBuscar;
    std::cout << "--- Eliminar Tripulante  ---\n";
    std::cout << "Ingrese codigo del tripulante a eliminar: ";
    std::getline(std::cin >> std::ws, codigoBuscar);

    bool encontrado = false;
    for (auto &t : lista) {
        if (t.codigo == codigoBuscar && t.activo) {
            t.activo = false;
            std::cout << "Tripulante marcado como inactivo en memoria. Guarde para persistir.\n";
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        std::cout << "Tripulante no encontrado o ya inactivo.\n";
    }
}

void consultarTripulacion(const std::vector<Tripulante>& lista) { 
    std::cout << "\n--- Lista de Tripulantes Activos ---\n";
    if (lista.empty()) {
        std::cout << "No hay tripulantes registrados.\n";
        return;
    }
    for (const auto &t : lista) {
        if (t.activo) {
            std::cout << "Codigo: " << t.codigo
                      << " | Nombre: " << t.nombre
                      << " | Rol: " << t.rol
                      << " | Vuelos asignados: ";
            if (t.vuelosAsignados.empty()) {
                std::cout << "Ninguno";
            } else {
                for (size_t i = 0; i < t.vuelosAsignados.size(); ++i) {
                    std::cout << t.vuelosAsignados[i];
                    if (i < t.vuelosAsignados.size() - 1) {
                        std::cout << ", ";
                    }
                }
            }
            std::cout << "\n";
        }
    }
    std::cout << "----------------------------------\n";
}