#include <stdio.h>
#include <stdlib.h>
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
                    break;
                case 2:
                    break;
                case 3://Modifica pelicula
                    Error=eGen_mostrarPelicula(peliculas,TAMPelis,get_int_Rango("Ingrese cantidad de peliculas a mostrar en una pantalla; (Maximo 20) ",1,20));
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
