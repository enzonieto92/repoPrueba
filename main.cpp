#include <iostream>
#include <cstring>

using namespace std;

const char *CANCIONES = "Canciones.dat";
const char *INTERPRETES = "Interpretes.dat";

#include "funcionesGlobales.h"
#include "clsFecha.h"
#include "clsCancion.h"
#include "clsInterprete.h"
#include "funcionesGlobalesCancion.h"
#include "funcionesGlobalesInterprete.h"
#include "opcionesMenu.h"

int main(){
    int opc;

    cout << "\nModificacion 1" << endl;
    cout << "Modificacion 2 "<<endl;
    system("pause");
    while(true){
        menuPrincipal();
        cin >> opc;
        system("cls");
        switch(opc){
            case 1: menuCanciones();
                break;
            case 2: menuInterpretes();
                break;
            case 3:
                break;
            case 4:
                break;
            case 0: return 0;
                break;
            default: cout << "OPCION INCORRECTA" << endl;
                break;
        }
        cout << endl;
        system("pause");
    }
    return 0;
}
