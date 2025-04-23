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
        char email[30];
        Fecha fechaNacimiento;
    public:
        Suscripcion(int identificador=1,int dni=0 , const char *nombre ="N/A", const char *apellido="N/A",int telefono=0,const char *email="pepito@hotmail.com",int[]={} );

        void setIdentificador(int );
        void setDni(int );
        void setNombre(const char *);
        void setApellido(const char *);
        void setTelefono(int );
        void setEmail(const char *);
        void setFechaNac(Fecha x);

        int getIdentificador();
        int getDni();
        const char *getNombre();
        const char *getApellido();
        int getTelefono();
        const char *getEmail();
        Fecha getFecha();

        void Cargar();
        void Mostrar();
};



#endif // CLSSUSCRIPCION_H_INCLUDED
