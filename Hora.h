#ifndef HORA_H_INCLUDED
#define HORA_H_INCLUDED

class Hora{
    private:
        int hora;
        int minuto;
        int segundo;
    public:
        Hora(int ,int ,int );

        void setHora(int );
        void setMinuto(int );
        void setSegundo(int );
        int getHora();
        int getMinuto();
        int getSegundo();

        void Cargar();
        void Mostrar(int , int );



};


#endif // HORA_H_INCLUDED
