#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "epalabras.h"
#include "S_Ariel.h"
#include "S_Ariel.h"
#include "paser.h"
int menu()
{
    int r=-1;
    char aux[50];
    printf("\nMenu Ordenar \n");
    printf("1-Alfabetico ascendente :\n");
    printf("2-Alfabetico decendente:\n");
    printf("3-Longitud:\n");
    printf("3-Cantidad de caracteres distintos:\n");
    printf("0-Salir:\n");
    fflush(stdin);
    gets(aux);
    if(soloNumeros(aux))
    {
        r=atoi(aux);
    }
    return r;
}
int  cargar_datos(LinkedList* lista)
{
    FILE* pfile;
    int r=0;
    pfile=fopen("examen.txt","r");
    if(pfile!=NULL)
    {
        r=parser_EmployeeFromText(pfile,lista);
    }
    fclose(pfile);
    return r;
}
void Listar_palabras(LinkedList* lista)
{
    int i;
    epalabra* aux;
    for(i=0;i<ll_len(lista);i++)
    {
        aux=(epalabra*)ll_get(lista,i);
        if(aux!=NULL)
        {
            printf("%s \n",aux->dato);
        }
    }
}
void order_Alf_ascendente(LinkedList* lista)
{

}
