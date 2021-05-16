#include "Input.h"

void GetChar (char mensaje[])
{
    fflush (stdin);
    printf ("%s", mensaje);
}


int GetInt (char mensaje[], int param1, int param2, char mensajeError[])
{
    int num;
    printf ("%s", mensaje);
    scanf ("%d", &num);

     while (num>param1||num<param2)
    {
    printf ("%s", mensajeError);
    scanf ("%d", &num);
    }
    return num;
}


float GetFloat (char mensaje[], int param1, int param2, char mensajeError[])
{
    float num;
    printf ("%s", mensaje);
    scanf ("%f", &num);
    while (num>param1||num<param2)
    {
    printf ("%s", mensajeError);
    scanf ("%f", &num);
    }
    return num;
}
