#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Partidas.h"
int partida_set_id(ePartida* x,int id)
{
    int r=0;
    if(id>0)
    {
        x->id=id;
        r=1;
    }
    return r;
}
int partida_set_cantJugadores(ePartida* x,int cantJ)
{
    int r=0;
    if(cantJ>0)
    {
        x->cantJugadores=cantJ;
        r=1;
    }
    return r;
}
int partida_set_duracionPart(ePartida* x,int dur)
{
    int r=0;
    if(dur>0)
    {
        x->durPartida=dur;
        r=1;
    }
    return r;
}
int partida_set_fecha(ePartida* x,char fecha[])
{
    strcpy(x->fecha,fecha);
    return 1;
}
int partida_set_tipo(ePartida* x,int tipe)
{
    int r=0;
    if(tipe>=0 && tipe<4)
    {
        x->tipoJuego=tipe;
        r=1;
    }
    return r;
}
int partida_set_costo(ePartida*x,float cost)
{
    int r=0;
    if(cost>=0)
    {
        x->costo=cost;
        r=1;
    }
    return r;
}
ePartida* new_partida(int id, char fecha[],int tipo,int cantj, int duracion,float costo)
{
    ePartida* nuevo;
    int ok=1;
    nuevo=(ePartida*)malloc(sizeof(ePartida));
    if(nuevo!=NULL)
    {
        if(!partida_set_id(nuevo,id))
        {
            ok=0;
        }
        partida_set_fecha(nuevo,fecha);

        if(!partida_set_cantJugadores(nuevo,cantj)){
            ok=0;
        }
        if(!partida_set_tipo(nuevo,tipo)){
            ok=0;
        }
        if(!partida_set_duracionPart(nuevo,duracion)){
            ok=0;
        }
        if(!partida_set_costo(nuevo,costo)){
            ok=0;
        }
        if(ok==0)
        {
            free(nuevo);
            nuevo=NULL;
        }
    }
    return nuevo;
}
int partida_get_tipo(ePartida* x)
{
    int r;
    r=x->tipoJuego;
    return r;
}
int partida_get_cantj(ePartida* x)
{
    int r;
    r=x->cantJugadores;
    return r;
}
int Partidas_calcular_Costo(void* x)
{
    int r=1;
    ePartida* aux;
    aux=(ePartida*)x;
    switch(partida_get_tipo(aux))
    {
            case 0:
                 aux->costo=2*aux->durPartida;
                break;
            case 1:
                aux->costo=2.5*aux->durPartida;
                break;
            case 2:
                aux->costo=1*aux->durPartida;
                break;
            case 3:
                aux->costo=1.5*aux->durPartida;
                break;
    }
    return r;
}
int partida_x_Tipo(void* dato, void* tipo)
{
    int r=1;
    int t;
    ePartida* aux;
    aux=(ePartida*)dato;
    t=(int)tipo;
    if(partida_get_tipo(aux)==t)
    {
        r=0;
    }
    return r;
}
