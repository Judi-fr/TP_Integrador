#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED

class Fecha{
    private:
        int dia, mes, anio;
        bool cargada=false;
    public:
        bool operator==(const Fecha& otra);
        Fecha(int ,int ,int );
        Fecha();
        void setDia(int);
        void setMes(int);
        void setAnio(int);
        int getDia();
        int getMes();
        int getAnio();
        bool getBool();
        void Cargar();
        void Mostrar();
};

#endif // CLSFECHA_H_INCLUDED
