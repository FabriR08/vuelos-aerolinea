#ifndef PASAJEROS_H
#define PASAJEROS_H

#include <string>
#include <vector> 

struct Pasajero { 
    int id;
    std::string nombre;
    std::string dui;
    std::string nacionalidad;
    std::string vueloReservado;
    std::string asiento;
    bool checkIn; 
    bool activo;   
};

void agregarPasajero(std::vector<Pasajero>& lista);
void editarPasajero(std::vector<Pasajero>& lista);
void eliminarPasajero(std::vector<Pasajero>& lista);
void consultarPasajero(const std::vector<Pasajero>& lista);
void listarPasajeros(const std::vector<Pasajero>& lista);

#endif