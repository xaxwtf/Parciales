#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "computer.h"
#include "LinkedList.h"
#include "S_Ariel.h"
#include "paser.h"

int menu()
{
    int r=-1;
    char aux[50];
    printf("\nMenu \n");
    printf("1-Cargar Datos:\n");
    printf("2-imprimir:\n");
    printf("3-generar archivo:\n");
    printf("0-Salir:\n");
    fflush(stdin);
    gets(aux);
    if(soloNumeros(aux))
    {
        r=atoi(aux);
    }
    return r;
}
int Cargar_desde_Archivo(LinkedList* lista)
{
    FILE* pFile;
    char aux[50];
    int r=0;
    pedir_cadena(aux,"Indique el nombre del Archivo:\n" );
    pFile=fopen(aux,"r");
    if(pFile!=NULL)
    {
        r=parser_EmployeeFromText(pFile,lista);
    }
    fclose(pFile);
    return r;
}
int listar(LinkedList* lista)
{
    int r=0;
    int i;
    eComputer* aux;
    ll_sort(lista,compararxTipo,-1);
    ll_maps(lista,computer_setearOferta);
    for(i=0;i<ll_len(lista);i++)
    {
        aux=(eComputer*)ll_get(lista,i);
        if(computer_get_idtipo(aux)== 1)
        {
            printf("\n %2d  %105s %6d  DESKTOP       %10s",aux->id,aux->descripcion,aux->precio,aux->oferta);
        }
        else if(computer_get_idtipo(aux)==2)
        {
            printf("\n %2d  %105s %6d  LAPTOP       %10s",aux->id,aux->descripcion,aux->precio,aux->oferta);
        }
        r=i;
    }
    return r;
}
int generar_Archivo_segun_tipo(LinkedList* lista)
{
    int opc,i,r;
    FILE* pFile;
    LinkedList* listaxTipo;
    eComputer*aux;
    char encabezado[]={"id,descripcion,precio,idtipo,oferta"};
    do{
        get_String_soloNum(&opc,"\nGenerar Archivos segun Tipo: \n1-desktop  \n2-laptops\n 0-Atras\n","Error,el caracter ingresado no es Valido",1);
        switch(opc)
        {
            case 1:
                listaxTipo=ll_Filter(lista,computer_x_Tipo,1);
                pFile=fopen("filtrado1.csv","w");
                if(pFile!=NULL)
                {
                    fprintf(pFile,"%s\n",encabezado);
                    for(i=0;i<ll_len(listaxTipo);i++)
                    {
                        aux=(eComputer*)ll_get(listaxTipo,i);
                        r=fprintf(pFile,"%d,%s,%d,%d %s\n",aux->id,aux->descripcion,aux->precio,aux->idTipo,aux->oferta);
                    }

                }
                fclose(pFile);
                break;
            case 2:
               listaxTipo=ll_Filter(lista,computer_x_Tipo,2);
                pFile=fopen("filtrado2.csv","w");
                if(pFile!=NULL)
                {
                    fprintf(pFile,"%s\n",encabezado);
                    for(i=0;i<ll_len(listaxTipo);i++)
                    {
                        aux=(eComputer*)ll_get(listaxTipo,i);
                        r=fprintf(pFile,"%d,%s,%d,%d %s",aux->id,aux->descripcion,aux->precio,aux->idTipo,aux->oferta);
                    }

                }
                fclose(pFile);
                break;
        }

    }while(opc!=0);
    return r;
}
