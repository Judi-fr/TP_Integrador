#ifndef CLSSUSCRIPCION_H_INCLUDED
#define CLSSUSCRIPCION_H_INCLUDED
#include <cstring>
#include "Fecha.h"

class Suscripcion{
    private:
        int identificador;
        int dni;
        char nombre[30];
        char apellido[30];
        int telefono;
        char email[50];
        char contrasenia[50];
        Fecha fechaNacimiento;
    public:
        Suscripcion();

        void setIdentificador(int );
        void setDni(int );
        void setNombre(const char * );
        void setApellido(const char * );
        void setTelefono(int );
        void setEmail();
        void setContrasenia();
        void setFechaNac(Fecha x);

        int getIdentificador();
        int getDni();
        const char *getNombre();
        const char *getApellido();
        int getTelefono();
        const char *getEmail();
        const char *getContrasenia();
        Fecha getFecha();

        void Cargar();
        void Mostrar();
};



#endif // CLSSUSCRIPCION_H_INCLUDED
