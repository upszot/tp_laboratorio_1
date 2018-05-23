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
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
}EMovie;


/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie lista[], char nombre[]);

#endif // FUNCIONES_H_INCLUDED


/** \brief Inicializa el valor de estado en 0 para indicar que esta libre.
 *         Tambien el id por si se quiere a hacer baja logica
 *
 * \param lista[] EMovie
 * \param tam int
 * \return int
 *
 */
int  inicializaVector(EMovie lista[],int tam);


/** \brief Obtiene el primer indice libre del array.
 * Devuelve un negativo cuando no hay lugar o se produce un error
 *
 * \param lista[] EMovie
 * \param cant int
 * \return int
 *
 */
int obtenerEspacioLibre(EMovie lista[],int cant);


int eGen_siguienteId(EMovie listado[],int limite);
EMovie carga_datos_pelicula(int ID);
int Alta_Pelicula(EMovie lista[],int cant);

void eGen_mostrarUno(EMovie record);
int eGen_mostrarPelicula(EMovie lista[],int cant,int paginado);
