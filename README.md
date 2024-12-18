# SICUE UCO
SICUE UCO es una aplicación diseñada para la gestión de inscripciones y planes de convalidación en el programa SICUE de la Universidad de Córdoba.
La herramienta permite a estudiantes, profesores y administradores gestionar de manera eficiente el intercambio académico entre universidades.

## Características principales:
### Para Estudiantes:
  - **Crear solicitudes:** Los estudiantes pueden inscribirse en el programa SICUE indicando sus datos personales y seleccionando planes de convalidación.
  - **Consultar estado:** Verificar el estado actual de su inscripción y detalles del plan seleccionado.

### Para Profesores:
  - **Crear solicitudes:** Inscribirse en planes de convalidación asociados a sus departamentos.
  - **Consultar estado:** Revisar las solicitudes realizadas y sus estados actuales.

### Para Administradores:
  - **Ver solicitudes:** Visualizar solicitudes concretas o mostrar todas las existentes.
  - **Creación de planes de convalidación:** Diseñar y registrar planes específicos para estudiantes y profesores.

## **Requisitos**
- **Lenguaje:** C++
- **Entorno de desarrollo:** Eclipse IDE (opcional, pero recomendado).
- **Dependencias:** Ninguna adicional requerida, usa librerías estándar de C++.

## **Estructura del Proyecto**
```
|-- menu.cc            # Lógica principal del menú y vistas.
|-- Usuario.h          # Definición de la clase Usuario.
|-- Solicitud.h        # Definición de la clase Solicitud.
|-- PlanDeConvalidacion.h # Definición de los planes de convalidación.
|-- Universidad.h      # Clases relacionadas con universidades.
|-- Asignatura.h       # Clases relacionadas con asignaturas.
|-- constructores.cc   # Constructores de todas las clases.
```

## **Autores**
Alejandro Gómez Amaro, Jorge Santos Jiménez, Raúl Castillo Díaz.
