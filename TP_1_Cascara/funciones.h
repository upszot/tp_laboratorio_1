#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



/** \brief suma de dos numeros
 *
 * \param Nro1 float
 * \param Nro2 float
 * \return float
 *
 */
float suma(float Nro1,float Nro2);

/** \brief Resta de 2 numeros
 *
 * \param Nro1 float
 * \param Nro2 float
 * \return float
 *
 */
float resta(float Nro1,float Nro2);

/** \brief Multiplica dos numeros
 *
 * \param Nro1 float
 * \param Nro2 float
 * \return float
 *
 */
float multiplicacion(float Nro1,float Nro2);

/** \brief divide dos numeros
 *
 * \param Nro1 float
 * \param Nro2 float
 * \return float
 *
 */
float divicion(float Nro1,float Nro2);

/** \brief Calcula el factorial de un numero enterio positivo
 *
 * \param numero int
 * \return int
 *
 */
int factorialRecursivo(int numero);

/** \brief Realiza validacion de un numero para que sea entero y positivo
 *         si es negatigo o tiene parte flotante devuelve -1
 *         Sino castea el numero de flotante a entero y devuelve el numero entero.
 *         La funcion es usada como entrada de la funcion que realiza el calculo de factorial de un nro entero.
 *
 * \param Nro float
 * \return int
 *
 */
int valida_factorial(float Nro);

/** \brief Imprime por pantalla el menu de opciones.
 *
 * \param A float
 * \param B float
 * \param FlagAB[2] int
 * \return void
 *
 */
void ImprimeMenu(float A,float B, int FlagAB[2]);

/** \brief Funcion para ingresar valores flotantes.
 *
 * \param Numero float*
 * \return void
 *
 */
void PideValor(float *Numero);

/** \brief valida que un numero sea distinto de 0, devuelve 1 si es igual a 0
 *
 * \param Nro float
 * \return int
 *
 */
int validaDivicion(float Nro);

/** \brief Imprime un cartel en pantalla con pausa y presione tecla para continuar..
 *
 * \return void
 *
 */
void pause();


/** \brief Usada para Mostrar por pantalla distintos carteles de error segun el parametro enviado.
 *
 * \param mensaje char
 * \return void
 *
 */
void sms_error(char mensaje);

#endif // FUNCIONES_H_INCLUDED
