// Archivo: Usuario.h
#ifndef USUARIO_H 
#define USUARIO_H

#include <string>

class Usuario {
private:
    std::string nombre;
    std::string dni;
    std::string email;

public:
    Usuario(const std::string& nombre, const std::string& dni, const std::string& email);
    std::string obtenerNombre() const { return nombre; }
    std::string obtenerDni() const { return dni; }
    std::string obtenerEmail() const { return email; }
};

class Administrador : public Usuario {
public:
    Administrador(const std::string& nombre, const std::string& dni, const std::string& email);
    void verHistorial() const;
    void aceptarSolicitud();
    void denegarSolicitud();
    void crearPlanConvalidacion();
};

class Estudiante : public Usuario {
private:
    std::string carrera;

public:
    Estudiante(const std::string& nombre, const std::string& dni, const std::string& email, const std::string& carrera);
    std::string obtenerCarrera() const { return carrera; }
};

class Profesor : public Usuario {
private:
    std::string departamento;

public:
    Profesor(const std::string& nombre, const std::string& dni, const std::string& email, const std::string& departamento);
    std::string obtenerDepartamento() const { return departamento; }
};

#endif
