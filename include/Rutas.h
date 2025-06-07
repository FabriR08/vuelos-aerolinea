#ifndef RUTAS_H
#define RUTAS_H

#include <iostream>
#include <vector>
#include <string>

struct Ruta { 
    int codigo;
    std::string origen;
    std::string destino;
    float duracion;
    float tarifaBase;
    bool activa;
};

void agregarRuta(std::vector<Ruta>& lista);
void mostrarRutas(const std::vector<Ruta>& lista);
void editarRuta(std::vector<Ruta>& lista);
void eliminarRutaLogicamente(std::vector<Ruta>& lista);

#endif