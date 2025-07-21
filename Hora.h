#ifndef HORA_H_INCLUDED
#define HORA_H_INCLUDED

class Hora{
    private:
        int hora;
        int minuto;
        int segundo;
    public:
        Hora(int ,int ,int );
        Hora();
        void setHora(int );
        void setMinuto(int );
        void setSegundo(int );
        int getHora();
        int getMinuto();
        int getSegundo();

        void Cargar();
        void Mostrar();



};


#endif // HORA_H_INCLUDED
