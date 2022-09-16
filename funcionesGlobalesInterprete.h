#ifndef FUNCIONESGLOBALESINTERPRETE_H_INCLUDED
#define FUNCIONESGLOBALESINTERPRETE_H_INCLUDED

/// PROTOTIPOS FUNCIONES GLOBALES INTERPRETE

// bool validarFecha(Fecha f);

int contarRegistrInterprete();

Interprete cargarInterprete();

int agregarRegistroInterprete();

void mostrarInterprete();

/// DEFINICIONES FUNCIONES GLOBALES INTERPRETE

// PUNTO 1 AGREGAR INTERPRETE
/*
bool validarFecha(Fecha f){
    /// VALIDACION DE FECHA IGUAL O MENOR A LA ACTUAL
    return true;
}
*/

int contarRegistroInterprete(){
    int cant;
    FILE *p;
    p = fopen(INTERPRETES, "rb");
    if(p == NULL){
        return 0;
    }
    fseek(p, 0, 2);
    cant = ftell(p)/sizeof(Interprete);
    fclose(p);
    return cant;
}

Interprete cargarInterprete(){
    Interprete cantor;
    int idI;
    Fecha fecha;
    cout << "INGRESE FECHA DE INICIO DE ACTIVIDAD: " << endl;
    fecha.Cargar();

    if(validarFecha(fecha) == false){
        cout << "LA FECHA INGRESADA ES INVALIDA. DEBER SER MENOR O IGUAL A HOY" << endl;
        cantor.setEstado(false);
        return cantor;
    }
    idI = contarRegistroInterprete() + 1;
    if(idI == 1){
        cout << "FALLO APERTURA DEL ARCHIVO, NO EXISTE O ESTA VACIO" << endl;
    }
    cantor.Cargar(idI, fecha);
    return cantor;
}

int agregarRegistroInterprete(){
    Interprete cantor;
    cantor = cargarInterprete();
    if(cantor.getEstado() == false){ /// ERROR EN FECHA o FALLO APERTURA ARCHIVO
        return -1;
    }
    if(cantor.GrabarEnDisco()){ /// GRABO EN DISCO
        return 0;
    }
    return -2; /// FALLO GRABAR EN DISCO
}

// PUNTO 2 LISTAR INTERPRETE POR ID
int buscarIdInterprete(int idI){
    Interprete cantor;
    int pos = 0;
    while(cantor.LeerDeDisco(pos)){
        if(idI == cantor.getIdInterprete()){
            return pos;
        }
        pos++;
    }
    return -1;
}

Interprete leerRegistroInterprete(int pos){
    Interprete cantor;
    cantor.setIdInterprete(-1);
    FILE *p;
    p = fopen(INTERPRETES,"rb");
    if(p == NULL){
        return cantor;
    }
    /// int desplazamiento = pos * sizeof tema;
    /// cantidad de bytes que necesito desplazarme
    /// 0 SEEK_SET DESDE EL PRINCIPIO DEL ARCHIVO
    /// 1 SEEK_CUR DESDE LA POSICION ACTUACL
    /// 2 SEEK_END DESDE LA POSICION FINAL
    fseek(p, pos * sizeof cantor, 0);
    fread(&cantor, sizeof cantor, 1, p);
    fclose(p);
    return cantor;
}

bool mostrarInterpretePorId(){ /// FILTRA LISTADO POR ID NUMERO DE INTERPRETE
    Interprete cantor;
    int idI, pos;
    /// buscar el interprete a mostrar
    cout << "INGRESE EL NUMERO DE ID INTERPRETE DEL REGISTRO A MOSTRAR: ";
    cin >> idI;
    /// leer si existe el interprete
    pos = buscarIdInterprete(idI);
    if(pos == -1){
        cout << "NO EXISTE EL ID NUMERO DE INTERPRETE EN EL ARCHIVO" << endl;
        return false;
    }
    cantor = leerRegistroInterprete(pos);
    /// LISTAR EL INTERPRETE FILTRADO
    cantor.Mostrar();
    return true;
}

// PUNTO 3 LISTAR TODOS LOS INTERPRETES
void mostrarInterprete(){
    Interprete cantor;
    int pos = 0;
    while(cantor.LeerDeDisco(pos)){
        cantor.Mostrar();
        cout << endl;
        pos++;
    }
}

// PUNTO 4 MODIFICAR GENERO MUSICAL PRINCIPAL
bool sobreEscribirRegistroInterprete(Interprete cantor, int pos){
    FILE *p;
    p = fopen(INTERPRETES, "rb+"); ///+ le agrega al modo lo que le falta
    if(p == NULL)return false;
    fseek(p, sizeof cantor * pos, 0);
    bool escribio = fwrite(&cantor, sizeof cantor, 1, p);
    fclose(p);
    return escribio;
}

bool modificarGeneroPrincipalInterprete(){
    Interprete cantor;
    int idI, pos;
    Fecha fecha;
    /// buscar la cancion a modificar fecha de estreno
    cout << "INGRESE EL ID INTERPRETE DEL REGISTRO A MODIFICAR FECHA DE INICIO DE ACTIVIDAD: ";
    cin >> idI;
    /// leer si existe la cancion
    pos = buscarIdInterprete(idI);
    if(pos == -1){
        cout << "NO EXISTE EL ID DE INTERPRETE EN EL ARCHIVO" << endl;
        return false;
    }
    cantor = leerRegistroInterprete(pos);
    /// cambiar la fecha del campo
    cout << "INGRESE LA NUEVA FECHA DE INICIO DE ACTIVIDAD: " << endl;
    fecha.Cargar();
    if(validarFecha(fecha) == false){
        cout << "LA FECHA INGRESADA ES INVALIDA. DEBER SER MENOR O IGUAL A HOY" << endl;
        return false;
    }
    cantor.setFechaInicioActividad(fecha);
    /// sobreescribir el registro
    return sobreEscribirRegistroInterprete(cantor, pos);
}

// PUNTO 5 ELIMINAR LOGICA INTERPRETE
bool eliminarLogicoInterprete(){
    Interprete cantor;
    int idI, pos;
    /// buscar el registro a eliminar
    cout << "INGRESE EL ID DE INTERPRETE DEL REGISTRO A DAR DE BAJA: ";
    cin >> idI;
    /// leer si existe el registro
    pos = buscarIdInterprete(idI);
    if(pos == -1){
        cout << "NO EXISTE EL ID DE INTERPRETE EN EL ARCHIVO" << endl;
        return false;
    }
    cantor = leerRegistroInterprete(pos);
    /// cambiar el estado del campo
    cantor.setEstado(false);
    /// sobreescribir el registro
    return sobreEscribirRegistroInterprete(cantor, pos);
}

#endif // FUNCIONESGLOBALESINTERPRETE_H_INCLUDED
