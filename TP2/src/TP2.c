#include <stdio.h>
#include <stdlib.h>
#define T 1000
#define VACIO 1
#define OCUPADO 0
#include "Employee.h"


int main()
{
	setbuf(stdout, NULL);

int opcion;
int flag=0;
int legajo=0;
int id;



eEmployee listado[T];
initEmployees(listado,T);


do{
        opcion=menu();

    switch(opcion)
    {
    case 1:

    legajo++;
    addEmployee(listado, T, legajo);
    flag=1;

    break;
    case 2:
     if(flag)
       {

     id=GetInt("Ingrese legajo del empleado a modificar: ", T, 0, "Error, ingrese un legajo valido: " );
     ModificarUnEmployee(listado,T,id);
        }else
        {
        printf("No se cargo primeramente un empleado \n");
        }

    break;
    case 3:
        if(flag)
        {

     id=GetInt("Ingrese legajo del empleado a eliminar: ", T, 0, "Error, ingrese un legajo valido: " );
           removeEmployee ( listado,T,id);


        }else
        {
        printf("No se cargo primeramente un empleado\n");
        }

    break;
    case 4:

    opcion=menuListar();
    switch(opcion)
    {

    case 1:

        if(flag)
        {
           sortEmployeeByNameAndSector(listado,T);
           showAllEmployees(listado, T);
        }
        else
        {
        printf("No se cargo primeramente un empleado\n");
        }
        break;

    case 2:
         if(flag)
        {
        salary(listado,T);
        }
        else
        {
        printf("No se cargo primeramente un empleado\n");
        }
        break;
    }

    break;






    }

}while(opcion!=5);






    return 0;
}
