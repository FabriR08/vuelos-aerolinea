#include "../include/FileManager.h"
#include "../include/Pasajeros.h"
#include "../include/Reservas.h"
#include "../include/Rutas.h"
#include "../include/Tripulacion.h"
#include "../include/Vuelos.h"

std::vector<std::string> FileManager::splitString(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

template<typename T>
bool FileManager::guardarDatos(const std::string& nombreArchivo, const std::vector<T>& datos) {
    std::ofstream archivo("data/" + nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << " para escritura.\n";
        return false;
    }
    for (const T& item : datos) {
    
    }
    archivo.close();
    return true;
}

template<typename T>
std::vector<T> FileManager::cargarDatos(const std::string& nombreArchivo) {
    std::vector<T> datos;
    std::ifstream archivo("data/" + nombreArchivo);
    if (!archivo.is_open()) {
        return datos; 
    }
    std::string linea;
    while (std::getline(archivo, linea)) {
    }
    archivo.close();
    return datos;
}




std::string FileManager::serializarPasajero(const Pasajero& p) {
    return std::to_string(p.id) + "|" +
           p.nombre + "|" +
           p.dui + "|" +
           p.nacionalidad + "|" +
           p.vueloReservado + "|" +
           p.asiento + "|" +
           std::to_string(p.checkIn) + "|" +
           std::to_string(p.activo);
}

Pasajero FileManager::deserializarPasajero(const std::string& linea) {
    std::vector<std::string> tokens = splitString(linea, '|');
    Pasajero p;
    if (tokens.size() == 8) {
        p.id = std::stoi(tokens[0]);
        p.nombre = tokens[1];
        p.dui = tokens[2];
        p.nacionalidad = tokens[3];
        p.vueloReservado = tokens[4];
        p.asiento = tokens[5];
        p.checkIn = (tokens[6] == "1");
        p.activo = (tokens[7] == "1");
    }
    return p;
}

bool FileManager::guardarPasajeros(const std::vector<Pasajero>& pasajeros) {
    std::ofstream archivo("data/pasajeros.txt");
    if (!archivo.is_open()) return false;
    for (const Pasajero& p : pasajeros) {
        archivo << serializarPasajero(p) << "\n";
    }
    archivo.close();
    return true;
}

std::vector<Pasajero> FileManager::cargarPasajeros() {
    std::vector<Pasajero> pasajeros;
    std::ifstream archivo("data/pasajeros.txt");
    if (!archivo.is_open()) return pasajeros;
    std::string linea;
    while (std::getline(archivo, linea)) {
        pasajeros.push_back(deserializarPasajero(linea));
    }
    archivo.close();
    return pasajeros;
}

// Reserva
std::string FileManager::serializarReserva(const Reserva& r) {
    return std::to_string(r.numeroReserva) + "|" +
           r.fechaReserva + "|" +
           std::to_string(r.estadoPago) + "|" +
           r.duiPasajero + "|" +
           r.codigoVuelo + "|" +
           std::to_string(r.activo);
}

Reserva FileManager::deserializarReserva(const std::string& linea) {
    std::vector<std::string> tokens = splitString(linea, '|');
    Reserva r;
    if (tokens.size() == 6) {
        r.numeroReserva = std::stoi(tokens[0]);
        r.fechaReserva = tokens[1];
        r.estadoPago = (tokens[2] == "1");
        r.duiPasajero = tokens[3];
        r.codigoVuelo = tokens[4];
        r.activo = (tokens[5] == "1");
    }
    return r;
}

bool FileManager::guardarReservas(const std::vector<Reserva>& reservas) {
    std::ofstream archivo("data/reservas.txt");
    if (!archivo.is_open()) return false;
    for (const Reserva& r : reservas) {
        archivo << serializarReserva(r) << "\n";
    }
    archivo.close();
    return true;
}

std::vector<Reserva> FileManager::cargarReservas() {
    std::vector<Reserva> reservas;
    std::ifstream archivo("data/reservas.txt");
    if (!archivo.is_open()) return reservas;
    std::string linea;
    while (std::getline(archivo, linea)) {
        reservas.push_back(deserializarReserva(linea));
    }
    archivo.close();
    return reservas;
}

// Ruta
std::string FileManager::serializarRuta(const Ruta& r) {
    return std::to_string(r.codigo) + "|" +
           r.origen + "|" +
           r.destino + "|" +
           std::to_string(r.duracion) + "|" +
           std::to_string(r.tarifaBase) + "|" +
           std::to_string(r.activa);
}

Ruta FileManager::deserializarRuta(const std::string& linea) {
    std::vector<std::string> tokens = splitString(linea, '|');
    Ruta r;
    if (tokens.size() == 6) {
        r.codigo = std::stoi(tokens[0]);
        r.origen = tokens[1];
        r.destino = tokens[2];
        r.duracion = std::stof(tokens[3]); // std::stof para float
        r.tarifaBase = std::stof(tokens[4]);
        r.activa = (tokens[5] == "1");
    }
    return r;
}

bool FileManager::guardarRutas(const std::vector<Ruta>& rutas) {
    std::ofstream archivo("data/rutas.txt");
    if (!archivo.is_open()) return false;
    for (const Ruta& r : rutas) {
        archivo << serializarRuta(r) << "\n";
    }
    archivo.close();
    return true;
}

std::vector<Ruta> FileManager::cargarRutas() {
    std::vector<Ruta> rutas;
    std::ifstream archivo("data/rutas.txt");
    if (!archivo.is_open()) return rutas;
    std::string linea;
    while (std::getline(archivo, linea)) {
        rutas.push_back(deserializarRuta(linea));
    }
    archivo.close();
    return rutas;
}

// Tripulante
std::string FileManager::serializarTripulante(const Tripulante& t) {
    std::string vuelosStr;
    for (size_t i = 0; i < t.vuelosAsignados.size(); ++i) {
        vuelosStr += t.vuelosAsignados[i];
        if (i < t.vuelosAsignados.size() - 1) {
            vuelosStr += ","; 
        }
    }
    return t.codigo + "|" +
           t.nombre + "|" +
           t.rol + "|" +
           vuelosStr + "|" +
           std::to_string(t.activo);
}

Tripulante FileManager::deserializarTripulante(const std::string& linea) {
    std::vector<std::string> tokens = splitString(linea, '|');
    Tripulante t;
    if (tokens.size() == 5) {
        t.codigo = tokens[0];
        t.nombre = tokens[1];
        t.rol = tokens[2];

        std::string vuelosStr = tokens[3];
        t.vuelosAsignados.clear();
        if (!vuelosStr.empty()) {
            t.vuelosAsignados = splitString(vuelosStr, ',');
        }
        t.activo = (tokens[4] == "1");
    }
    return t;
}

bool FileManager::guardarTripulacion(const std::vector<Tripulante>& tripulacion) {
    std::ofstream archivo("data/tripulacion.txt");
    if (!archivo.is_open()) return false;
    for (const Tripulante& t : tripulacion) {
        archivo << serializarTripulante(t) << "\n";
    }
    archivo.close();
    return true;
}

std::vector<Tripulante> FileManager::cargarTripulacion() {
    std::vector<Tripulante> tripulacion;
    std::ifstream archivo("data/tripulacion.txt");
    if (!archivo.is_open()) return tripulacion;
    std::string linea;
    while (std::getline(archivo, linea)) {
        tripulacion.push_back(deserializarTripulante(linea));
    }
    archivo.close();
    return tripulacion;
}

// Vuelo
std::string FileManager::serializarVuelo(const Vuelo& v) {
    return v.codigo + "|" +
           v.origen + "|" +
           v.destino + "|" +
           v.horaSalida + "|" +
           v.horaLlegada + "|" +
           std::to_string(v.capacidad) + "|" +
           v.tipoAvion + "|" +
           std::to_string(v.activo);
}

Vuelo FileManager::deserializarVuelo(const std::string& linea) {
    std::vector<std::string> tokens = splitString(linea, '|');
    Vuelo v;
    if (tokens.size() == 8) {
        v.codigo = tokens[0];
        v.origen = tokens[1];
        v.destino = tokens[2];
        v.horaSalida = tokens[3];
        v.horaLlegada = tokens[4];
        v.capacidad = std::stoi(tokens[5]);
        v.tipoAvion = tokens[6];
        v.activo = (tokens[7] == "1");
    }
    return v;
}

bool FileManager::guardarVuelos(const std::vector<Vuelo>& vuelos) {
    std::ofstream archivo("data/vuelos.txt");
    if (!archivo.is_open()) return false;
    for (const Vuelo& v : vuelos) {
        archivo << serializarVuelo(v) << "\n";
    }
    archivo.close();
    return true;
}

std::vector<Vuelo> FileManager::cargarVuelos() {
    std::vector<Vuelo> vuelos;
    std::ifstream archivo("data/vuelos.txt");
    if (!archivo.is_open()) return vuelos;
    std::string linea;
    while (std::getline(archivo, linea)) {
        vuelos.push_back(deserializarVuelo(linea));
    }
    archivo.close();
    return vuelos;
}