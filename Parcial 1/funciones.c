#include <stdio.h>
#include <string.h>
#include "funciones.h"
void inizArray(eProp vector[],int tam,int valor,int desde)
{
    int i;
    for(i=desde; i<tam; i++)
    {
        vector[i].id=valor;
    }
}
int busPrimeraOcurrencia(eProp vector[],int tam, int valor)
{
    int i;
    int index=-1;
    for(i=0;i<tam;i++)
    {
        if(vector[i].id==valor)
        {
           return i;
        }
    }

}
void mostrarDatos(eProp vector[],int tam, int valor)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(vector[i].id!=valor)
        {
            printf("\n %10s   %5d   %10s   %5s",vector[i].Nombre,vector[i].id,vector[i].Direcion,vector[i].NumTarCred);
        }
    }
}
void cargNum(char mensaje[],int dep)
{
   printf(mensaje);
   scanf("&d",&dep);
}
int soloNumeros(char vec[])
{
    int i=0;
    while(vec[i]!='\0')
    {
        if(vec[i]<'0'||vec[i]>'9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}
int soloLetras(char vec[])
{
    int i=0;
    while(vec[i]!='\0')
    {
        if((vec[i]!=' ')&&(vec[i]<'a'||vec[i]>'z')&&(vec[i]<'A'||vec[i]>'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}
int esTarjOTelefono(char vec[])
{
    int i=0;
    while(vec[i]!='\0')
    {
        if((vec[i]<'0'||vec[i]>'9')&&(vec[i]!='-'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}
void solCadena(char mensaje[],char dep[])
{
    printf(mensaje);
    fflush(stdin);
    gets(dep);
}
