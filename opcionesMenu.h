#ifndef OPCIONESMENU_H_INCLUDED
#define OPCIONESMENU_H_INCLUDED

/// DECLARACION DE MENUS

void menuCanciones();

void menuPrincipal();

/// DEFINICIONES DE MENUS

// MENU CANCIONES
void menuCanciones(){
    int opc, valorAgregarCancion;
    cout << "Modificacion 3" << endl;
    system("pause");
    while(true){
        system("cls");
        cout << "MENU CANCIONES" << endl;
        cout << "-----------------------------" << endl;
        cout << "1) AGREGAR CANCION" << endl;
        cout << "2) LISTAR CANCION POR ID" << endl;
        cout << "3) LISTAR TODAS LAS CANCIONES" << endl;
        cout << "4) MODIFICAR FECHA DE ESTRENO" << endl;
        cout << "5) ELIMINAR CANCION" << endl;
        cout << "-----------------------------" << endl;
        cout << "0) VOLVER MENU PRINCIPAL" << endl;
        cout << "\nSELECCIONES UNA DE LAS OPCIONES: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1: valorAgregarCancion = agregarRegistroCancion();
                    if(valorAgregarCancion == -2){
                        cout << "FALLO GRABAR EN DISCO " << endl;
                        return;
                    }
                    else{
                        if(valorAgregarCancion == -1){
                            cout << "ERROR FECHAS DE ESTRENO O FALLO APERTURA DE ARCHIVO" << endl;
                            return;
                        }
                    }
                    cout << "CANCION CARGADA" << endl;
                break;
            case 2: if(mostrarCancionPorId() == false){
                        cout << "ERROR EN LA BUSQUEDA DE LA CANCION" << endl;
                    }
                    else{
                        cout << "CANCION LISTADA" << endl;
                    }
                break;
            case 3: mostrarCancion();
                break;
            case 4: if(modificarFechaEstrenoCancion() == false){
                        cout << "ERROR EN LA MODIFICACION DEL REGISTRO " << endl;
                    }
                    else{
                        cout << "REGISTRO MODIFICADO" << endl;
                    }
                break;
            case 5: if(eliminarLogicoCancion() == false){
                        cout << "ERROR EN EL BORRADO DEL REGISTRO" << endl;
                    }
                    else{
                        cout << "REGISTRO BORRADO" << endl;
                    }
                break;
            case 0: return;
                break;
            default: cout << "OPCION INCORRECTA" << endl;
                break;
        }
        cout << endl;
        system("pause");
    }
    return;
}

// MENU INTERPRETES
void menuInterpretes(){
    int opc, valorAgregarInterprete;
    while(true){
        system("cls");
        cout << "MENU INTERPRETES" << endl;
        cout << "-----------------------------" << endl;
        cout << "1) AGREGAR INTERPRETE" << endl;
        cout << "2) LISTAR INTERPRETE POR ID" << endl;
        cout << "3) LISTAR TODOS LOS INTERPRETES" << endl;
        cout << "4) MODIFICAR GENERO MUSICAL PRINCIPAL" << endl;
        cout << "5) ELIMINAR INTERPRETE" << endl;
        cout << "-----------------------------" << endl;
        cout << "0) VOLVER MENU PRINCIPAL" << endl;
        cout << "\nSELECCIONES UNA DE LAS OPCIONES: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1: valorAgregarInterprete = agregarRegistroInterprete();
                    if(valorAgregarInterprete== -2){
                        cout << "FALLO GRABAR EN DISCO " << endl;
                        return;
                    }
                    else{
                        if(valorAgregarInterprete == -1){
                            cout << "ERROR FECHAS DE ESTRENO O FALLO APERTURA DE ARCHIVO" << endl;
                            return;
                        }
                    }
                    cout << "INTERPRETE CARGADO" << endl;
                break;
            case 2: if(mostrarInterpretePorId() == false){
                        cout << "ERROR EN LA BUSQUEDA DEL INTERPRETE" << endl;
                    }
                    else{
                        cout << "INTERPRETE LISTADO" << endl;
                    }
                break;
            case 3: mostrarInterprete();
                break;
            case 4: if(modificarGeneroPrincipalInterprete() == false){
                        cout << "ERROR EN LA MODIFICACION DEL REGISTRO " << endl;
                    }
                    else{
                        cout << "REGISTRO MODIFICADO" << endl;
                    }
                break;
            case 5: if(eliminarLogicoInterprete() == false){
                        cout << "ERROR EN EL BORRADO DEL REGISTRO" << endl;
                    }
                    else{
                        cout << "REGISTRO BORRADO" << endl;
                    }
                break;
            case 0: return;
                break;
            default: cout << "OPCION INCORRECTA" << endl;
                break;
        }
        cout << endl;
        system("pause");
    }
    return;
}

/// MENU PRINCIPAL
void menuPrincipal(){
    system("cls");
    cout << "MENU PRINCIPAL" << endl;
    cout << "---------------------" << endl;
    cout << "1) MENU CANCIONES" << endl;
    cout << "2) MENU INTERPRETES" << endl;
    cout << "3) MENU REPORTES" << endl;
    cout << "4) MENU CONFIGURACION" << endl;
    cout << "---------------------" << endl;
    cout << "0) FIN DEL PROGRAMA" << endl;
    cout << "\nSELECCIONES UNA DE LAS OPCIONES: ";
}

#endif // OPCIONESMENU_H_INCLUDED
