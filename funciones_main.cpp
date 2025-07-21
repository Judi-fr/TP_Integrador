#include <iostream>
#include <string>
#include "1_clsSuscripcion.h"
#include "1_archSuscripcion.h"
#include "3_archCanciones.h"
#include "4_archAccesos.h"
#include "2_clsArchivos.h"
#include "Hora.h"
#include "funciones_main.h"
#include "Menu.h"
#include "MenuListarCanciones.h"
#include "rlutil.h"


using namespace std;

///LOGIN///////////////////////////////////////////////////////
Suscripcion login(){
    system("cls");
    Suscripcion login, suscriptor;
    Archivo_Suscripcion archivo;
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
               strcmp(login.getContrasenia(),suscriptor.getContrasenia())==0 && suscriptor.getBajaLogica()==true){

                system("cls");
                ///AnimacionCarga("Iniciando Sesion ");
                login=suscriptor;
                login.setLogeado(true);
                rlutil::hidecursor();
                cout<<"Bienvenid@ "<<login.getNombre()<<"!";
                rlutil::msleep(1200);
                rlutil::showcursor();
                return login;
            }
        }
    }system("cls");
    cout<<"INGRESO INCORRECTO O USUARIO DADO DE BAJA"<<endl;
    rlutil::msleep(1500);
    return Suscripcion();
}
///SUSCRIBIRSE/////////////////////////////////////////////////
void crearNuevoUsuario (){
    system("cls");
    Archivo_Suscripcion archivo;
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
    nuevoUsuario.setBajaLogica(true);
    archivo.append(nuevoUsuario);
    cout<<endl<<"REGISTRO EXITOSO! Bienvenido a nuestro servicio."<<endl;
    cout<<"Tu ID de suscriptor es: "<<nuevoUsuario.getIdentificador()<< endl;
    system("pause");
}

///MI-PERFIL///////////////////////////////////////////////////

void mi_perfil(Suscripcion sus){
    Fecha fechaNacimiento = sus.getFecha();
    rlutil::locate(6,10);
    cout<<sus.getNombre()<<" "<<sus.getApellido()<<endl;
    rlutil::locate(6,11);
    cout<<"Dni: "<<sus.getDni()<<endl;
    rlutil::locate(6,12);
    cout<<"Fecha de nacimiento: "
    <<fechaNacimiento.getDia()<<"/"
    <<fechaNacimiento.getMes()<<"/"
    <<fechaNacimiento.getAnio()<<endl;
    rlutil::locate(6,13);
    cout<<"Telefono: "<<sus.getTelefono()<<endl;
    rlutil::locate(6,14);
    cout<<"Email: "<<sus.getEmail()<<endl;
    rlutil::locate(6,15);
    cout<<"Suscriptor N"<<char(167)<<sus.getIdentificador();

    rlutil::anykey();

    rlutil::locate(6,9);
    cout<<"                                     "<<endl;
    rlutil::locate(6,10);
    cout<<"                                     "<<endl;
    rlutil::locate(6,11);
    cout<<"                                     "<<endl;
    rlutil::locate(6,12);
    cout<<"                                     "<<endl;
    rlutil::locate(6,13);
    cout<<"                                     "<<endl;
    rlutil::locate(6,14);
    cout<<"                                     "<<endl;
}


///LISTAR-CANCIONES////////////////////////////////////////////
void listaCanciones(Suscripcion sus, Fecha fechaHoy){
    int idCancion, idSuscriptor, contador;
    Cancion cancion;
    Archivo_Cancion archivoCanc;
    Archivo_Acceso archivoAcc;
    system("cls");
    rlutil::locate(41,1);
    cout<<"L i s t a   d e   c a n c i o n e s"<<endl;
    contador=menu_canciones();
    cancion=interaccion_de_menu(contador);
    if(cancion.getCargado()== true){
        cancion.sumarReproduccion();
        int pocision=archivoCanc.SaberPocision(cancion);
        archivoCanc.Actualizar(pocision, cancion);

        idCancion=cancion.getNumero();
        idSuscriptor=sus.getIdentificador();
        Hora hora;
        hora.Cargar();
        Accesos acceso(idCancion,idSuscriptor,fechaHoy,hora);
        archivoAcc.append(acceso);
    }
    rlutil::locate(1,1);
}
///HISTORIAL///////////////////////////////////////////////////
int historial(Suscripcion sus){
    Archivo_Acceso archivoAcc;
    Archivo_Suscripcion archivoSus;
    Accesos axes;
    Suscripcion historialBuscado;
    int cantidad_accesos=archivoAcc.CantidadRegis_acces();
    int x=0, y=0,idSuscripcion,contador=0;

    for(int i=0;i<cantidad_accesos;i++){
        axes=archivoAcc.leerAcceso(i);
        historialBuscado=archivoSus.BuscarPorId(axes.getSuscripcion());
        if(strcmp(sus.getEmail(),historialBuscado.getEmail())==0&&axes.getFecha().getAnio()!=1900){
            contador++;
            dibujar_acceso(x,y,axes);
            if(x==0 || x==33){
                x+=33;
            }else{
                x=0;
                y+=6;}
        }
    }return contador;
}
void dibujar_acceso(int x,int y,Accesos axes){
    Archivo_Suscripcion archivoSus;
    Archivo_Cancion archivoCan;

    Suscripcion sus=archivoSus.BuscarPorId(axes.getSuscripcion());
    Cancion song =archivoCan.BuscarPorId(axes.getCanciones());
    Fecha fecha = axes.getFecha();
    Hora hora = axes.getHora();

    rlutil::locate(14+x,11+y);
    cout<<song.getNombre();
    rlutil::locate(14+x,12+y);
    cout<<song.getAutor();
    rlutil::locate(14+x,13+y);
    cout<<"Interprete: "<<song.getInterprete();
    rlutil::locate(14+x,14+y);
    fecha.Mostrar();
    cout<<" ";
    hora.Mostrar();
    rlutil::locate(14+x,15+y);
    cout<<sus.getNombre()<<" "<<sus.getApellido();
}
void switchHistorial(){
    bool booleano=true;
    int x=16,y=16;
    while(booleano){
        rlutil::hidecursor();
        int key=rlutil::getkey();
        switch(key){
            case 14:
                ///ARRIBA
                y-=7;
                rlutil::locate(x,y);
                break;
            case 15:
                ///ABAJO
                y+=7;
                rlutil::locate(x,y);
                break;
            default:
                rlutil::showcursor();
                booleano=false;
                break;

        }
    }
}
void dibujar_grilla(int contador){
    int division=contador/3,resto=contador%3,x=0,y=0;

    for(int i=0;i<division;i++){
        for(int j=0;j<3;j++){
            rlutil::locate(9+x,11+y);
            cout<<char(179);
            rlutil::locate(9+x,12+y);
            cout<<char(179);
            rlutil::locate(9+x,13+y);
            cout<<char(179);
            rlutil::locate(9+x,14+y);
            cout<<char(179);
            rlutil::locate(9+x,15+y);
            cout<<char(179);
            rlutil::locate(9+x,16+y);
            cout<<char(179);
            if(j==0){x+=33;}else{x+=34;}

        }x=0;y+=6;
    }
    if(resto!=0){
        for(int j=0;j<3;j++){
            rlutil::locate(9+x,11+y);
            cout<<char(179);
            rlutil::locate(9+x,12+y);
            cout<<char(179);
            rlutil::locate(9+x,13+y);
            cout<<char(179);
            rlutil::locate(9+x,14+y);
            cout<<char(179);
            rlutil::locate(9+x,15+y);
            cout<<char(179);
            rlutil::locate(9+x,16+y);
            cout<<char(179);
            if(j==0){x+=33;}else{x+=34;}
        }
    }
}

///////////////////////////////////////////////////////////////

///REPORTE-1////////////////////////////////////////////////// bau
void reporte1() {
    system("cls");
    Archivo_Cancion archivo;
    char autorBuscado[30];
    bool encontrado=false;
    int cantidadCanciones=archivo.CantidadRegis_canc();
    cout<<"===================================="<<endl;
    cout<<"   BUSCAR DISCOGRAFIA POR AUTOR     "<<endl;
    cout<<"===================================="<<endl<<endl;
    cout<<"Ingrese el nombre del autor: ";
    cin.ignore();
    cin.getline(autorBuscado, 30);
    system("cls");
    cout<<"===================================="<<endl;
    cout<<"  DISCOGRAFIA DE: "<<autorBuscado<<endl;
    cout<< "===================================="<<endl;
    for(int i=0;i<cantidadCanciones;i++){
        Cancion cancion=archivo.leerCancion(i);
        if(strcmp(cancion.getAutor(),autorBuscado)==0){
            cout<<"Cancion #"<<cancion.getNumero()<<endl;
            cout<<"Titulo: "<<cancion.getNombre()<<endl;
            cout<<"Interprete: "<<cancion.getInterprete()<<endl;
            cout<<"Reproducciones: "<<cancion.getReproducciones()<<endl;
            cout<<"------------------------------------" << endl;
            encontrado=true;
        }
    }
    if(!encontrado){
        cout<<"No se encontraron canciones para el autor "<<autorBuscado<<""<<endl;
    }
    cout<<endl<< "Presione cualquier tecla para continuar...";
    rlutil::anykey();
}
/////////////////////////////////////////////////////////////

///REPORTE-2///////////////////////////////////////////////// bau
void reporte2() {
    system("cls");
    Archivo_Acceso archivoAcc;
    Archivo_Cancion archivoCan;
    int totalAccesos=archivoAcc.CantidadRegis_acces();
    if(totalAccesos==0){
        cout<<"No hay registros de reproducciones."<<endl;
        system("pause");
        return;
    }
    int totalCanciones=archivoCan.CantidadRegis_canc();
    char** autoresValidos=new char*[totalCanciones];
    int totalAutoresValidos=0;
    for(int i=0;i<totalCanciones;i++){
        Cancion cancion=archivoCan.leerCancion(i);
        const char* autor=cancion.getAutor();
        if(autor != nullptr&&autor[0]!='\0'){
            bool existe=false;
            for(int j=0;j<totalAutoresValidos;j++){
                if(strcmp(autoresValidos[j],autor)==0){
                    existe=true;
                    break;
                }
            }
            if(!existe){
                autoresValidos[totalAutoresValidos]=new char[strlen(autor)+1];
                strcpy(autoresValidos[totalAutoresValidos],autor);
                totalAutoresValidos++;
            }
        }
    }
    if(totalAutoresValidos==0){
        cout<<"No hay autores válidos registrados en el sistema."<<endl;
        for(int i=0;i<totalAutoresValidos;i++) {
            delete[] autoresValidos[i];
        }
        delete[] autoresValidos;
        system("pause");
        return;
    }
    int* conteoReproducciones=new int[totalAutoresValidos]();
    for(int i=0;i<totalAccesos;i++) {
        Archivo_Cancion archivoCan;
        Accesos acceso=archivoAcc.leerAcceso(i);
        Cancion cancion=archivoCan.BuscarPorId(acceso.getCanciones());
        const char* autorActual=cancion.getAutor();

        if(autorActual!=nullptr&&autorActual[0]!='\0'){
            for(int j=0;j<totalAutoresValidos;j++){
                if(strcmp(autoresValidos[j],autorActual)==0){
                    conteoReproducciones[j]++;
                    break;
                }
            }
        }
    }
    int maxReproducciones=0;
    int indiceMax=-1;
    for(int i=0;i<totalAutoresValidos;i++){
        if(conteoReproducciones[i]>maxReproducciones){
            maxReproducciones=conteoReproducciones[i];
            indiceMax=i;
        }
    }
    if(indiceMax==-1){
        cout<<"No se encontraron reproducciones de autores válidos."<<endl;
    }else{
        cout<<"REPORTE DE AUTOR MAS POPULAR"<<endl;
        cout<<"============================"<<endl;
        cout<<"Autor con mas reproducciones: "<<autoresValidos[indiceMax]<<endl;
        cout<<"Total de reproducciones: "<<maxReproducciones<<endl<<endl;
    }
    for(int i=0;i<totalAutoresValidos;i++){
        delete[]autoresValidos[i];
    }
    delete[]autoresValidos;
    delete[]conteoReproducciones;

    system("pause");
}
//////////////////////////////////////////////////////////////////

///REPORTE-3////////////////////////////////////////////////////// matt
void reporte3() {
    Archivo_Cancion archivo;
    Cancion cancion, cancionAux;
    char original[9]="Original";
    int cantidadCanciones = archivo.CantidadRegis_canc();

    cout<<"LAS CANCIONES QUE NO ESTAN INTERPRETADAS POR SU AUTOR ORIGINAL SON"<<endl<<endl;
    for(int i=0;i<cantidadCanciones;i++){
        cancion=archivo.leerCancion(i);
        if(strcmp(cancion.getInterprete(),original)==1){
            cout<<cancion.getNombre()<<endl;
            cout<<cancion.getAutor()<<endl;
            cout<<cancion.getInterprete()<<endl<<endl;
        }

    }
    system("pause");
}
//////////////////////////////////////////////////////////////////

///REPORTE-4////////////////////////////////////////////////////// bau
void reporte4(){
    system("cls");
    Archivo_Acceso archivoAcc;
    Archivo_Suscripcion archivoSus;
    Fecha fechaConsulta;
    cout<<"INGRESE LA FECHA: ";
    fechaConsulta.Cargar();
    int totalAccesos=archivoAcc.CantidadRegis_acces();
    int totalUsuarios=archivoSus.CantidadRegis_susc();
    int* dnisValidos=new int[totalUsuarios];
    string* nombresValidos=new string[totalUsuarios];
    int* reproducciones=new int[totalUsuarios]();
    int usuariosRegistrados=0;
    for(int i=0;i<totalUsuarios;i++){
        Suscripcion suscriptor=archivoSus.leerSuscripcion(i);
        dnisValidos[usuariosRegistrados]=suscriptor.getDni();
        nombresValidos[usuariosRegistrados]=string(suscriptor.getNombre()) + " " + string(suscriptor.getApellido());
        usuariosRegistrados++;
    }
    int totalReproducciones=0;
    for(int i=0;i<totalAccesos;i++){
        Accesos acceso=archivoAcc.leerAcceso(i);
        if(acceso.getFecha()==fechaConsulta){
            Suscripcion sus1;
            sus1= archivoSus.BuscarPorId(acceso.getSuscripcion());
            int dni=sus1.getDni();
            for(int j=0;j<usuariosRegistrados;j++){
                if(dnisValidos[j]==dni){
                    reproducciones[j]++;
                    totalReproducciones++;
                    break;
                }
            }
        }
    }
    cout<<"REPORTE DE REPRODUCCIONES ";
    cout<<fechaConsulta.getDia()<<"/"<<fechaConsulta.getMes()<<"/"<<fechaConsulta.getAnio()<<endl;
    cout<<"=========================================="<<endl;
    bool hayResultados=false;
    for(int i=0;i<usuariosRegistrados;i++){
        if(reproducciones[i]>10){
            cout<<"DNI: "<<dnisValidos[i]<<endl;
            cout<<"Nombre: "<<nombresValidos[i]<<endl;
            cout<<"Reproducciones: "<<reproducciones[i]<<endl;
            cout<<"-------------------------------------"<<endl;
            hayResultados=true;
        }
    }
    if(!hayResultados){
        cout<<"No hubo usuarios con mÃ¡s de 10 reproducciones"<<endl;
    }
    cout<<"Total de reproducciones registradas: "<<totalReproducciones<<endl;
    delete[] dnisValidos;
    delete[] nombresValidos;
    delete[] reproducciones;
    system("pause");
}
//////////////////////////////////////////////////////////////////

///REPORTE-5////////////////////////////////////////////////////// yo
void reporte5(){
    Archivo_Cancion archivoCan;
    Archivo_Acceso archivoAcc;
    int AccesosTotales = archivoAcc.CantidadRegis_acces();
    Accesos acceso;
    Fecha fechaIngresada;
    fechaIngresada.Cargar();
    system("cls");
    cout<<"EN EL DIA INGRESADO LAS CANCIONES CON MAS REPRODUCCIONES SON:"<<endl;
    cout<<"-------------------------------------------------------------"<<endl<<endl;
    int cantidadEncontradas = 0;
    int cantidadCanciones=archivoCan.CantidadRegis_canc();

    int* idsCanciones = new int[cantidadCanciones];
    int* cantidadReproducciones = new int[cantidadCanciones];

    // Inicializo en 0
    for(int i=0;i<cantidadCanciones;i++){
        idsCanciones[i]=0;
        cantidadReproducciones[i]=0;
    }

    ///recorro los accesos
    for(int i=0; i<AccesosTotales; i++){
        acceso = archivoAcc.leerAcceso(i);
        if(acceso.getFecha() == fechaIngresada){
            Cancion song = archivoCan.BuscarPorId(acceso.getCanciones());
            int idCancion = song.getNumero();
            int pos = -1;
            for(int j=0; j<cantidadEncontradas; j++){
                if(idsCanciones[j] == idCancion){
                    pos = j;
                    break;
                }
            }
            if(pos == -1){
                idsCanciones[cantidadEncontradas] = idCancion;
                cantidadReproducciones[cantidadEncontradas] += 1;
                cantidadEncontradas++;
            }
            else {
                cantidadReproducciones[pos]++;
            }
        }
    }

    /// Ordeno de mayor a menor
    for(int i=0; i<cantidadEncontradas-1; i++){
        for(int j=i+1; j<cantidadEncontradas; j++){
            if(cantidadReproducciones[j] > cantidadReproducciones[i]){
                ///cambia los valores de reproducciones por el mayor
                int auxCant = cantidadReproducciones[i];
                cantidadReproducciones[i] = cantidadReproducciones[j];
                cantidadReproducciones[j] = auxCant;

                ///cambia los valores de id tambien
                int auxID = idsCanciones[i];
                idsCanciones[i] = idsCanciones[j];
                idsCanciones[j] = auxID;
            }
        }
    }

    /// Muestro el resultado
    for(int i=0; i<cantidadEncontradas; i++){
        Cancion cancion = archivoCan.BuscarPorId(idsCanciones[i]);
        cout<<cancion.getNombre()<<" - "<<cantidadReproducciones[i]<<" reproducciones."<<endl;
    }

    delete[] idsCanciones;
    delete[] cantidadReproducciones;



}
//////////////////////////////////////////////////////////////////

///MODIFICAR-REGISTROS////////////////////////////////////////////
void Modif_susc(Suscripcion sus){
    int id;
    Archivo_Suscripcion archivo;
    if(!sus.getLogeado()){
        cout<<"Ingrese el ID de la suscripcion a modificar. ";
        cin>>id;
        sus=archivo.BuscarPorId(id);
    }
    if(sus.getIdentificador()!=-1){
        bool salir = false;
        while(salir == false){
            system("cls");
            cout<<"1. Nombre: "<<sus.getNombre();
            cout<<endl<<"2. Apellido: "<<sus.getApellido();
            cout<<endl<<"3. DNI: "<<sus.getDni();
            cout<< endl<<"4. Fecha de nacimiento: "; sus.getFecha().Mostrar(); // si está sobrecargado <<
            cout<<endl<<"5. Telefono: "<<sus.getTelefono();
            cout<<endl<<"6. Email: "<<sus.getEmail();
            cout<<endl<<"7. Contrasenia: "<<sus.getContrasenia();
            cout<<endl<<"8. Guardar y salir"<<endl<<endl;

            cout<<"Que parte del registro queres modificar? (1-8) "<<endl<<endl<<" >>> ";
            cin>>id;
            cin.ignore();
            switch(id){
                case 1: {
                    char nombre[30];
                    cout << "Nuevo nombre: "<<flush;
                    cin.getline(nombre, 30);
                    sus.setNombre(nombre);
                    break;
                }
                case 2: {
                    char apellido[30];
                    cout << "Nuevo apellido: "<<flush;
                    cin.getline(apellido, 30);
                    sus.setApellido(apellido);
                    break;
                }
                case 3: {
                    int nuevoDni;
                    cout << "Nuevo DNI: "<<flush;
                    cin >> nuevoDni;
                    sus.setDni(nuevoDni);
                    cin.ignore();
                    break;
                }
                case 4: {
                    Fecha nuevaFecha;
                    nuevaFecha.Cargar();
                    sus.setFechaNac(nuevaFecha);
                    cin.ignore();
                    break;
                }
                case 5: {
                    int tel;
                    cout << "Nuevo teléfono: "<<flush;
                    cin >> tel;
                    sus.setTelefono(tel);
                    cin.ignore();
                    break;
                }
                case 6: {
                    char nuevoEmail[50];
                    cout << "Nuevo email: "<<flush;
                    cin.getline(nuevoEmail, 50);
                    sus.setEmail(nuevoEmail);
                    break;
                }
                case 7: {
                    char nuevaContrasenia[50];
                    cout << "Nueva contraseña: "<<flush;
                    cin.getline(nuevaContrasenia, 50);
                    sus.setContrasenia(nuevaContrasenia);
                    break;
                }
                case 8:
                    int pos=archivo.SaberPocision(sus);
                    archivo.Actualizar(pos,sus);
                    salir=true;
                    break;
            }
        }
    }
}
void Modif_canc(){
    int id;
    Archivo_Cancion archivo;
    Cancion cancion;

    cout << "Ingrese el ID de la canción a modificar: ";
    cin >> id;
    cin.ignore();

    cancion = archivo.BuscarPorId(id);

    if (cancion.getNumero() != -1) {
        system("cls");
        bool salir = false;

        while (!salir) {
            system("cls");
            cout << "1. Nombre: " << cancion.getNombre();
            cout << endl << "2. Autor: " << cancion.getAutor();
            cout << endl << "3. Interprete: " << cancion.getInterprete();
            cout << endl << "4. Fecha de publicacion: ";
            cancion.getFechaPub().Mostrar();
            cout << endl << "5. Guardar y salir" << endl<<endl;

            cout << "Que parte del registro queres modificar? (1-5): "<<endl<<" >>> ";
            cin >> id;
            cin.ignore();

            switch (id) {
                case 1: {
                    char nombre[30];
                    cout << "Nuevo nombre: "<<flush;
                    cin.getline(nombre, 30);
                    cancion.setNombre(nombre);
                    break;
                }
                case 2: {
                    char autor[30];
                    cout << "Nuevo autor: "<<flush;
                    cin.getline(autor, 30);
                    cancion.setAutor(autor);
                    break;
                }
                case 3: {
                    char interprete[30];
                    cout << "Nuevo intérprete: "<<flush;
                    cin.getline(interprete, 30);
                    cancion.setInterprete(interprete);
                    break;
                }
                case 4: {
                    Fecha nuevaFecha;
                    nuevaFecha.Cargar();
                    cancion.setFechaPub(nuevaFecha);
                    break;
                }
                case 5: {
                    int pos = archivo.SaberPocision(cancion);
                    archivo.Actualizar(pos, cancion);
                    salir = true;
                    break;
                }
                default:
                    cout << "Opción inválida." << endl;
                    break;
                }
        }
    }
}

///LISTAR///////////////////////////////////////////////
void listar_canc(){
    system("cls");
    int cantidad = mostrarTodasLasCanciones();
    dibujar_grilla(cantidad);
    switchHistorial();
}
int mostrarTodasLasCanciones() {
    Archivo_Cancion archivoCan;
    Cancion song;
    int cantidad_canciones = archivoCan.CantidadRegis_canc();
    int x = 0, y = 0, contador = 0;

    for (int i = 0; i < cantidad_canciones; i++) {
        song = archivoCan.leerCancion(i);
        dibujar_cancion(x, y, song);
        contador++;

        if (x == 0 || x == 33) {
            x += 33;
        } else {
            x = 0;
            y += 6;
        }
    }

    return contador;
}
void dibujar_cancion(int x, int y, Cancion song) {
    rlutil::locate(14 + x, 11 + y);
    cout << song.getNombre();
    rlutil::locate(14 + x, 12 + y);
    cout << song.getAutor();
    rlutil::locate(14 + x, 13 + y);
    cout << "Interprete: " << song.getInterprete();
    rlutil::locate(14 + x, 14 + y);
    if(song.getBajaLogica()){
        rlutil::setColor(rlutil::GREEN);
        cout<<"Activada";
        rlutil::setColor(rlutil::WHITE);
    }else{
        rlutil::setColor(rlutil::RED);
        cout<<"Desactivada";
        rlutil::setColor(rlutil::WHITE);
    }
    rlutil::locate(14 + x, 15 + y);
    cout<<"ID: "<<song.getNumero();
}
////////////////////////////////////////////////////////
///LISTAR-SUSCRIPCIONES////////////////////////////////
void listar_sus(){
    system("cls");
    int cantidad = mostrarTodosLosSuscriptores();
    dibujar_grilla(cantidad);  // Usa la misma función que ya tenés
    switchHistorial();
}
int mostrarTodosLosSuscriptores() {
    Archivo_Suscripcion archivoSus;
    Suscripcion sus;
    int cantidad_suscriptores = archivoSus.CantidadRegis_susc();
    int x = 0, y = 0, contador = 0;

    for (int i = 0; i < cantidad_suscriptores; i++) {
        sus = archivoSus.leerSuscripcion(i);
        dibujar_suscriptor(x, y, sus);
        contador++;

        if (x == 0 || x == 33) {
            x += 33;
        } else {
            x = 0;
            y += 6;
        }
    }

    return contador;
}
void dibujar_suscriptor(int x, int y, Suscripcion sus) {
    rlutil::locate(14 + x, 11 + y);
    cout << "ID: " << sus.getIdentificador();
    rlutil::locate(14 + x, 12 + y);
    cout << sus.getNombre() << " " << sus.getApellido();
    rlutil::locate(14 + x, 13 + y);
    cout << "DNI: " << sus.getDni();
    rlutil::locate(14 + x, 14 + y);
    cout << "Email: " << sus.getEmail();
    rlutil::locate(14 + x, 15 + y);
    cout << "Telefono: " << sus.getTelefono();
    rlutil::locate(14 + x, 16 + y);
    if (sus.getBajaLogica()) {
        rlutil::setColor(rlutil::GREEN);
        cout << "Activo";
    } else {
        rlutil::setColor(rlutil::RED);
        cout << "Inactivo";
    }
    rlutil::setColor(rlutil::WHITE);
}
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


