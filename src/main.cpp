#include <iostream>
#include <vector>
#include <limits> 

#include "../include/Pasajeros.h" 
#include "../include/Reservas.h"   
#include "../include/Rutas.h"      
#include "../include/Tripulacion.h" 
#include "../include/Vuelos.h"     
#include "../include/FileManager.h" 

std::vector<Pasajero> globalPasajeros;
std::vector<Reserva> globalReservas;
std::vector<Ruta> globalRutas;
std::vector<Tripulante> globalTripulacion;
std::vector<Vuelo> globalVuelos;

// Prototipos de funciones del menu
void mostrarMenuPrincipal();
void gestionarPasajeros();
void gestionarReservas();
void gestionarRutas();
void gestionarTripulacion();
void gestionarVuelos();
void limpiarConsola();

int main() {
    // 1. Cargar todos los datos al inicio del programa
    globalPasajeros = FileManager::cargarPasajeros();
    globalReservas = FileManager::cargarReservas();
    globalRutas = FileManager::cargarRutas();
    globalTripulacion = FileManager::cargarTripulacion();
    globalVuelos = FileManager::cargarVuelos();

    int opcion;
    do {
        mostrarMenuPrincipal();
        std::cout << "Ingrese su opcion: ";
        while (!(std::cin >> opcion)) {
            std::cout << "Entrada invalida. Ingrese un numero: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        limpiarConsola();

        switch (opcion) {
            case 1: gestionarVuelos(); break;
            case 2: gestionarPasajeros(); break;
            case 3: gestionarReservas(); break;
            case 4: gestionarTripulacion(); break;
            case 5: gestionarRutas(); break;
            case 6:
                std::cout << "Guardando todos los cambios antes de salir...\n";
                FileManager::guardarPasajeros(globalPasajeros);
                FileManager::guardarReservas(globalReservas);
                FileManager::guardarRutas(globalRutas);
                FileManager::guardarTripulacion(globalTripulacion);
                FileManager::guardarVuelos(globalVuelos);
                std::cout << "Saliendo del sistema. ¡Gracias!\n";
                break;
            default:
                std::cout << "Opcion no valida. Intente de nuevo.\n";
                break;
        }
        std::cout << "\nPresione Enter para continuar...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        limpiarConsola();

    } while (opcion != 6);

    return 0;
}

void mostrarMenuPrincipal() {
    std::cout << "\n--- Sistema de Gestion de Aerolinea ---\n";
    std::cout << "1. Gestionar Vuelos\n";
    std::cout << "2. Gestionar Pasajeros\n";
    std::cout << "3. Gestionar Reservas\n";
    std::cout << "4. Gestionar Tripulacion\n";
    std::cout << "5. Gestionar Rutas\n";
    std::cout << "6. Salir (Guardar y Salir)\n";
    std::cout << "--------------------------------------\n";
}

void gestionarVuelos() {
    int opcion;
    do {
        std::cout << "\n--- Gestion de Vuelos ---\n";
        std::cout << "1. Agregar Vuelo\n";
        std::cout << "2. Editar Vuelo\n";
        std::cout << "3. Eliminar Vuelo (Logico)\n";
        std::cout << "4. Consultar/Listar Vuelos\n";
        std::cout << "5. Volver al Menu Principal\n";
        std::cout << "-------------------------\n";
        std::cout << "Ingrese su opcion: ";
        while (!(std::cin >> opcion)) {
            std::cout << "Entrada invalida. Ingrese un numero: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        limpiarConsola();

        switch (opcion) {
            case 1: agregarVuelo(globalVuelos); break;
            case 2: editarVuelo(globalVuelos); break;
            case 3: eliminarVuelo(globalVuelos); break;
            case 4: consultarVuelos(globalVuelos); break;
            case 5: std::cout << "Volviendo al menu principal...\n"; break;
            default: std::cout << "Opcion no valida. Intente de nuevo.\n"; break;
        }
        if (opcion != 5) {
            std::cout << "\nPresione Enter para continuar...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            limpiarConsola();
        }
    } while (opcion != 5);
}

void gestionarPasajeros() {
    int opcion;
    do {
        std::cout << "\n--- Gestion de Pasajeros ---\n";
        std::cout << "1. Agregar Pasajero\n";
        std::cout << "2. Editar Pasajero\n";
        std::cout << "3. Eliminar Pasajero (Logico)\n";
        std::cout << "4. Consultar Pasajero por ID\n";
        std::cout << "5. Listar Pasajeros\n";
        std::cout << "6. Volver al Menu Principal\n";
        std::cout << "---------------------------\n";
        std::cout << "Ingrese su opcion: ";
        while (!(std::cin >> opcion)) {
            std::cout << "Entrada invalida. Ingrese un numero: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        limpiarConsola();

        switch (opcion) {
            case 1: agregarPasajero(globalPasajeros); break;
            case 2: editarPasajero(globalPasajeros); break;
            case 3: eliminarPasajero(globalPasajeros); break;
            case 4: consultarPasajero(globalPasajeros); break;
            case 5: listarPasajeros(globalPasajeros); break;
            case 6: std::cout << "Volviendo al menu principal...\n"; break;
            default: std::cout << "Opcion no valida. Intente de nuevo.\n"; break;
        }
        if (opcion != 6) {
            std::cout << "\nPresione Enter para continuar...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            limpiarConsola();
        }
    } while (opcion != 6);
}

void gestionarReservas() {
    int opcion;
    do {
        std::cout << "\n--- Gestion de Reservas ---\n";
        std::cout << "1. Agregar Reserva\n";
        std::cout << "2. Editar Reserva\n";
        std::cout << "3. Eliminar Reserva (Logico)\n";
        std::cout << "4. Consultar/Listar Reservas\n";
        std::cout << "5. Volver al Menu Principal\n";
        std::cout << "---------------------------\n";
        std::cout << "Ingrese su opcion: ";
        while (!(std::cin >> opcion)) {
            std::cout << "Entrada invalida. Ingrese un numero: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        limpiarConsola();

        switch (opcion) {
            case 1: agregarReserva(globalReservas); break;
            case 2: editarReserva(globalReservas); break;
            case 3: eliminarReserva(globalReservas); break;
            case 4: consultarReservas(globalReservas); break;
            case 5: std::cout << "Volviendo al menu principal...\n"; break;
            default: std::cout << "Opcion no valida. Intente de nuevo.\n"; break;
        }
        if (opcion != 5) {
            std::cout << "\nPresione Enter para continuar...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            limpiarConsola();
        }
    } while (opcion != 5);
}

void gestionarRutas() {
    int opcion;
    do {
        std::cout << "\n--- Gestion de Rutas ---\n";
        std::cout << "1. Agregar Ruta\n";
        std::cout << "2. Editar Ruta\n";
        std::cout << "3. Eliminar Ruta (Logico)\n";
        std::cout << "4. Mostrar Rutas\n";
        std::cout << "5. Volver al Menu Principal\n";
        std::cout << "------------------------\n";
        std::cout << "Ingrese su opcion: ";
        while (!(std::cin >> opcion)) {
            std::cout << "Entrada invalida. Ingrese un numero: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        limpiarConsola();

        switch (opcion) {
            case 1: agregarRuta(globalRutas); break;
            case 2: editarRuta(globalRutas); break;
            case 3: eliminarRutaLogicamente(globalRutas); break;
            case 4: mostrarRutas(globalRutas); break;
            case 5: std::cout << "Volviendo al menu principal...\n"; break;
            default: std::cout << "Opcion no valida. Intente de nuevo.\n"; break;
        }
        if (opcion != 5) {
            std::cout << "\nPresione Enter para continuar...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            limpiarConsola();
        }
    } while (opcion != 5);
}

void gestionarTripulacion() {
    int opcion;
    do {
        std::cout << "\n--- Gestion de Tripulacion ---\n";
        std::cout << "1. Agregar Tripulante\n";
        std::cout << "2. Editar Tripulante\n";
        std::cout << "3. Eliminar Tripulante (Logico)\n";
        std::cout << "4. Consultar/Listar Tripulacion\n";
        std::cout << "5. Volver al Menu Principal\n";
        std::cout << "-----------------------------\n";
        std::cout << "Ingrese su opcion: ";
        while (!(std::cin >> opcion)) {
            std::cout << "Entrada invalida. Ingrese un numero: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        limpiarConsola();

        switch (opcion) {
            case 1: agregarTripulante(globalTripulacion); break;
            case 2: editarTripulante(globalTripulacion); break;
            case 3: eliminarTripulante(globalTripulacion); break;
            case 4: consultarTripulacion(globalTripulacion); break;
            case 5: std::cout << "Volviendo al menu principal...\n"; break;
            default: std::cout << "Opcion no valida. Intente de nuevo.\n"; break;
        }
        if (opcion != 5) {
            std::cout << "\nPresione Enter para continuar...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            limpiarConsola();
        }
    } while (opcion != 5);
}

void limpiarConsola() {
    #ifdef _WIN32
        system("cls");
    #else
        
        system("clear");
    #endif
}