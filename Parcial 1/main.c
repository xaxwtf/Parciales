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
    char auxTarj[50];
    eProp Propietarios[TAM];
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
                    resBusq=busPrimeraOcurrencia(Propietarios,TAM,-1);
                    if(resBusq!=-1)
                    {
                        ingrSoloLetras("\n Indique el Nombre del Propietario: ",Propietarios[resBusq].Nombre);
                        solCadena("Indique el Numero de Tarjeta",auxTarj);
                        if(!(esTarjOTelefono(auxTarj)==1)&&(strlen(auxTarj)==8))
                        {
                            printf("Indique un Numero de Tarjeta Valido");
                        }



                    }

                    break;
                case 2:
                    break;
                case 3:
                    break;
            }


    }while(opcion!=0);

    return 0;
}
