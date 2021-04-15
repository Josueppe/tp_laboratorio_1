#include <stdio.h>
#include <stdlib.h>

/** \brief Muestra el menu, ambos operandos y retorna el resultado de la opcion elegida
	 *
	 * \param A primer operando
	 * \param B segundo operando
	 * \return float Opcion elegida del menu por el usuario
	 *
	 */
int menu(int A, int B);


/** \brief Suma dos operandos
	 *
	 * \param A primer operando
	 * \param B segundo operando
	 * \return float Resultado de la operacion
	 *
	 */
float sumar(float A,float B);


/** \brief Resta dos operandos
	 *
	 * \param A primer operando
	 * \param B segundo operando
	 * \return float Resultado de la operacion
	 *
	 */
float restar(float A,float B);


/** \brief Multiplica dos operandos
	 *
	 * \param A primer operando
	 * \param B segundo operando
	 * \return float Resultado de la operacion
	 *
	 */
float multiplicar(float A,float B);


/** \brief Divide dos operandos
	 *
	 * \param A primer operando
	 * \param B segundo operando
	 * \param flagdivision Flag para saber si B es igual a 0
	 * \return float Resultado de la operacion
	 *
	 */
float dividir(float A, float B, int* flagdivision);


/** \brief Factorea un numero
	 *
	 * \param A primer operando
	 * \return float Resultado de la operacion
	 *
	 */
float factorear(float num);

/** \brief Pide que ingrese un numero y lo guarda
	 *
	 * \return float Retorna el numero ingresado
	 *
	 */
float pedirnum();
