#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
#define T 1000
#define VACIO 1
#define OCUPADO 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Input.h"

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}eEmployee;


int menu();

int menuListar();
/*
*
*\brief Incializa el listado en Vacio
*\param tam, El tamaño del array
*\return Retorna el si se pudo hacer o no
*
*/
int initEmployees(eEmployee listado[], int tam);
/*
*
*\brief Busca un espacio libre en el array
*\param tam, El tamaño del array
*\return Retorna el si se pudo hacer o no
*
*/
int searchFree(eEmployee listado[], int tam);
/*
*
*\brief Busca un espacio libre en el array y carga un empleado en la lista
*\param tam, El tamaño del array
*\return Retorna el si se pudo hacer o no
*
*/
int addEmployee(eEmployee listado[], int tam,int legajo);
/*
*
*\brief Pide los datos del empleado
*\return Retorna el empleado
*
*/
eEmployee askEmployee ();
/*
*
*\brief Elimina un empleado
*\param tam, El tamaño del array
*\param id, El id del empleado a borrar
*\return Retorna el si se pudo hacer o no
*
*/
int removeEmployee (eEmployee listado[], int tam, int id);
/*
*
*\brief Muestra todos los empleados
*\param tam, El tamaño del array
*
*/
void showAllEmployees(eEmployee listado[], int tam);
/*
*
*\brief Muestra un empleado
*\param tam, El tamaño del array
*
*/
void showEmployee (eEmployee miEmployee);
/*
*
*\brief Ordena los empleados por nombre y por sector
*\param tam, El tamaño del array
*
*/
void sortEmployeeByNameAndSector(eEmployee listado[], int tam);
/*
*
*\brief Muestra el total de salarios, el promedio y los empleados que superan ese promedio
*\param tam, El tamaño del array
*
*/
void salary(eEmployee listado[], int tam);
/*
*
*\brief Modifica un empleado
*\param tam, El tamaño del array
*\param id, El id del empleado a modificar
*\return Retorna el si se pudo hacer o no
*
*/
int ModificarUnEmployee(eEmployee listado[], int tam, int id);


#endif // EMPLOYEE_H_INCLUDED
