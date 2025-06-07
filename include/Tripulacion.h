#ifndef TRIPULACION_H
#define TRIPULACION_H

#include <string>
#include <vector>

struct Tripulante { // La estructura se llama Tripulante (singular)
    std::string codigo;
    std::string nombre;
    std::string rol; // piloto, copiloto, azafata, etc.
    std::vector<std::string> vuelosAsignados; // Esto se guardará como una cadena separada por comas
    bool activo = true;
};

void agregarTripulante(std::vector<Tripulante>& lista);
void editarTripulante(std::vector<Tripulante>& lista);
void eliminarTripulante(std::vector<Tripulante>& lista);
void consultarTripulacion(const std::vector<Tripulante>& lista);

#endif