#ifndef PASAJEROS_H
#define PASAJEROS_H

#include <string>
#include <vector> // Necesario para la declaración de std::vector

// Estructura del pasajero
struct Pasajero { // La estructura se llama Pasajero (singular)
    int id;
    std::string nombre;
    std::string dui;
    std::string nacionalidad;
    std::string vueloReservado;
    std::string asiento;
    bool checkIn;  // true si ya hizo check-in
    bool activo;   // true si está activo (no eliminado)
};

// Declaración de funciones (ahora aceptan el vector por referencia)
void agregarPasajero(std::vector<Pasajero>& lista);
void editarPasajero(std::vector<Pasajero>& lista);
void eliminarPasajero(std::vector<Pasajero>& lista);
void consultarPasajero(const std::vector<Pasajero>& lista);
void listarPasajeros(const std::vector<Pasajero>& lista);

#endif