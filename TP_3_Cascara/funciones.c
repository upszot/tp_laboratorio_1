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

int generarPagina_head(char *Archivo,char *temp)
{
    int retorno=-1;
    FILE *pFile;
    FILE *pHead;
    char FHead[50];
    strcpy(FHead,temp);
    strcat(FHead,"index_head");

    pFile=fopen(Archivo,"w");
    pHead=fopen(FHead,"r");

    fseek(pHead, 0L, SEEK_END);
    int tam=ftell(pHead);
    fseek(pHead, 0L, SEEK_SET);

    if(pFile!=NULL && pHead!=NULL)
    {
        retorno=-2;
        char *PBuffer= (char *) malloc (tam + 2);
        while(!feof(pHead))
        {
            if(feof(pHead))
            {//soluciona bug de EOF falso
                break;
            }
            fread(PBuffer,sizeof(char),1,pHead);
            fwrite(PBuffer, sizeof(char), 1, pFile);
            retorno=0;
        }
    }
    fclose(pHead);
    fclose(pFile);
    return retorno;
}

int generarPagina_tail(char *Archivo,char *temp)
{
    int retorno=-1;
    FILE *pFile;
    FILE *pTail;
    char FTail[50];
    strcpy(FTail,temp);
    strcat(FTail,"index_tail");

    pFile=fopen(Archivo,"a");
    pTail=fopen(FTail,"r");

    fseek(pTail, 0L, SEEK_END);
    int tam=ftell(pTail);
    fseek(pTail, 0L, SEEK_SET);

    if(pFile!=NULL && pTail!=NULL)
    {
        retorno=-2;
        char *PBuffer= (char *) malloc (tam + 2);
        while(!feof(pTail))
        {
            if(feof(pTail))
            {//soluciona bug de EOF falso
                break;
            }
            fread(PBuffer,sizeof(char),1,pTail);
            fwrite(PBuffer, sizeof(char), 1, pFile);
            retorno=0;
        }
    }
     fclose(pTail);
     fclose(pFile);
    return retorno;
}

int generarPagina(EMovie lista[], int cant,char *Archivo,char *temp)
{
    int retorno = -1;
    if(cant > 0 && lista != NULL && Archivo!=NULL)
    {
        retorno = -2;
            for(int i=0; i<cant; i++)
            {
                if(lista[i].estado==1)
                {
                    retorno = 0;
                    if(WebAddPelicula(lista[i],Archivo,temp) !=0 )
                    {
                        retorno=-3;
                        break;
                    }
                }
            }//FIN for(int i=0; i<cant; i++)
    }// FIN if(cant > 0 && lista != NULL && archivo!=NULL)
    return retorno;
}

int WebAddPelicula(EMovie record,char *Archivo,char *temp)
{
    int retorno = -1;

    FILE *pFile;
    FILE *pMedio;
    char FMedio[50];
    char linea[100];
    char buffer[2000];
    if(Archivo!=NULL && temp!=NULL)
    {
        retorno = -2;
        strcpy(FMedio,temp);
        strcat(FMedio,"index_Repetir");

        pFile=fopen(Archivo,"a");
        pMedio=fopen(FMedio,"r");

        if(pFile!=NULL && pMedio!=NULL)
        {
            retorno=-3;
            medio(record,buffer);
            fputs(buffer,pFile);
            retorno =0;
            /*
            while(fgets(linea, 100, pMedio) != NULL)
            {
                //printf("Linea: %s",linea);

                //reemplazar
                fputs(buffer,pFile);
                //fwrite(PBuffer, sizeof(char), 1, pFile);
                retorno=0;
            }
            system("pause");
            */


            fclose(pMedio);
            fclose(pFile);
        }//FIN if(pFile!=NULL && pMedio!=NULL)
    }//FIN if(Archivo!=NULL && temp!=NULL)
    return retorno;
}

void medio(EMovie record,char *medio)
{

    strcpy(medio,"			<!-- Repetir esto para cada pelicula -->            <article class='col-md-4 article-intro'>                <a href='#'>                    <img class='img-responsive img-rounded' src='");
    strcat(medio,record.linkImagen);
    strcat(medio,"' alt=''>                </a>                <h3>                    <a href='#'>");
    strcat(medio,record.titulo);
    strcat(medio,"</a>                </h3>				<ul>					<li>Género:");
    strcat(medio,record.genero);
    strcat(medio,"</li>					<li>Puntaje:");
    strcat(medio,record.puntaje);
    strcat(medio,"</li>					<li>Duración:");
    strcat(medio,record.duracion);
    strcat(medio,"%</li>									</ul>                <p>");
    strcat(medio,record.descripcion);
    strcat(medio,"</p>            </article>			<!-- Repetir esto para cada pelicula -->    ");
}
