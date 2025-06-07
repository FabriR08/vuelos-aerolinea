#ifndef VUELOS_H
#define VUELOS_H

#include <string>
#include <vector>

struct Vuelo { // La estructura se llama Vuelo (singular)
    std::string codigo;
    std::string origen;
    std::string destino;
    std::string horaSalida;
    std::string horaLlegada;
    int capacidad;
    std::string tipoAvion;
    bool activo = true;
};

void agregarVuelo(std::vector<Vuelo>& lista);
void editarVuelo(std::vector<Vuelo>& lista);
void eliminarVuelo(std::vector<Vuelo>& lista);
void consultarVuelos(const std::vector<Vuelo>& lista);

#endif