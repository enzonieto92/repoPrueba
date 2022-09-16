#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED

class Fecha{
    private:
        int dia;
        int mes;
        int anio;

    public:
        /// CONSTRUCTOR
        Fecha(int d = 1, int m = 1, int a = 1900){
            dia = d;
            mes = m;
            anio = a;
        }

        /// METODOS
        void Cargar();
        void Mostrar();

        /// SETS
        void setDia(int d){dia = d;}
        void setMes(int m){mes = m;}
        void setAnio(int a){anio = a;}

        /// GEST
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
};

void Fecha::Cargar(){
    int d, m, a;

    cout << "DIA: ";
    cin >> d;
    cout << "MES: ";
    cin >> m;
    cout << "ANIO: ";
    cin >> a;
    /// falta validar fecha
    setDia(d);
    setMes(m);
    setAnio(a);
}

void Fecha::Mostrar(){
    cout << getDia() << "/" << getMes() << "/" << getAnio() << endl;
}

/// PROTOTIPO VALIDAR FECHA
bool validarFecha(Fecha f);

/// DEFINICION VALIDAR FECHA
bool validarFecha(Fecha f){
    /// VALIDACION DE FECHA IGUAL O MENOR A LA ACTUAL
    return true;
}

#endif // CLSFECHA_H_INCLUDED
