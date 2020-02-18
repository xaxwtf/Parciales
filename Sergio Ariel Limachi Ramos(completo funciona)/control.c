#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "paser.h"
#include "S_Ariel.h"
#include "Partidas.h"
int cargarDatosdeArchivoTexto(LinkedList* lista)
{
    FILE* pFile;
    int r=0;
    char aux[50];
    pedir_cadena(aux,"Indique el Nombre del Archivo: ");
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
    ePartida* aux;
    ll_maps(lista,Partidas_calcular_Costo);
    for(i=0;i<ll_len(lista);i++)
    {
        aux=(ePartida*)ll_get(lista,i);
        printf("\n %4d  %12s    %d    %d  %3d    %6.2f  \n",aux->id,aux->fecha,aux->tipoJuego,aux->cantJugadores,aux->durPartida,aux->costo);
        r=i;
    }
    return r;
}
int mostrar_promedios_x_tipo_juego(LinkedList* lista){

    int i,r;
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int sumA=0;
    int sumB=0;
    int sumC=0;
    int sumD=0;
    int aaa;
    int prom0,prom1,prom2,prom3;
    ePartida* aux;
    for(i=0;i<ll_len(lista);i++)
    {
        aux=(ePartida*)ll_get(lista,i);
        switch(partida_get_tipo(aux))
        {
            case 0:
                a++;
                aaa=partida_get_cantj(aux);
                sumA=sumA+aaa;
                break;
            case 1:
                b++;
                aaa=partida_get_cantj(aux);
                sumB=sumB+aaa;
                break;
            case 2:
                c++;
                aaa=partida_get_cantj(aux);
                sumC=sumC+aaa;
                break;
            case 3:
                d++;
                aaa=partida_get_cantj(aux);
                sumD=sumD+aaa;
                break;
        }
    }
    r=ll_len(lista);
    prom0=sumA/a;
    prom1=sumB/b;
    prom2=sumC/c;
    prom3=sumD/d;
    printf("\nPromedio de Jugadores por tipo de Juego:\n Ping Pong  %d\n Pool       %d\n Metegool   %d\n Dardos     %d\n",prom0,prom1,prom2,prom3);
    return r;
}
int generar_Archivo_segun_tipo(LinkedList* lista)
{
    int opc,i,r;
    FILE* pFile;
    LinkedList* listaxTipo;
    ePartida*aux;
    char encabezado[]={"id_partida,fecha,tipo_juego,cantidad_jugadores,duracion_partida,Costo_Total"};
    do{
        get_String_soloNum(&opc,"\nGenerar Archivos segun Tipo de Juego: \n1-Ping Pong \n2-Pool \n3-Metegool \n4-Dardos \n 0-Atras\n","Error,el caracter ingresado no es Valido",1);
        switch(opc)
        {
            case 1:
                listaxTipo=ll_Filter(lista,partida_x_Tipo,0);
                pFile=fopen("PingPong.csv","w");
                if(pFile!=NULL)
                {
                    fprintf(pFile,"%s\n",encabezado);
                    for(i=0;i<ll_len(listaxTipo);i++)
                    {
                        aux=(ePartida*)ll_get(listaxTipo,i);
                        r=fprintf(pFile,"%d,%s,%d,%d,%d,%0.2f\n",aux->id, aux->fecha, aux->tipoJuego,aux->cantJugadores,aux->durPartida,aux->costo);
                    }

                }
                fclose(pFile);
                break;
            case 2:
               listaxTipo=ll_Filter(lista,partida_x_Tipo,1);
                pFile=fopen("Pool.csv","w");
                if(pFile!=NULL)
                {
                    fprintf(pFile,"%s\n",encabezado);
                    for(i=0;i<ll_len(listaxTipo);i++)
                    {
                        aux=(ePartida*)ll_get(listaxTipo,i);
                        r=fprintf(pFile,"%d,%s,%d,%d,%d,%0.2f\n",aux->id, aux->fecha, aux->tipoJuego,aux->cantJugadores,aux->durPartida,aux->costo);
                    }

                }
                fclose(pFile);
                break;
            case 3:
                listaxTipo=ll_Filter(lista,partida_x_Tipo,2);
                pFile=fopen("Metegool.csv","w");
                if(pFile!=NULL)
                {
                    fprintf(pFile,"%s \n",encabezado);
                    for(i=0;i<ll_len(listaxTipo);i++)
                    {
                        aux=(ePartida*)ll_get(listaxTipo,i);
                        r=fprintf(pFile,"%d,%s,%d,%d,%d,%0.2f\n",aux->id, aux->fecha, aux->tipoJuego,aux->cantJugadores,aux->durPartida,aux->costo);
                    }

                }
                fclose(pFile);
                break;
            case 4:
                listaxTipo=ll_Filter(lista,partida_x_Tipo,3);
                pFile=fopen("Dardos.csv","w");
                if(pFile!=NULL)
                {
                    fprintf(pFile,"%s\n",encabezado);
                    for(i=0;i<ll_len(listaxTipo);i++)
                    {
                        aux=(ePartida*)ll_get(listaxTipo,i);
                        r=fprintf(pFile,"%d,%s,%d,%d,%d,%0.2f\n",aux->id, aux->fecha, aux->tipoJuego,aux->cantJugadores,aux->durPartida,aux->costo);
                    }

                }
                fclose(pFile);
                break;
        }

    }while(opc!=0);
    return r;
}
