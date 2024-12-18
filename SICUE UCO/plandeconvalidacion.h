// Archivo: PlanDeConvalidacion.h
// Archivo: PlanDeConvalidacion.h
#ifndef PLAN_DE_CONVALIDACION_H
#define PLAN_DE_CONVALIDACION_H

#include <string>
#include "Universidad.h"
#include "Asignatura.h"
#include <vector>

class PlanDeConvalidacion {
protected:
    std::string duracion;
    Universidad universidad;

public:
    PlanDeConvalidacion(const std::string& duracion, const Universidad& universidad);
    std::string obtenerDuracion() const { return duracion; }
    Universidad obtenerUniversidad() const { return universidad; }
};

class PlanProfesores : public PlanDeConvalidacion {
private:
    std::string departamento;

public:
    PlanProfesores(const std::string& duracion, const Universidad& universidad, const std::string& departamento);
    std::string obtenerDepartamento() const { return departamento; }
};

class PlanEstudiantes : public PlanDeConvalidacion {
private:
    std::vector<Asignatura> asignaturas;

public:
    PlanEstudiantes(const std::string& duracion, const Universidad& universidad, const std::vector<Asignatura>& asignaturas);
    std::vector<Asignatura> obtenerAsignaturas() const { return asignaturas; }
};

#endif