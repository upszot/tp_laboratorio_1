#include "funciones.h"
#include "genericas.h"

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

int eGen_siguienteId(EMovie lista[],int cant)
{
    int retorno = 0;
    int Error=-1;
    if(cant > 0 && lista != NULL)
    {
        Error=0;
        for(int i=0; i<cant; i++)
        {
            if(lista[i].estado == 1)
            {
                    if(lista[i].id>retorno)
                    {
                         retorno=lista[i].id;
                    }
            }
        }//FIN for(int i=0; i<limite; i++)
    }
    if(Error==0)
    {
        retorno++;
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
                retorno=Pos_libre;
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

int agregarPelicula(EMovie record,char *Archivo)
{
    int retorno=-1;
    FILE *pFile;

    if(Archivo!=NULL)
    {
        retorno=-2;
        pFile=fopen(Archivo,"ab");
        if(pFile!=NULL)
        {
            retorno=0;
            fwrite(&record,sizeof(EMovie),1,pFile);
            fclose(pFile);
        }//if(pFile!=NULL)
    }//FIN if(Archivo!=NULL)
    return retorno;
}

int ReadFile_CargaPeliculas(EMovie lista[],int cant,char *Archivo)
{
    int retorno=-1;
    int Pos=0;
    int Flag_cant=0;
    FILE *pFile;
    EMovie aux;

    if(Archivo!=NULL && lista!=NULL && cant>0)
    {
        retorno=-2;
        if(inicializaVector(lista,cant)==0)
        {//aca tengo la lista limpia para cargarla con los datos del archivo
            retorno=-3;
            pFile=fopen(Archivo,"rb");
            if(pFile!=NULL)
            {
                retorno=-4;
                fread(&aux,sizeof(EMovie),1,pFile);
                while( !feof(pFile) && Flag_cant==0 )
                {
                    if(feof(pFile))
                    {//soluciona bug de EOF falso
                        break;
                    }
                    if(Pos<cant)
                    {
                        retorno=0;
                        if(aux.estado==1)
                        {
                            lista[Pos]=aux;
                            Pos++;
                        }
                    }
                    else
                    {
                        Flag_cant=1;
                        retorno=-5;
                    }
                    fread(&aux,sizeof(EMovie),1,pFile);
                }//FIN while(!feof(pFile))
                fclose(pFile);
            }//if(pFile!=NULL)
        }//FIN if(inicializaVector(lista,cant)==0)
    }//FIN if(Archivo!=NULL && lista!=NULL && cant>0)
    return retorno;
}

void eGen_mostrarUno(EMovie record)
{
     printf("\n ID: %d  Titulo: %s ", record.id,record.titulo);
     printf("\n\t Genero: %s Duracion: %d Puntaje: %d",record.genero,record.duracion,record.puntaje);
     printf("\n\t Descripcion: %s  ", record.descripcion);
     printf("\n\t Link Imagen: %s  \n", record.linkImagen);
     printf("\n\t Estado: %d  \n", record.estado);
}

int eGen_mostrarPelicula(EMovie lista[],int cant,int paginado)
{
    int retorno = -1;
    int cont=0;
    system("cls");
    if(cant > 0 && lista != NULL)
    {
        retorno = 0;
        for(int i=0; i<cant; i++)
        {
            if(lista[i].estado==1)
            {
                if(cont!=0 && cont %paginado==0)
                {
                    system("pause");
                    system("cls");
                }
                eGen_mostrarUno(lista[i]);
                cont++;
            }
        }
        if(cont!=0)
        {
            system("pause");
        }
    }
    return retorno;
}

int eGen_buscarPorId(EMovie lista[] ,int cant, int ID_Buscado)
{
    int retorno = -1;
    if(cant > 0 && lista != NULL)
    {
        retorno = -2;
        for(int i=0;i<cant;i++)
        {
            if(lista[i].estado == 1 && lista[i].id == ID_Buscado)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int borrarPelicula(EMovie movie,char *Archivo)
{
    EMovie aux;
    FILE *pFile;

    int retorno=-1;
    int pos;
    int Flag_Encontro=0;

    if(Archivo!=NULL)
    {
        retorno=-2;
        pFile=fopen(Archivo,"r+b");
        if(pFile!=NULL)
        {
            retorno=-3;
            while( !feof(pFile) && retorno!=0 )
            {
                if(feof(pFile))
                {//soluciona bug de EOF falso
                    break;
                }
                retorno=-4;
                fread(&aux,sizeof(EMovie),1,pFile);
                pos=ftell(pFile)-sizeof(EMovie);
                if( (aux.id==movie.id) && (Flag_Encontro==0) )
                {//este tengo que borrar
                    fseek(pFile,pos,SEEK_SET);
                    aux.estado=0; //borrado logico
                    fwrite(&aux, sizeof(EMovie), 1, pFile);
                    Flag_Encontro=1;
                    retorno=0;
                }

            }//FIN while(!feof(pFile))
            fclose(pFile);
        }//if(pFile!=NULL)
    }//FIN if(Archivo!=NULL)
    return retorno;
}

int ModificaPelicula(EMovie movie,char *Archivo)
{
    EMovie aux;
    FILE *pFile;
    int retorno=-1;
    int pos;

    if(Archivo!=NULL)
    {
        retorno=-2;
        pFile=fopen(Archivo,"r+b");
        if(pFile!=NULL)
        {
            retorno=-3;
            while( !feof(pFile) && retorno!=0 )
            {
                if(feof(pFile))
                {//soluciona bug de EOF falso
                    break;
                }
                retorno=-4;
                fread(&aux,sizeof(EMovie),1,pFile);
                pos=ftell(pFile)-sizeof(EMovie);
                if(aux.id==movie.id)
                {
                    retorno=0;
                    fseek(pFile,pos,SEEK_SET);
                    printf("\n Reingrese todos los datos de la pelicula: \n");
                    movie=carga_datos_pelicula(movie.id);
                    fwrite(&movie, sizeof(EMovie), 1, pFile);
                }

            }//FIN while( !feof(pFile) && retorno!=0 )
            fclose(pFile);
        }//if(pFile!=NULL)
    }//FIN if(Archivo!=NULL)
    return retorno;
}
