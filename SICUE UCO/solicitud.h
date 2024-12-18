// Archivo: Solicitud.h
#ifndef SOLICITUD_H
#define SOLICITUD_H

#include <string>
#include "Usuario.h"
#include "PlanDeConvalidacion.h"

class Solicitud {
private:
    Usuario* usuario;
    PlanDeConvalidacion* plan;
    std::string estado;

public:
    Solicitud(Usuario* usuario, PlanDeConvalidacion* plan, const std::string& estado){

    }
    Usuario* obtenerUsuario() const { return usuario; }
    PlanDeConvalidacion* obtenerPlan() const { return plan; }
    std::string obtenerEstado() const { return estado; }
};

#endif