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
        bool logeado = false;
        Fecha fechaNacimiento;
    public:
        Suscripcion();

        void setIdentificador(int );
        void setDni(int );
        void setNombre(const char * );
        void setApellido(const char * );
        void setTelefono(int );
        void setEmail(const char *);
        void setContrasenia(const char *);
        void setLogeado(bool );
        void setFechaNac(Fecha x);

        int getIdentificador();
        int getDni();
        const char *getNombre();
        const char *getApellido();
        int getTelefono();
        const char *getEmail();
        const char *getContrasenia();
        bool getLogeado();
        Fecha getFecha();

        void Cargar();
        void cargarEmail();
        void cargarContrasenia();

        void Mostrar();
};



#endif // CLSSUSCRIPCION_H_INCLUDED
