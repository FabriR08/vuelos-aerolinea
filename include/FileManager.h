#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream> 

struct Pasajero;
struct Reserva;
struct Ruta;
struct Tripulante;
struct Vuelo;

namespace FileManager {

    template<typename T>
    bool guardarDatos(const std::string& nombreArchivo, const std::vector<T>& datos);

    template<typename T>
    std::vector<T> cargarDatos(const std::string& nombreArchivo);


    // Pasajero
    bool guardarPasajeros(const std::vector<Pasajero>& pasajeros);
    std::vector<Pasajero> cargarPasajeros();
    std::string serializarPasajero(const Pasajero& p);
    Pasajero deserializarPasajero(const std::string& linea);

    // Reserva
    bool guardarReservas(const std::vector<Reserva>& reservas);
    std::vector<Reserva> cargarReservas();
    std::string serializarReserva(const Reserva& r);
    Reserva deserializarReserva(const std::string& linea);

    // Ruta
    bool guardarRutas(const std::vector<Ruta>& rutas);
    std::vector<Ruta> cargarRutas();
    std::string serializarRuta(const Ruta& r);
    Ruta deserializarRuta(const std::string& linea);

    // Tripulante
    bool guardarTripulacion(const std::vector<Tripulante>& tripulacion);
    std::vector<Tripulante> cargarTripulacion();
    std::string serializarTripulante(const Tripulante& t);
    Tripulante deserializarTripulante(const std::string& linea);

    // Vuelo
    bool guardarVuelos(const std::vector<Vuelo>& vuelos);
    std::vector<Vuelo> cargarVuelos();
    std::string serializarVuelo(const Vuelo& v);
    Vuelo deserializarVuelo(const std::string& linea);

    // Función auxiliar para dividir una cadena
    std::vector<std::string> splitString(const std::string& s, char delimiter);
}

#endif