#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "genericas.h"

#define TAMPelis 3

int main()
{
    char seguir='s';
    int opcion=0;
    int Error=-9;
    EMovie peliculas[TAMPelis];
    Error=inicializaVector(peliculas,TAMPelis);

    char Archivo[20]="Peliculas.txt";
    //strcpy(Archivo,"Peliculas.txt");

    if(Error==0)
    {
        do
        {
            menu(   "\n 1. AGREGAR PELICULA"
                    "\n 2. BORRAR PELICULA"
                    "\n 3. MODIFICAR PELICULA"
                    "\n 4. GENERAR PAGINA WEB"
                );

            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1://AGREGAR PELICULA
                    Error=Alta_Pelicula(peliculas,TAMPelis);
                    if(Error>=0)
                    {//Añado la pelicula al archivo
                        Error=agregarPelicula(peliculas[Error],Archivo);
                    }
                    break;
                case 2://BORRAR PELICULA
                    Error=ReadFile_CargaPeliculas(peliculas,TAMPelis,Archivo);
                    if(Error==0)
                    {//mostrar para despues borrar

                    }
                    break;
                case 3://MODIFICAR PELICULA
                    break;
                case 4://GENERAR PAGINA WEB
                    break;
                case 0:
                    seguir = 'n';
                    Error=0;
                    break;
                default:
                    Error=-1;
                    opcion=-2;
                    break;
            }//FIN switch(opcion)
            if(Error!=0)
            {
                sms_error(opcion,Error);
                Error=0;
            }
        }while(seguir=='s');
    }
    else
    {
        sms_error(-1,Error);
    }//FIN if(Error==0)

    return Error;
}//int main()
