#ifndef RESERVAS_H
#define RESERVAS_H

#include <string>
#include <vector>

struct Reserva { 
    int numeroReserva;
    std::string fechaReserva;
    bool estadoPago;
    std::string duiPasajero;
    std::string codigoVuelo;
    bool activo; 
};

void agregarReserva(std::vector<Reserva>& lista);
void editarReserva(std::vector<Reserva>& lista);
void eliminarReserva(std::vector<Reserva>& lista);
void consultarReservas(const std::vector<Reserva>& lista);

#endif