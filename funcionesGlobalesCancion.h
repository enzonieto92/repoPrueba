#ifndef FUNCIONESGLOBALESCANCION_H_INCLUDED
#define FUNCIONESGLOBALESCANCION_H_INCLUDED

/// PROTOTIPOS FUNCIONES GLOBALES CANCION

// bool validarFecha(Fecha f);

int contarRegistrCancion();

Cancion cargarCancion();

int agregarRegistroCancion();

void mostrarCancion();

/// DEFINICIONES FUNCIONES GLOBALES CANCION

// PUNTO 1 AGREGAR CANCION
/*
bool validarFecha(Fecha f){
    /// VALIDACION DE FECHA IGUAL O MENOR A LA ACTUAL
    return true;
}
*/

int contarRegistroCancion(){
    int cant;
    FILE *p;
    p = fopen(CANCIONES, "rb");
    if(p == NULL){
        return 0;
    }
    fseek(p, 0, 2);
    cant = ftell(p)/sizeof(Cancion);
    fclose(p);
    return cant;
}

Cancion cargarCancion(){
    Cancion tema;
    int idC;
    Fecha fecha;
    cout << "INGRESE FECHA DE ESTRENO: " << endl;
    fecha.Cargar();

    if(validarFecha(fecha) == false){
        cout << "LA FECHA INGRESADA ES INVALIDA. DEBER SER MENOR O IGUAL A HOY" << endl;
        tema.setEstado(false);
        return tema;
    }
    idC = contarRegistroCancion() + 1;
    if(idC == 1){
        cout << "FALLO APERTURA DEL ARCHIVO, NO EXISTE O ESTA VACIO" << endl;
    }
    tema.Cargar(idC, fecha);
    return tema;
}

int agregarRegistroCancion(){
    Cancion tema;
    tema = cargarCancion();
    if(tema.getEstado() == false){ /// ERROR EN FECHA o FALLO APERTURA ARCHIVO
        return -1;
    }
    if(tema.GrabarEnDisco()){ /// GRABO EN DISCO
        return 0;
    }
    return -2; /// FALLO GRABAR EN DISCO
}

// PUNTO 2 LISTAR CANCION POR ID
int buscarIdCancion(int idC){
    Cancion tema;
    int pos = 0;
    while(tema.LeerDeDisco(pos)){
        if(idC == tema.getIdCancion()){
            return pos;
        }
        pos++;
    }
    return -1;
}

Cancion leerRegistroCancion(int pos){
    Cancion tema;
    tema.setIdCancion(-1);
    FILE *p;
    p = fopen(CANCIONES,"rb");
    if(p == NULL){
        return tema;
    }
    /// int desplazamiento = pos * sizeof tema;
    /// cantidad de bytes que necesito desplazarme
    /// 0 SEEK_SET DESDE EL PRINCIPIO DEL ARCHIVO
    /// 1 SEEK_CUR DESDE LA POSICION ACTUACL
    /// 2 SEEK_END DESDE LA POSICION FINAL
    fseek(p, pos * sizeof tema, 0);
    fread(&tema, sizeof tema, 1, p);
    fclose(p);
    return tema;
}

bool mostrarCancionPorId(){ /// FILTRA LISTADO POR ID NUMERO DE CANCION
    Cancion tema;
    int idC, pos;
    /// buscar la cancion a mostrar
    cout << "INGRESE EL NUMERO DE IDCANCION DEL REGISTRO A MOSTRAR: ";
    cin >> idC;
    /// leer si existe la cancion
    pos = buscarIdCancion(idC);
    if(pos == -1){
        cout << "NO EXISTE EL IDNUMERO DE CANCION EN EL ARCHIVO" << endl;
        return false;
    }
    tema = leerRegistroCancion(pos);
    /// LISTAR LA CANCION FILTRADA
    tema.Mostrar();
    return true;
}

// PUNTO 3 LISTAR TODAS LAS CANCIONES
void mostrarCancion(){
    Cancion tema;
    int pos = 0;
    while(tema.LeerDeDisco(pos)){
        tema.Mostrar();
        cout << endl;
        pos++;
    }
}

// PUNTO 4 MODIFICAR FECHA DE ESTRENO
bool sobreEscribirRegistroCancion(Cancion tema, int pos){
    FILE *p;
    p = fopen(CANCIONES, "rb+"); ///+ le agrega al modo lo que le falta
    if(p == NULL)return false;
    fseek(p, sizeof tema * pos, 0);
    bool escribio = fwrite(&tema, sizeof tema, 1, p);
    fclose(p);
    return escribio;
}

bool modificarFechaEstrenoCancion(){
    Cancion tema;
    int idC, pos;
    Fecha fecha;
    /// buscar la cancion a modificar fecha de estreno
    cout << "INGRESE EL ID CANCION DEL REGISTRO A MODIFICAR FECHA DE ESTRENO: ";
    cin >> idC;
    /// leer si existe la cancion
    pos = buscarIdCancion(idC);
    if(pos == -1){
        cout << "NO EXISTE EL ID DE CANCION EN EL ARCHIVO" << endl;
        return false;
    }
    tema = leerRegistroCancion(pos);
    /// cambiar la categoria del campo
    cout << "INGRESE LA NUEVA FECHA DE ESTRENO: " << endl;
    fecha.Cargar();
    if(validarFecha(fecha) == false){
        cout << "LA FECHA INGRESADA ES INVALIDA. DEBER SER MENOR O IGUAL A HOY" << endl;
        return false;
    }
    tema.setFechaEstreno(fecha);
    /// sobreescribir el registro
    return sobreEscribirRegistroCancion(tema, pos);
}

// PUNTO 5 ELIMINAR LOGICA CANCION
bool eliminarLogicoCancion(){
    Cancion tema;
    int idC, pos;
    /// buscar el registro a eliminar
    cout << "INGRESE EL ID DE CANCION DEL REGISTRO A DAR DE BAJA: ";
    cin >> idC;
    /// leer si existe el registro
    pos = buscarIdCancion(idC);
    if(pos == -1){
        cout << "NO EXISTE EL ID DE CANCION EN EL ARCHIVO" << endl;
        return false;
    }
    tema = leerRegistroCancion(pos);
    /// cambiar el estado del campo
    tema.setEstado(false);
    /// sobreescribir el registro
    return sobreEscribirRegistroCancion(tema, pos);
}


#endif // FUNCIONESGLOBALESCANCION_H_INCLUDED
