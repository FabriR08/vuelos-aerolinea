#ifndef TRIPULACION_H
#define TRIPULACION_H

#include <string>
#include <vector>

struct Tripulante { 
    std::string codigo;
    std::string nombre;
    std::string rol; 
    std::vector<std::string> vuelosAsignados; 
    bool activo = true;
};

void agregarTripulante(std::vector<Tripulante>& lista);
void editarTripulante(std::vector<Tripulante>& lista);
void eliminarTripulante(std::vector<Tripulante>& lista);
void consultarTripulacion(const std::vector<Tripulante>& lista);

#endif