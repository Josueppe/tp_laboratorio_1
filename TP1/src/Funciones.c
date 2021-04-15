#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"



int menu(int A, int B)
{

    int opcion;
    //system("cls");
    printf("-------Menu de opciones-------\n");
    printf("1-Ingresar 1er operando: A=%d \n",A);
    printf("2-Ingresar 2do operando: B=%d \n",B);
    printf("3-Calcular todas las operaciones:\n");
    printf("   -Sumar\n");
    printf("   -Restar\n");
    printf("   -Multiplicar\n");
    printf("   -Factorial\n");
    printf("   -Dividir\n");
    printf("4- Informar resultados.\n");
    printf("5- Cerrar calculadora.\n");
    printf("Ingrese su opcion: ");
    fflush(stdout);
    scanf("%d",&opcion);
    return opcion;

}

float pedirnum()
{
	float num;
    printf("Ingresar operando: \n");
    scanf("%f",&num);

    return num;

}

float sumar(float A,float B){
	float resultado;

resultado=A+B;

return resultado;

}

float restar(float A,float B){
	float resultado;

resultado=A-B;

return resultado;

}



float dividir(float A,float B, int* flagdivision){
	float resultado;
if(B!=0){
resultado=(float)A/B;
}
else{
    *flagdivision=1;
}

return resultado;

}



float multiplicar(float A,float B){
	float resultado;

resultado=A*B;

return resultado;

}

float factorear(float num){

	float r1=1;
    for(int i = 1; i <= num; i++)
    {
        r1 = r1 * i;
    }
    return r1;

}
