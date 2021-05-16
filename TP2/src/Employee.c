#include "Employee.h"


int menu()
{
  int opcion;
  GetChar ("*****MENU*****\n");
  GetChar ("1. ALTA\n");
  GetChar ("2. MODIFICACION\n");
  GetChar ("3. BAJA\n");
  GetChar ("4. MENU LISTAR\n");
  GetChar ("5. SALIR\n");
  GetChar ("**************\n");
  opcion = GetInt ("Elija una opcion:", 5, 0, "Elija una opcion valida: ");

  return opcion;
}

int menuListar()
{
  int opcion;
  GetChar ("*****MENU LISTAR*****\n");
  GetChar ("1. EMPLEADOS ORDENADOS POR APELLIDO Y SECTOR\n");
  GetChar ("2. TOTAL PROMEDIO SALARIOS\n");
  GetChar ("**************\n");
  opcion = GetInt ("Elija una opcion:", 2, 0, "Elija una opcion valida: ");

  return opcion;
}



int initEmployees(eEmployee listado[], int tam)
{
  int i;
  int ok=0;
  if (listado != NULL)
    {
      for (i = 0; i < tam; i++)
	{
	  listado[i].isEmpty = VACIO;
	}
	ok=1;
    }
    return ok;
}


int searchFree(eEmployee listado[], int tam)
{
  int i;
  int index;
  index = -1;
  if (listado != NULL)
    {
      for (i = 0; i < tam; i++)
	{
	  if (listado[i].isEmpty == VACIO)
	    {
	      index = i;
	      break;
	    }
	}
    }
  return index;
}


int addEmployee(eEmployee listado[], int tam,int legajo)
{
  int index;
  index = searchFree (listado,tam);

  if (index != -1)
    {
      listado[index] = askEmployee();
      listado[index].id = legajo;
    }


  return index;
}



eEmployee askEmployee ()
{
  eEmployee miEmployee;

    printf ("Ingrese nombre del empleado: ");
  fflush (stdin);
  scanf ("%s", miEmployee.name);

  printf ("Ingrese apellido del empleado: ");
  fflush (stdin);
  scanf ("%s", miEmployee.lastName);


  miEmployee.salary= GetFloat ("Ingrese el salario: ", 50000, 0, "El salario debe estar entre 0 y 50000: " );
  miEmployee.sector= GetInt ("Ingrese el sector: ", 5, 1, "Error, los sectores son 1, 2, 3, 4 y 5: ");



  miEmployee.isEmpty = OCUPADO;

  return miEmployee;
}


int removeEmployee (eEmployee listado[], int tam, int id)
{
  if (listado != NULL)
    {
      int i;
      for (i = 0; i < tam; i++)
	{
	  if (listado[i].id == id)
	    {
	      listado[i].isEmpty = VACIO;
	      return 1;
	    }
	}

    }
  return 0;
}




void showAllEmployees(eEmployee listado[], int tam)
{
  int i;
  if (listado != NULL)
    {
      GetChar ("ID:    NOMBRE:   APELLIDO:    SALARIO:     SECTOR:\n");

      for (i = 0; i < tam; i++)
	 {
			  if (listado[i].isEmpty == OCUPADO)
			    {
			      showEmployee(listado[i]);
			    }
	 }
    }
}



void showEmployee (eEmployee miEmployee)
{
  printf ("%d %10s %10s %10.2f %15d\n", miEmployee.id,miEmployee.name, miEmployee.lastName, miEmployee.salary, miEmployee.sector);
}

void sortEmployeeByNameAndSector(eEmployee listado[], int tam)
{
  int i;
  int j;
  eEmployee auxiliar;
  if (listado != NULL)
    {
      for (i = 0; i < tam - 1; i++)
	{
	  for (j = i + 1; j < tam; j++)
	    {

	      if (strcmp (listado[i].lastName, listado[j].lastName) > 0)
		   {
		  auxiliar = listado[i];
		  listado[i] = listado[j];
		  listado[j] = auxiliar;
		    }
           if(strcmp (listado[i].lastName, listado[j].lastName)==0)
           {
               if(listado[i].sector==listado[j].sector)
               {
          auxiliar = listado[i];
		  listado[i] = listado[j];
		  listado[j] = auxiliar;
               }
           }
	    }
	}
    }
}

void salary(eEmployee listado[], int tam)
{
    int i;
    int j;
    int contSalaryEmployees=0;
    int contEmployees=0;
    float acumEmployees=0;
    float promedio;

    for(i=0; i<tam; i++)
    {
        if(listado[i].isEmpty==OCUPADO)
        {
            acumEmployees=acumEmployees+listado[i].salary;
            contEmployees++;
        }
    }

    promedio=(float)acumEmployees/contEmployees;

    for(j=0; j<tam; j++)
    {
        if(listado[j].salary>promedio&&listado[j].isEmpty==OCUPADO)
        {
            contSalaryEmployees++;
        }
    }
        printf("\nTotal de salarios: %.2f\n",acumEmployees);
        printf("\nPromedio de salarios: %.2f\n",promedio);
        printf("\nTotal empleados que superan el promedio de salario: %d\n\n",contSalaryEmployees);

}



int ModificarUnEmployee(eEmployee listado[], int tam, int id)
{
  if (listado != NULL)
    {
      int sectorNuevo;
      float salarioNuevo;
      int opcion;
      int i;
      for (i = 0; i < tam; i++)
	{
	  if (listado[i].id == id)
	    {
	      opcion=GetInt("Que desea modificar?\n1-Nombre\n2-Apellido\n3-Salario\n4-Sector\nIngrese una opcion: ",4,1,"Error.Opcion incorrecta");
	      switch (opcion)
		{


		case 1:
        printf ("Ingrese el nombre: ");
        fflush (stdin);
        scanf ("%s", listado[i].name);break;

        case 2:
        printf ("Ingrese el apellido ");
        fflush (stdin);
        scanf ("%s", listado[i].lastName);break;


		case 3:
          salarioNuevo=GetFloat ("Ingrese el salario: ", 50000, 0, "El salario debe estar entre 0 y 50000: " );
		  listado[i].salary = salarioNuevo;
		  break;


		case 4:
          sectorNuevo=GetInt ("Ingrese el sector: ", 5, 1, "Error, los sectores son 1, 2, 3, 4 y 5: ");
		  listado[i].sector = sectorNuevo;
		  break;

		}
	      return 1;
	    }
	}

    }
  return 0;
}



