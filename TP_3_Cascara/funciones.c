#include "funciones.h"

int  inicializaVector(EMovie lista[],int tam)
{
    int retorno=-1;
    if(tam>0 && lista!=NULL)
    {
        retorno=0;
        for(int i=0; i<tam ;i++)
        {
            lista[i].estado=0;
            lista[i].id=0;
        }//fin for(int i=0; i<tam ;i++)
    }
    return retorno;
}

int obtenerEspacioLibre(EMovie lista[],int cant)
{
    int retorno=-1;//pq no es un valor valido para el subindice de un vector
    if(cant>0&&lista!=NULL)
    {
        retorno=-2;
        for(int i=0; i<cant ;i++)
        {
            if(lista[i].estado==0)
            {//Esta libre
                retorno=i;
                break;
            }
        }//for(int i=0; i<cant ;i++)
    }//fin if(cant>0&&lista!=NULL)
    return retorno;
}

int eGen_siguienteId(EMovie listado[],int limite)
{
    int retorno = 0;
    int Error=-1;
    if(limite > 0 && listado != NULL)
    {
        Error=0;
        for(int i=0; i<limite; i++)
        {
            if(listado[i].estado == 1)
            {
                    if(listado[i].id>retorno)
                    {
                         retorno=listado[i].id;
                    }
            }
        }//FIN for(int i=0; i<limite; i++)
    }
    if(Error==0)
    {
        retorno+1;
    }
    else
    {
        retorno=Error;
    }
    return retorno;
}

EMovie carga_datos_pelicula(int ID)
{
    EMovie record;
    system("cls");
    printf("\n----- Cargue los datos de la Pelicula -----\n\n");
    record.id=ID;
    strcpy(record.titulo,get_char("\n Titulo: ",20));
    strcpy(record.genero,get_char("\n Genero: ",20));
    record.duracion=get_int_Rango("\n Duracion (minutos): ",1,240);
    record.puntaje=get_int_Rango("\n Puntaje: ",1,10);
    strcpy(record.descripcion,get_char("\n Descripcion: ",50));
    strcpy(record.linkImagen,get_char("\n Link Imagen: ",50));
    record.estado=1;

    return record;
}

int Alta_Pelicula(EMovie lista[],int cant)
{
    int retorno=-1;
    int Pos_libre;
    int NextID;
    if(cant>0&&lista!=NULL)
    {
        retorno=-2;
        Pos_libre= obtenerEspacioLibre(lista,cant);
        if(Pos_libre>=0)
        {//Encontre una posicion libre
            retorno=-3;
            NextID=eGen_siguienteId(lista,cant);
            if(NextID >0 )
            {
                retorno=0;
                lista[Pos_libre]=carga_datos_pelicula(NextID);
            }

        }
        else
        {
            printf("\n No hay espacio libre..");
        }
    }//if(cant>0&&lista!=NULL)
    return retorno;
}


