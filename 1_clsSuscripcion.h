#ifndef CLSSUSCRIPCION_H_INCLUDED
#define CLSSUSCRIPCION_H_INCLUDED
#include <cstring>
#include "Fecha.h"

class Suscripcion{
    private:
        int identificador;
        int dni;
        std::string nombre;
        std::string apellido;
        int telefono;
        std::string email;
        Fecha fechaNacimiento;
    public:
        Suscripcion(int identificador=1,int dni=0 , std::string nombre ="N/A", std::string apellido="N/A",int telefono=0,std::string email="pepito@hotmail.com",int[]={} );

        void setIdentificador(int );
        void setDni(int );
        void setNombre(std::string );
        void setApellido(std::string );
        void setTelefono(int );
        void setEmail(std::string );
        void setFechaNac(Fecha x);

        int getIdentificador();
        int getDni();
        std::string getNombre();
        std::string getApellido();
        int getTelefono();
        std::string getEmail();
        Fecha getFecha();

        void Cargar();
        void Mostrar();
};



#endif // CLSSUSCRIPCION_H_INCLUDED
