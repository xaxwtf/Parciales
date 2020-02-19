#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "computer.h"
int computer_set_id(eComputer* x, int id)
{
    int r=0;
    if(id>0)
    {
        x->id=id;
        r=1;
    }
    return r;
}
int computer_set_precio(eComputer* x, int precio)
{
    int r=0;
    if(precio>=0)
    {
        x->precio=precio;
        r=1;
    }
    return r;
}
int computer_set_idTipo(eComputer* x, int  idTipo)
{
    int r=0;
    if(idTipo>0)
    {
        x->idTipo=idTipo;
        r=1;
    }
    return r;
}
eComputer* new_computer(int id, char descripcion[], float precio, int idTipo, char oferta[])
{
    eComputer* nuevo;
    int ok=0;
    nuevo=(eComputer*)malloc(sizeof(eComputer));
    if(nuevo!=NULL)
       {
            if(computer_set_id(nuevo,id)){
               ok++;
            }
            strcpy(nuevo->descripcion,descripcion);
            if(computer_set_precio(nuevo,precio)){
               ok++;
            }
            if(computer_set_idTipo(nuevo,idTipo)){
               ok++;
            }
            strcpy(nuevo->oferta,oferta);
            if(ok==0)
            {
                free(nuevo);
                nuevo=NULL;
            }
       }
       return nuevo;
}
int computer_get_idtipo(eComputer* x)
{
    return x->idTipo;
}
int compararxTipo(void* dato1,void* dato2)
{
    eComputer* aux1;
    eComputer* aux2;
    aux1=(eComputer*)dato1;
    aux2=(eComputer*)dato2;
    int r;
    if(computer_get_idtipo(aux1)==computer_get_idtipo(aux2))
    {
        r=0;
    }
    if(computer_get_idtipo(dato1)>computer_get_idtipo(dato2))
    {
        r=1;
    }
    if(computer_get_idtipo(dato1)<computer_get_idtipo(dato2))
    {
        r=-1;
    }

    return r;
}
int computer_setearOferta(void* dato)
{
    int r;
    eComputer* aux;
    aux=(eComputer*)dato;
    if(computer_get_idtipo(aux)==2)
    {
        strcpy(aux->oferta,"SIN DATOS");
        r=2;

    }
    if(computer_get_idtipo(aux)==1 && aux->precio > 20000)
    {
        strcpy(aux->oferta,"50% DESCUENTO");
        r= 1;
    }
    return r;
}
int computer_x_Tipo(void* dato, void* tipo)
{
    int r=1;
    int t;
    eComputer* aux;
    aux=(eComputer*)dato;
    t=(int)tipo;
    if(computer_get_idtipo(aux)==t)
    {
        r=0;
    }
    return r;
}

