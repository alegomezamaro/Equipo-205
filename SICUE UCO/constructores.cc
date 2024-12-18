// Archivo: Constructores.cc
//Constructor de todas las clases 
#include "Universidad.h"
#include "Asignatura.h"
#include "PlanDeConvalidacion.h"
#include "Usuario.h"

// Universidad
Universidad::Universidad(const std::string& id, const std::string& facultad, const std::string& direccion)
    : id(id), facultad(facultad), direccion(direccion) {}

// Asignatura
Asignatura::Asignatura(const std::string& nombre, int codigo, int creditos)
    : nombre(nombre), codigo(codigo), creditos(creditos) {}

// PlanDeConvalidacion
PlanDeConvalidacion::PlanDeConvalidacion(const std::string& duracion, const Universidad& universidad)
    : duracion(duracion), universidad(universidad) {}

// PlanProfesores
PlanProfesores::PlanProfesores(const std::string& duracion, const Universidad& universidad, const std::string& departamento)
    : PlanDeConvalidacion(duracion, universidad), departamento(departamento) {}

// PlanEstudiantes
PlanEstudiantes::PlanEstudiantes(const std::string& duracion, const Universidad& universidad, const std::vector<Asignatura>& asignaturas)
    : PlanDeConvalidacion(duracion, universidad), asignaturas(asignaturas) {}

// Usuario
Usuario::Usuario(const std::string& nombre, const std::string& dni, const std::string& email)
    : nombre(nombre), dni(dni), email(email) {}

// Administrador
Administrador::Administrador(const std::string& nombre, const std::string& dni, const std::string& email)
    : Usuario(nombre, dni, email) {}

// Estudiante
Estudiante::Estudiante(const std::string& nombre, const std::string& dni, const std::string& email, const std::string& carrera)
    : Usuario(nombre, dni, email), carrera(carrera) {}

// Profesor
Profesor::Profesor(const std::string& nombre, const std::string& dni, const std::string& email, const std::string& departamento)
    : Usuario(nombre, dni, email), departamento(departamento) {}
