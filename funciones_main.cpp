#include <iostream>
#include "rlutil.h"
#include <string>
#include "funciones_main.h"
#include "Menu.h"
#include "1_clsSuscripcion.h"
#include "2_clsArchivos.h"

using namespace std;

///LOGIN///////////////////////////////////////////////////////
Suscripcion login(){
    system("cls");
    Suscripcion login, suscriptor;
    Archivos archivo;
    int cant_suscriptores;

    cout<<"INGRESE SU EMAIL Y CONTRASENIA"<<endl<<endl;
    cout<<"Email: ";
    login.cargarEmail();
    cout<<"Contrasenia: ";
    login.cargarContrasenia();
    cout<<endl;

    cant_suscriptores=archivo.CantidadRegis_susc();

    if(cant_suscriptores!=0){

        for(int i=0;i<cant_suscriptores;i++){
            suscriptor=archivo.leerSuscripcion(i);

            if(strcmp(login.getEmail(),suscriptor.getEmail())== 0&&
               strcmp(login.getContrasenia(),suscriptor.getContrasenia())==0){

                system("cls");
                AnimacionCarga("Iniciando Sesion ");
                login=suscriptor;
                login.setLogeado(true);
                rlutil::hidecursor();
                cout<<endl<<"Bienvenid@ "<<login.getNombre()<<"!";
                rlutil::msleep(2500);
                rlutil::showcursor();
                return login;
            }
        }
    }system("cls");
    cout<<"INGRESO INCORRECTO. "<<endl;
    rlutil::msleep(2000);
    return Suscripcion();
}
///SUSCRIBIRSE/////////////////////////////////////////////////
void crearNuevoUsuario (){
    system("cls");
    Archivos archivo;
    Suscripcion nuevoUsuario;
    int cantidadUsuarios=archivo.CantidadRegis_susc();
    nuevoUsuario.setIdentificador(cantidadUsuarios+1);
    cout<<"REGISTRO DE NUEVO USUARIO"<<endl;
    cout<<"-------------------------"<<endl;
    nuevoUsuario.Cargar();
    bool emailExistente=false;
    Suscripcion usuarioExistente;
    for(int i=0;i<cantidadUsuarios;i++){
        usuarioExistente=archivo.leerSuscripcion(i);
        if(strcmp(nuevoUsuario.getEmail(),usuarioExistente.getEmail())==0){
            emailExistente=true;
            break;
        }
    }
    if(emailExistente){
        cout<<endl<<"ERROR: El email ya está registrado."<<endl;
        system("pause");
        return;
    }
    archivo.append(nuevoUsuario);
    cout<<endl<<"REGISTRO EXITOSO! Bienvenido a nuestro servicio."<<endl;
    cout<<"Tu ID de suscriptor es: "<<nuevoUsuario.getIdentificador()<< endl;
    system("pause");
}
///LISTAR-CANCIONES////////////////////////////////////////////
void listaCanciones(Suscripcion sus, Fecha fechaHoy){
    Cancion cancion;
    Archivos archivo;
    system("cls");
    rlutil::locate(41,1);
    cout<<"L i s t a   d e   c a n c i o n e s"<<endl;
    menu_canciones();
    cancion=interaccion_de_menu();
    Accesos acceso(cancion,sus,fechaHoy);
    ///archivo.append(acceso);

    cout<<" ";
    rlutil::locate(1,1);
    system("pause");
}
///HISTORIAL///////////////////////////////////////////////////
void historial(Suscripcion sus){
    Archivos archivo;
    Accesos historialAccesos;
    Suscripcion historialBuscado;
    int cantidadUsuarios=archivo.CantidadRegis_susc();
    for(int i=0;i<cantidadUsuarios;i++){
        historialAccesos=archivo.leerAcceso(i);
        historialBuscado=historialAccesos.getSus();
        if(historialBuscado.getIdentificador()==sus.getIdentificador()){
            historialAccesos.Mostrar();
        }
    }
}
///////////////////////////////////////////////////////////////

void AnimacionCarga(std::string str){
    rlutil::hidecursor();
    for(int i=0;i<=100;i++){
        cout<<"\r"<<str<<i<<"%"<<flush;
        rlutil::msleep(12);
    }
    rlutil::showcursor();
    ///flush: los cout aveces no imprimen al instante por que hay una memoria intermedia entre el cout y
    ///la impresion por consola que se llama bufer donde las cadenas del cout van a parar antes de ser
    ///mostradas por consola, evitando que se imprima lo que contiene al instante, cuando el buffer
    ///se llena, se hace un \n o endl, se imprime lo que contienen dentro automaticamente, si uno quiere
    ///forzar una impresion en tiempo real se usa el flush para liberar lo que contiene el bufer manualmente
}


