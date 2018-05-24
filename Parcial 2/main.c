#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#define TAM 20
int main()
{
    int opcion=100;
    int i;
    int busDato;
    int resBusq;
    int limDCaracteres;
    eProp Propietarios[TAM];
    eProp aux;
    char auxIdString[100];
    int id[TAM]= {1,2,3,4};
    char nombre[TAM][20]= {"Juan","Luis","Maria","Jose"};
    char tarjeta[TAM][20]= {"111-111","222-222","333-333","444-444"};
    char direccion[TAM][20]= {"mitre","urquiza","belgrano","alsina"};
    for(i=0;i<TAM;i++)
    {
        Propietarios[i].id=id[i];
        strcpy(Propietarios[i].Nombre,nombre[i]);
        strcpy(Propietarios[i].NumTarCred,tarjeta[i]);
        strcpy(Propietarios[i].Direcion,direccion[i]);
    }
    inizArray(Propietarios,TAM,-1,4);

    do{
            printf("\n      Nombre     %5ID   %10Direccion  %5Targ.Credito\n");
            mostrarDatos(Propietarios,TAM,-1);
            printf("\n 1- ALTA DE PROPIETARIO. \n 2- MODIFICACION DE PROPIETARIO. \n 3- BAJA DE PROPIETARIO.\n 0- Salir. \n");
            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                    busDato=busPrimeraOcurrencia(Propietarios,TAM,-1);
                    solCadena("\n indique el Numero de ID: ",auxIdString);
                    if(!soloNumeros(auxIdString))
                    {
                        printf("\n Ingrese solamente Numeros \n");
                        break;
                    }
                    aux.id=atoi(auxIdString);
                    if(busPrimeraOcurrencia(Propietarios,TAM,aux.id)!=-1)
                    {
                        printf("el Legajo Indicado ya Existe");
                        break;
                    }
                    solCadena("\n indique el Nombre del Propietario: ",aux.Nombre);
                    if(!soloLetras(aux.Nombre))
                    {
                        printf("\n El Nombre solo debe contener Letras \n");
                        break;
                    }
                    solCadena("\n Indique Su Direccion: ",aux.Direcion);
                    if(!esAlfaNumer(aux.Nombre))
                    {
                        printf("\n !!!!Direccion No Valida");
                        break;
                    }
                    solCadena("\n Indique el Numero de su Tarjeta de Credito Ej: xxx-xxx: ",aux.NumTarCred);
                    limDCaracteres=strlen(aux.NumTarCred);
                    if(limDCaracteres == 7 && esTarjOTelefono(aux.NumTarCred))
                    {
                        Propietarios[busDato]=aux;
                    }
                    else
                    {
                        printf("\n Tarjeta de credito Invalida");
                        break;
                    }
                    break;
                case 2:
                    solCadena("\n indique el ID del Usuario que Solicita el Cambio de Tarj. de Credito: \n",auxIdString);
                    aux.id=atoi(auxIdString);
                    resBusq=busPrimeraOcurrencia(Propietarios,TAM,aux.id);
                    if(resBusq==-1)
                    {
                        printf("\n El Legajo Indicado No existe \n");
                    }
                    else
                    {
                        solCadena("\n Indique el Nuevo Numero de Tarj. Credito",aux.NumTarCred);
                        if(esTarjOTelefono(aux.NumTarCred))
                        {
                            strcpy(Propietarios[resBusq].NumTarCred,aux.NumTarCred);
                        }
                        else
                        {
                            printf("\n Tarj.de Credito Invalida\n");
                        }
                    }
                    break;
                case 3:
                    break;
            }


    }while(opcion!=0);

    return 0;
}
