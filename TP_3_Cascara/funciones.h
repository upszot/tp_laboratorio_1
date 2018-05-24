#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int id;
    int estado;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[250];
    int puntaje;
    char linkImagen[70];
}EMovie;


/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna  0 d si pudo agregar la pelicula o numeros negativos si hubo un error
 */
int agregarPelicula(EMovie record,char *Archivo); //OK

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 0 si pudo eliminar la pelicula o numeros negativos si hubo un error
 */
int borrarPelicula(EMovie movie,char *Archivo); //OK

/** \brief   Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *
 * \param lista[] EMovie lista de peliculas a ser agregadas en el archivo.
 * \param cant int longitud del vector de lista
 * \param Archivo char*  el nombre para el archivo.
 * \return (int) retorna 0 NO hubo Error o Valores negativos si Hubo Error,
 *
 */
int generarPagina(EMovie lista[], int cant,char *Archivo,char *temp);

#endif // FUNCIONES_H_INCLUDED

/** \brief Inicializa el valor de estado en 0 para indicar que esta libre.
 *         Tambien el id por si se quiere a hacer baja logica
 *
 * \param lista[] EMovie
 * \param tam int
 * \return (int) retorna 0 NO hubo Error o Valores negativos si Hubo Error,
 *
 */
int  inicializaVector(EMovie lista[],int tam);  //OK

/** \brief Obtiene el primer indice libre del array.
 * Devuelve un negativo cuando no hay lugar o se produce un error
 *
 * \param lista[] EMovie
 * \param cant int
 * \return (int) retorna Posision del proximo espacio libre en el vector o Valores negativos si Hubo Error,
 *
 */
int obtenerEspacioLibre(EMovie lista[],int cant);   //OK

/** \brief Obtiene el siguiente Nro de ID
 *
 * \param lista[] EMovie
 * \param cant int
 * \return (int) retorna valor positivo con el siguiente nro de id o Valores negativos si Hubo Error,
 *
 */
int eGen_siguienteId(EMovie lista[],int cant);      //OK

/** \brief pide datos de pelicula, y devuelve una estructura del tipo emovie con los datos cargados
 *
 * \param ID int
 * \return EMovie
 *
 */
EMovie carga_datos_pelicula(int ID);                //OK

/** \brief Agrega 1 pelicula al vector de peliculas (llama a carga_datos_pelicula para el ingreso de los datos)
 *
 * \param lista[] EMovie
 * \param cant int
 * \return (int) retorna 0 NO hubo Error o Valores negativos si Hubo Error,
 *
 */
int Alta_Pelicula(EMovie lista[],int cant);         //OK

/** \brief Lee un archivo y recarga el listado de peliculas pisando lo que tenia antes el listado
 *
 * \param lista[] EMovie
 * \param cant int
 * \param Archivo char*
 * \return (int) retorna 0 NO hubo Error o Valores negativos si Hubo Error,
 *
 */
int ReadFile_CargaPeliculas(EMovie lista[],int cant,char *Archivo);     //OK

/** \brief Muestra por pantalla datos de 1 sola pelicula
 *
 * \param record EMovie
 * \return void
 *
 */
void eGen_mostrarUno(EMovie record);    //OK

/** \brief Recorre el vector de peliculas llamando a "eGen_mostrarUno" para visualizar todas las peliculas
 *
 * \param lista[] EMovie
 * \param cant int
 * \param paginado int
 * \return (int) retorna 0 NO hubo Error o Valores negativos si Hubo Error,
 *
 */
int eGen_mostrarPelicula(EMovie lista[],int cant,int paginado); //OK

/** \brief Busca en el listado el ID y retorna la posision donde se encontro
 *
 * \param lista[] EMovie
 * \param cant int
 * \param ID_Buscado int
 * \return (int) retorna Nro de posicion donde se enncontro el ID o Valores negativos si Hubo Error,
 *
 */
int eGen_buscarPorId(EMovie lista[] ,int cant, int ID_Buscado); //OK

/** \brief Modifica todos los datos (menos el ID) de una pelicula e impacta el cambio en el archivo
 *
 * \param movie EMovie
 * \param Archivo char*
 * \return (int) retorna 0 NO hubo Error o Valores negativos si Hubo Error,
 *
 */
int ModificaPelicula(EMovie movie,char *Archivo);       //OK


/** \brief Agrega cabezera al la pagina web
 *
 * \param Archivo char*
 * \param temp char*
 * \return int
 *
 */
int generarPagina_head(char *Archivo,char *temp);

/** \brief Agrega la ultima parte a la pagina web
 *
 * \param Archivo char*
 * \param temp char*
 * \return int
 *
 */
int generarPagina_tail(char *Archivo,char *temp);

/** \brief Realiza una subtitucion de separadores por los datos concretos de las peliculas,
 *
 * \param linea char*
 * \param record EMovie
 * \return char*
 *
 */
char *reemplaza_substring(char *linea,EMovie record);

/** \brief realiza la logica del agregado en la web 1 pelicula... llama a "reemplaza_substring" para modificar el texto del template
 *
 * \param record EMovie
 * \param Archivo char*
 * \param temp char*
 * \return int
 *
 */
int WebAddPelicula(EMovie record,char *Archivo,char *temp);
