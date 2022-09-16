#ifndef CLSINTERPRETE_H_INCLUDED
#define CLSINTERPRETE_H_INCLUDED

class Interprete{
    private:
        int idInterprete; // no se repite autonumerico consecutivo
        char nombre[40];
        int nacionalidad; // 1 al 100
        int tipo; // 1 al 5
        int genero; // 1 al 10
        Fecha fechaInicioActividad; // valida anterior o igual a la fecha actual
        bool estado;
    public:
        ///CONSTRUCTOR
        Interprete(int i = 0, const char *n = "sin nombre", int nac = 0, int t = 0, int g = 0, int d = 1, int m = 1, int a = 1900, bool e = false){
            idInterprete = i;
            strcpy(nombre, n);
            nacionalidad = nac;
            tipo = t;
            genero = g;
            fechaInicioActividad.setDia(d);
            fechaInicioActividad.setMes(m);
            fechaInicioActividad.setAnio(a);
            estado = e;
        }
        /// METODOS
        bool Cargar(int idI, Fecha fecha);
        void Mostrar();
        bool LeerDeDisco(int pos);
        bool GrabarEnDisco();

        ///SETS
        void setIdInterprete(int i){idInterprete = i;}
        void setNombre(const char *n){strcpy(nombre, n);}
        bool setNacionalidad(int nac){
            if(nac >= 1 && nac <= 100){
                nacionalidad = nac;
                return true;
            }
            return false;
        }
        bool setTipo(int t){
            if(t >= 1 && t <= 5){
                tipo = t;
                return true;
            }
            return false;
        }
        bool setGenero(int g){
            if(g >= 1 && g <= 10){
                genero = g;
                return true;
            }
            return false;
        }
        void setFechaInicioActividad(Fecha f){fechaInicioActividad = f;}
        void setEstado(bool e){estado = e;}

        ///GETS
        int getIdInterprete(){return idInterprete;}
        const char *getNombre(){return nombre;}
        int getNacionalidad(){return nacionalidad;}
        int getTipo(){return tipo;}
        int getGenero(){return genero;}
        Fecha getFechaInicioActividad(){return fechaInicioActividad;}
        bool getEstado(){return estado;}

        /// DESTRUCTOR
        ~Interprete(){}
};

bool Interprete::Cargar(int idI, Fecha fecha){
    //cout << "ID INTERPRETE: ";
    //cin >> idInterprete;
    setIdInterprete(idI);

    cout << "NOMBRE: ";
    cargarCadena(nombre, 39);
    setNombre(nombre);

    cout << "NACIONALIDAD: ";
    cin >> nacionalidad;
    if(!setNacionalidad(nacionalidad)){
        cout << "NACIONALIDAD DEBE ESTAR ENTRE 1 Y 100" << endl;
        return false;
    }

    cout << "TIPO DE INTERPRETE: ";
    cin >> tipo;
    if(!setTipo(tipo)){
        cout << "TIPO DE INTERPRETE DEBE ESTAR ENTRE 1 Y 5" << endl;
        return false;
    }

    cout << "GENERO MUSICAL PRINCIPAL: ";
    cin >> genero;
    if(!setGenero(genero)){
        cout << "GENERO MUSICAL PRINCIPAL DEBE ESTAR ENTRE 1 Y 10" << endl;
        return false;
    }

    //cout << "FECHA DE INICIO DE ACTIVIDAD: ";
    //fechaInicioActividad.Cargar();
    setFechaInicioActividad(fecha);

    estado = 1;
    setEstado(estado);
    return true;
}

void Interprete::Mostrar(){
    if(estado){
        cout << "ID INTERPRETE: "<< idInterprete << endl;

        cout << "NOMBRE: " << nombre << endl;

        cout << "NACIONALIDAD: " << nacionalidad  << endl;

        cout << "TIPO DE INTERPRETE: " << tipo << endl;

        cout << "GENERO MUSICAL: " << genero << endl;

        cout << "FECHA DE INICIO DE ACTIVIDAD: " << endl;
        fechaInicioActividad.Mostrar();

        cout << "ESTADO: " << estado << endl;
    }
}

bool Interprete::LeerDeDisco(int pos){
    FILE *p;
    p = fopen(INTERPRETES, "rb");
    if(p == NULL){
        return false;
    }
    fseek(p, sizeof(Interprete) * pos, 0);
    bool leyo = fread(this, sizeof(Interprete), 1, p);
    fclose(p);
    return leyo;
}

bool Interprete::GrabarEnDisco(){
    FILE *p;
    p = fopen(INTERPRETES, "ab");
    if(p == NULL){
        return false;
    }
    bool escribio = fwrite(this, sizeof(Interprete), 1, p);
    fclose(p);
    return escribio;
}

#endif // CLSINTERPRETE_H_INCLUDED
