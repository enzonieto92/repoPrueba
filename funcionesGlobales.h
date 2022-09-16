#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED

/// PROTOTIPOS FUNCIONES GLOBALES

void cargarCadena(char *pal, int tam);  /// CARGA CADENAS DE CARACTERES

/// DEFINICION FUNCIONES GLOBALES

void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i = 0; i < tam; i++){
      pal[i] = cin.get();
	  if(pal[i] == '\n') break;
	  }
  pal[i] = '\0';
  fflush(stdin);
}

#endif // FUNCIONESGLOBALES_H_INCLUDED
