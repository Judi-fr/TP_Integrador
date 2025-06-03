#include "4_clsAccesos.h"
///METODOS ACCESOS
using namespace std;

Accesos::Accesos(Cancion cancion_, Suscripcion suscripcion_, Fecha fecha_){
    cancion=cancion_;
    suscriptor=suscripcion_;
    diaEscuchado=fecha_;
}

Accesos::Accesos(){

}
