#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "genericas.h"

#define TAMPelis 10

int main()
{
    char seguir='s';
    int opcion=0;
    int Error=-9;
    EMovie peliculas[TAMPelis];
    Error=inicializaVector(peliculas,TAMPelis);

    char Archivo[20]="Peliculas.txt";
    char web[20]="Web\\hola.txt";
    char Path_Template[20]="Temp_Web\\";

    if(Error==0)
    {
        do
        {
            menu(   "\n 1. AGREGAR PELICULA"
                    "\n 2. BORRAR PELICULA"
                    "\n 3. MODIFICAR PELICULA"
                    "\n 4. GENERAR PAGINA WEB"
                    "\n 5. Re-Lee Archivo - Muestra peliculas"
                );

            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1://AGREGAR PELICULA
                    Error=Alta_Pelicula(peliculas,TAMPelis);
                    if(Error>=0)
                    {//Añado la pelicula al archivo
                        Error=agregarPelicula(peliculas[Error],Archivo);
                        if(Error!=0)
                        {
                            Error=Error*10;
                        }
                    }
                    break;
                case 2://BORRAR PELICULA
                    Error=ReadFile_CargaPeliculas(peliculas,TAMPelis,Archivo);
                    if(Error==0)
                    {//mostrar para despues borrar
                        Error=eGen_mostrarPelicula(peliculas,TAMPelis,get_int_Rango("Ingrese cada cuanto quiere paginar le muestra: ",1,10));
                        if(Error==0)
                        {//pido que elija la pelicula a borrar por el ID
                            Error=eGen_buscarPorId(peliculas,TAMPelis,get_int_Rango("Ingrese el ID de la pelicula a borrar: ",1,32767));
                            if(Error>=0)
                            {// aca se la posicion de la pelicula a borrar
                             //poodria ir directamente a esa posicion en el archivo y borrarla...
                             //pero para respetar el encabezado de la funcion de la carcasa...realizo la busqueda sobre el archivo..
                                Error=borrarPelicula(peliculas[Error],Archivo);
                            }
                            else
                            {
                                Error=Error*100;
                            }
                        }
                        else
                        {
                            Error=Error*10;
                        }//fin if(Error==0) mostrar pelicula
                    }//fin if(Error==0) Por lectura archivo
                    break;
                case 3://MODIFICAR PELICULA
                    Error=ReadFile_CargaPeliculas(peliculas,TAMPelis,Archivo);
                    if(Error==0)
                    {//mostrar
                        Error=eGen_mostrarPelicula(peliculas,TAMPelis,get_int_Rango("Ingrese cada cuanto quiere paginar le muestra: ",1,10));
                        if(Error==0)
                        {//pido que elija la pelicula a modificar por el ID
                            Error=eGen_buscarPorId(peliculas,TAMPelis,get_int_Rango("Ingrese el ID de la pelicula a Modificar: ",1,32767));
                            if(Error>=0)
                            {
                                Error=ModificaPelicula(peliculas[Error],Archivo);
                            }
                            else
                            {
                                Error=Error*100;
                            }
                        }
                        else
                        {
                            Error=Error*10;
                        }//fin if(Error==0) mostrar pelicula
                    }//fin if(Error==0) Por lectura archivo

                    break;
                case 4://GENERAR PAGINA WEB
                    Error=ReadFile_CargaPeliculas(peliculas,TAMPelis,Archivo);
                    if(Error==0)
                    {
                        Error=generarPagina_head(web,Path_Template);
                        if(Error==0)
                        {
                            Error=generarPagina(peliculas,TAMPelis,web,Path_Template);
                            if(Error==0)
                            {
                                Error=generarPagina_tail(web,Path_Template);
                                if(Error!=0)
                                {
                                    Error=Error*1000;
                                }//FIN ERROR AGREGADO TAIL
                            }
                            else
                            {
                                Error=Error*100;
                            }//FIN ERROR PARTE DEL MEDIO
                        }
                        else
                        {
                            Error=Error*10;
                        }//FIN ERROR AGREGADO HEAD
                    }//FIN ERROR recarga vector
                    break;
                case 5://Muestra peliculas
                    Error=ReadFile_CargaPeliculas(peliculas,TAMPelis,Archivo);
                    if(Error==0)
                    {//muestro peliculas
                        Error=eGen_mostrarPelicula(peliculas,TAMPelis,5);
                        if(Error!=0)
                        {
                            Error=Error*10;
                        }//fin if(Error==0) mostrar pelicula
                    }//fin if(Error==0) Por lectura archivo
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
