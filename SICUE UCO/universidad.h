// Archivo: Universidad.h
#ifndef UNIVERSIDAD_H
#define UNIVERSIDAD_H

#include <string>

class Universidad {
private:
    std::string id;
    std::string facultad;
    std::string direccion;

public:
    Universidad(const std::string& id, const std::string& facultad, const std::string& direccion);
    std::string obtenerId() const { return id; }
    std::string obtenerFacultad() const { return facultad; }
    std::string obtenerDireccion() const { return direccion; }
};

#endif