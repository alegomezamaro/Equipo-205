// Archivo: Menu.cc
//Menu del programa
//g++ menu.cc constructores.cc -o menu
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "Usuario.h"
#include "Solicitud.h"
#include "PlanDeConvalidacion.h"
#include "Universidad.h"
#include "Asignatura.h"

using namespace std;

void mostrarMenuPrincipal();
void vistaAdministrador();
void vistaAlumno();
void vistaProfesor();
void crearPlanDeConvalidacion();
void imprimirPlanesEstudiantes(string carreraEstudiante);
void imprimirPlanesProfesores();
string huecos(const string& str);
bool verificarDNIEnArchivo(const string& dni, const string& archivoPath);
string obtenerFechaActual();
void crearSolicitudAlumno();
void crearSolicitudProfesor();
void verSolicitudes();
void mostrarTodasLasSolicitudes(const string& archivoPath);
void mostrarUnaSolicitud(const string& archivoPath);
void imprimirDetallesSolicitud(const string& linea);
string buscarInformacionPlan(const string& codigoPlan, const string& archivoPlanes);
void imprimirDetallesPlan(const string& linea);

int main() {
    int opcion;
    do {
        mostrarMenuPrincipal();
        cin >> opcion;
        switch (opcion) {
            case 1:
                vistaAdministrador();
                break;
            case 2:
                vistaAlumno();
                break;
            case 3:
                vistaProfesor();
                break;
            case 4:
                cout << "-> Saliendo del sistema.\n";
                break;
            default:
                cout << "-> Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 4);
    return 0;
}

void mostrarMenuPrincipal() {
    cout << "\n===========================\n        ELIGE VISTA        \n===========================\n";
    cout << "1. Administrador\n";
    cout << "2. Alumno\n";
    cout << "3. Profesor\n";
    cout << "4. Salir\n\n";
    cout << "-> Seleccione una opción: ";
}

void vistaAdministrador() {
    int opcion;
    do {
        cout << "\n===========================\n    VISTA ADMINISTRADOR    \n===========================\n";
        cout << "1. Ver historial\n";
        cout << "2. Ver solicitudes\n";
        cout << "3. Crear plan de convalidación\n";
        cout << "4. Volver a la selección de vista\n\n";
        cout << "-> Seleccione una opción: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "\n==============================================\n     FUNCIÓN EN DESARROLLO: Ver historial.     \n==============================================\n";
                break;
            case 2: {
                verSolicitudes();
                break;
            }
            case 3:
                crearPlanDeConvalidacion();
                break;
            case 4:
                cout << "-> Volviendo al menú principal.\n";
                break;
            default:
                cout << "-> Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 4);
}

void vistaAlumno() {
    int opcion;
    do {
        cout << "\n===========================\n    VISTA ESTUDIANTE    \n===========================\n";
        cout << "1. Crear solicitud\n";
        cout << "2. Consultar solicitud\n";
        cout << "3. Eliminar solicitud\n";
        cout << "4. Volver al menú principal\n\n";
        cout << "-> Seleccione una opción: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                crearSolicitudAlumno();
                break;
            case 2:
            cout << "\n==============================================\n               CONSULTAR SOLICITUD               \n==============================================\n";
               
                mostrarUnaSolicitud("solicitudesestudiantes.txt");
                break;
            case 3:
                cout << "\n==============================================\n  FUNCIÓN EN DESARROLLO: Eliminar solicitud.  \n==============================================\n";
                break;
            case 4:
                cout << "-> Volviendo al menú principal.\n";
                break;
            default:
                cout << "-> Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 4);
}

void vistaProfesor() {
    int opcion;
    do {
        cout << "\n===========================\n    VISTA PROFESOR    \n===========================\n";
        cout << "1. Crear solicitud\n";
        cout << "2. Consultar solicitud\n";
        cout << "3. Eliminar solicitud\n";
        cout << "4. Volver al menú principal\n\n";
        cout << "-> Seleccione una opción: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                crearSolicitudProfesor();
                break;
            case 2:
                mostrarUnaSolicitud("solicitudesprofesores.txt");
                break;
            case 3:
                cout << "\n==============================================\n  FUNCIÓN EN DESARROLLO: Eliminar solicitud.  \n==============================================\n";
                break;
            case 4:
                cout << "-> Volviendo al menú principal.\n";
                break;
            default:
                cout << "-> Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 4);
}

void crearPlanDeConvalidacion() {
    int tipo;
    string duracion;
    string universidadId, universidadFacultad, universidadDireccion;

    cout << "\n====================================\n  CREANDO UN PLAN DE CONVALIDACIÓN  \n====================================\n";

    cout << "Ingrese la duración del plan: ";
    cin.ignore();
    getline(cin, duracion);

    cout << "Ingrese la ID de la universidad: ";
    getline(cin, universidadId);

    cout << "Ingrese la facultad de la universidad: ";
    getline(cin, universidadFacultad);

    cout << "Ingrese la dirección de la universidad: ";
    getline(cin, universidadDireccion);

    Universidad universidad(universidadId, universidadFacultad, universidadDireccion);

    cout << "\n===========================\n  SELECCIONA TIPO DE PLAN  \n===========================\n\n";
    cout << "1. Plan de profesores\n";
    cout << "2. Plan de estudiantes\n\n";
    cout << "-> Seleccione una opción: ";
    cin >> tipo;

    if (tipo == 1) {
        string departamento;
        cout << "Ingrese el departamento: ";
        cin.ignore();
        getline(cin, departamento);

        PlanProfesores plan(duracion, universidad, departamento);

        ofstream archivo("planesprofesores.txt", ios::app);
        if (archivo.is_open()) {
            archivo << universidadId << "|" << duracion << "|" << universidadFacultad << "|" << universidadDireccion << "|" << departamento << "\n";
            archivo.close();
            cout << "-> Plan de profesores registrado exitosamente.\n";
        } else {
            cout << "-> Error al abrir el archivo planesprofesores.txt.\n";
        }
    } else if (tipo == 2) {
        int numAsignaturas;
        cout << "Ingrese el número de asignaturas: ";
        cin >> numAsignaturas;

        vector<Asignatura> asignaturas;
        cin.ignore();
        for (int i = 0; i < numAsignaturas; ++i) {
            string nombre;
            int codigo, creditos;

            cout << "Ingrese el nombre de la asignatura " << i + 1 << ": ";
            getline(cin, nombre);

            cout << "Ingrese el código de la asignatura " << i + 1 << ": ";
            cin >> codigo;
            cout << "Ingrese los créditos de la asignatura " << i + 1 << ": ";
            cin >> creditos;
            cin.ignore();

            asignaturas.emplace_back(nombre, codigo, creditos);
        }

        PlanEstudiantes plan(duracion, universidad, asignaturas);

        ofstream archivo("planesestudiantes.txt", ios::app);
        if (archivo.is_open()) {
            archivo << universidadId << "|" << duracion << "|" << universidadFacultad << "|" << universidadDireccion;
            for (const auto& asignatura : asignaturas) {
                archivo << "|" << asignatura.obtenerNombre() << " (Código: " << asignatura.obtenerCodigo() << ", Créditos: " << asignatura.obtenerCreditos() << ")";
            }
            archivo << "\n";
            archivo.close();
            cout << "-> Plan de estudiantes registrado exitosamente.\n";
        } else {
            cout << "-> Error al abrir el archivo planesestudiantes.txt.\n";
        }
    } else {
        cout << "-> Opción no válida.\n";
    }
}

void imprimirPlanesEstudiantes(string carreraEstudiante) {
    ifstream archivo("planesestudiantes.txt");
    string linea;

    if (archivo.is_open()) {
        cout << "\n======================================================================\n  PLANES DE ESTUDIANTES DISPONIBLES PARA " << carreraEstudiante << "  \n======================================================================\n\n";
        while (getline(archivo, linea)) {
            if (linea.find(carreraEstudiante) != string::npos) {
                cout << linea << "\n\n";
            }
        }
        archivo.close();
    } else {
        cout << "-> Error al abrir el archivo planesestudiantes.txt.";
    }
}

void imprimirPlanesProfesores() {
    ifstream archivo("planesprofesores.txt");
    string linea;

    if (archivo.is_open()) {
        cout << "\n======================================\n  PLANES DISPONIBLES PARA PROFESORES  \n======================================\n\n";
        while (getline(archivo, linea)) {
            cout << linea << "\n\n";
        }
        archivo.close();
    } else {
        cout << "-> Error al abrir el archivo planesprofesores.txt.\n";
    }
}

string huecos(const string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    size_t last = str.find_last_not_of(" \t\n\r");
    return (first == string::npos || last == string::npos) ? "" : str.substr(first, (last - first + 1));
}

bool verificarDNIEnArchivo(const string& dni, const string& archivoPath) {
    ifstream archivo(archivoPath);
    string linea;
    while (getline(archivo, linea)) {
        linea = huecos(linea);
        size_t pos = linea.find('|');
        if (pos != string::npos) {
            string dniEnArchivo = huecos(linea.substr(pos + 1, linea.find('|', pos + 1) - pos - 1));
            if (dniEnArchivo == dni) {
                return true;
            }
        }
    }
    return false;
}

string obtenerFechaActual() {
    time_t ahora = time(0);
    tm* tiempoLocal = localtime(&ahora);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", tiempoLocal);
    return string(buffer);
}

void crearSolicitudAlumno() {
    string nombre, carrera, dni, email;
    vector<string> idPlanes;
    string idPlan;

    cout << "\n==============================\n  CREANDO SOLICITUD ALUMNO  \n==============================\n";


    cout << "Ingrese su nombre: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese su DNI: ";
    getline(cin, dni);

    cout << "Ingrese su email: ";
    getline(cin, email);

    cout << "Ingrese su carrera: ";
    getline(cin, carrera);

    if (verificarDNIEnArchivo(dni, "solicitudesestudiantes.txt")) {
        cout << "-> Ya existe una solicitud registrada con este DNI. Por favor, elimine la solicitud existente antes de crear una nueva.\n";
        return;
    }

    imprimirPlanesEstudiantes(carrera);

    cout << "\n-> Seleccione los códigos de los planes de convalidación en orden de prioridad (ingrese -1 para finalizar):";
    while (true) {
        cin >> idPlan;
        if (idPlan == "-1") break;
        idPlanes.push_back(idPlan);
    }

    ifstream archivo("planesestudiantes.txt");
    ofstream solicitudes("solicitudesestudiantes.txt", ios::app);
    string linea;

    if (archivo.is_open() && solicitudes.is_open()) {
        solicitudes << nombre << "|" << dni << "|"  << email << "|" << carrera;
        for (const auto& priority : idPlanes) {
            archivo.clear();
            archivo.seekg(0);
            bool found = false;
            while (getline(archivo, linea)) {
                if (linea.find(priority) != string::npos) {
                    solicitudes << "|" << priority;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "-> Código del plan no válido: " << priority << "\n";
            }
        }
        solicitudes << "|" << obtenerFechaActual() << "|Pendiente\n";
        archivo.close();
        solicitudes.close();
        cout << "-> Solicitud registrada exitosamente.\n";
    } else {
        cout << "-> Error al abrir los archivos.\n";
    }
}

void crearSolicitudProfesor() {
    string nombre, departamento, dni, email;
    vector<string> idPlanes;
    string idPlan;

    cout << "\n==============================\n  CREANDO SOLICITUD PROFESOR  \n==============================\n";

    cout << "Ingrese su nombre: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese su DNI: ";
    getline(cin, dni);

    cout << "Ingrese su email: ";
    getline(cin, email);

    if (verificarDNIEnArchivo(dni, "solicitudesprofesores.txt")) {
        cout << "-> Ya existe una solicitud registrada con este DNI. Por favor, elimine la solicitud existente antes de crear una nueva.\n";
        return;
    }

    cout << "Ingrese su departamento: ";
    getline(cin, departamento);

    imprimirPlanesProfesores();

    cout << "\n-> Seleccione los códigos de los planes de convalidación en orden de prioridad (ingrese -1 para finalizar):";
    while (true) {
        cin >> idPlan;
        if (idPlan == "-1") break;
        idPlanes.push_back(idPlan);
    }

    ifstream archivo("planesprofesores.txt");
    ofstream solicitudes("solicitudesprofesores.txt", ios::app);
    string linea;

    if (archivo.is_open() && solicitudes.is_open()) {
        solicitudes << nombre << "|" << dni << "|" << email << "|" << departamento;
        for (const auto& priority : idPlanes) {
            archivo.clear();
            archivo.seekg(0);
            bool found = false;
            while (getline(archivo, linea)) {
                if (linea.find(priority) != string::npos) {
                    solicitudes << "|" << priority;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "-> Código del plan no válido: " << priority << "\n";
            }
        }
        solicitudes << "|" << obtenerFechaActual() << "|Pendiente\n";
        archivo.close();
        solicitudes.close();
        cout << "-> Solicitud registrada exitosamente.\n";
    } else {
        cout << "-> Error al abrir los archivos.\n";
    }
}

void verSolicitudes() {
    int tipoSolicitud;
    cout << "\n================================================\n  SELECCIONA TIPO DE SOLICITUDES QUE DESEA VER  \n================================================\n";
    cout << "1. Solicitudes de estudiantes\n";
    cout << "2. Solicitudes de profesores\n\n";
    cout << "-> Seleccione una opción: ";
    cin >> tipoSolicitud;

    string archivoPath = (tipoSolicitud == 1) ? "solicitudesestudiantes.txt" : "solicitudesprofesores.txt";

    int detalleOpcion;
    cout << "\n=========================\n    ¿QUE DESEA HACER?    \n=========================\n";
    cout << "1. Ver todas las solicitudes\n";
    cout << "2. Ver una solicitud específica\n\n";
    cout << "-> Seleccione una opción: ";
    cin >> detalleOpcion;

    if (detalleOpcion == 1) {
        mostrarTodasLasSolicitudes(archivoPath);
    } else if (detalleOpcion == 2) {
        mostrarUnaSolicitud(archivoPath);
    } else {
        cout << "\n-> Opción no válida.\n";
    }
}

void mostrarTodasLasSolicitudes(const string& archivoPath) {
    ifstream archivo(archivoPath);
    string linea;
    if (archivo.is_open()) {
        cout << "\n============================\n    LISTA DE SOLICITUDES    \n============================\n";
        while (getline(archivo, linea)) {
            imprimirDetallesSolicitud(linea);
        }
        archivo.close();
    } else {
        cout << "-> No se pudo abrir el archivo de solicitudes.\n";
    }
}

void mostrarUnaSolicitud(const string& archivoPath) {
    string dni;
    cout << "Ingrese el DNI de la solicitud que desea ver: ";
    cin.ignore();
    getline(cin, dni);

    ifstream archivo(archivoPath);
    string linea;
    bool encontrada = false;

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            linea = huecos(linea);
            size_t posDNI = linea.find('|');
            if (posDNI != string::npos) {
                string dniEnLinea = huecos(linea.substr(posDNI + 1, linea.find('|', posDNI + 1) - posDNI - 1));
                if (dniEnLinea == dni) {
                    cout << "\n===============================\n    DETALLES DE SOLICITUDES    \n===============================\n";
                    imprimirDetallesSolicitud(linea);
                    encontrada = true;
                    break;
                }
            }
        }
        archivo.close();

        if (!encontrada) {
            cout << "-> No se encontró una solicitud con el DNI proporcionado.\n";
        }
    } else {
        cout << "-> No se pudo abrir el archivo de solicitudes.\n";
    }
}

string buscarInformacionPlan(const string& codigoPlan, const string& archivoPlanes) {
    ifstream archivo(archivoPlanes);
    string linea;
    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            if (linea.find(codigoPlan) != string::npos) {
                return linea;
            }
        }
        archivo.close();
    }
    return "-> Información del plan no encontrada.";
}

// Imprime los detalles de un plan de convalidación
void imprimirDetallesPlan(const string& linea) {
    vector<string> campos;
    size_t start = 0;
    size_t end;
    while ((end = linea.find('|', start)) != string::npos) {
        campos.push_back(huecos(linea.substr(start, end - start)));
        start = end + 1;
    }
    campos.push_back(huecos(linea.substr(start)));

    if (!campos.empty()) {
        if (campos.size() > 0) cout << "    Código: " << campos[0] << "\n";
        if (campos.size() > 1) cout << "    Duración: " << campos[1] << "\n";
        if (campos.size() > 2) cout << "    Facultad: " << campos[2] << "\n";
        if (campos.size() > 3) cout << "    Dirección: " << campos[3] << "\n";
    }
}

// Imprime los detalles de una solicitud específica
void imprimirDetallesSolicitud(const string& linea) {
    vector<string> campos;
    size_t start = 0;
    size_t end;
    while ((end = linea.find('|', start)) != string::npos) {
        campos.push_back(huecos(linea.substr(start, end - start)));
        start = end + 1;
    }
    campos.push_back(huecos(linea.substr(start)));

    if (!campos.empty()) {
        cout << "Nombre: " << campos[0] << "\n";
        if (campos.size() > 1) cout << "DNI: " << campos[1] << "\n";
        if (campos.size() > 2) cout << "Email: " << campos[2] << "\n";
        if (campos.size() > 3) cout << "Carrera o Departamento: " << campos[3];
        size_t limitePlanes = campos.size() - 2; // Penúltimo campo es la fecha, el último es el estado
        for (size_t i = 4; i < limitePlanes; ++i) {
            string informacionPlan = buscarInformacionPlan(campos[i], "planesprofesores.txt");
            if (informacionPlan == "-> Información del plan no encontrada.") {
                informacionPlan = buscarInformacionPlan(campos[i], "planesestudiantes.txt");
            }
            cout << "\n====================\n  PLAN PRIORIDAD " << (i - 3) << "  \n====================\n";
            imprimirDetallesPlan(informacionPlan);
            cout << "====================\n";
        }
        if (campos.size() > 1) {
            cout << "Fecha de inscripción: " << campos[campos.size() - 2] << "\n";
            cout << "Estado: " << campos.back() << "\n";
            cout << "===============================\n";
        }
    }
    cout << "\n";
}

//Alejandro Gómez Amaro
//Jorge Santos Jiménez
//Raúl Castillo Díaz