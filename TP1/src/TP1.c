#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"


int main()
{
	setbuf(stdout, NULL);
	float A=0;
	float B=0;
    int flagingresoA=0;
    int flagingresoB=0;
    int flagcalculo=0;
    int flagdivision=0;
    float suma;
    float factoreoB;
    float factoreoA;
    float division;
    float multiplicacion;
    float resta;

    int opcion;

    do
    {
        opcion=menu(A, B);

        switch(opcion)
        {
            case 1:

            A=pedirnum();
            flagingresoA=1;
            break;


         case 2:

            B=pedirnum();
            flagingresoB=1;
            break;

         case 3:

            if (flagingresoA&&flagingresoB){
                suma=sumar(A,B);
                resta=restar(A,B);
                multiplicacion=multiplicar(A,B);
                division=dividir(A,B, &flagdivision);
                factoreoA=factorear(A);
                factoreoB=factorear(B);
                flagcalculo=1;
                printf("Calculos realizados\n");
                system("pause");

                break;

            }
            else{
                printf("Ingrese todos los operandos primero\n");
                system("pause");

                break;
            }

         case 4:
             if(flagcalculo){
               printf("La suma es: %.2f\n",suma);
                printf("La resta es: %.2f\n",resta);
                printf("La multiplicacion es: %.2f\n",multiplicacion);
                printf("El factoreo de A: %.2f\n",factoreoA);
                printf("El factoreo de B: %.2f\n",factoreoB);
                if(flagdivision){
                    printf("No se puede dividir por cero\n");
                }
                else{
                printf("La division es: %.2f\n",division);
                }
                system("pause");

             }
             else{
                printf("Primero debe calcular\n");
                system("pause");

             }

        }


    }
    while(opcion!=5);


    return 0;
}
