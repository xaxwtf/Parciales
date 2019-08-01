#include "abono.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
int abono_setTipo(eAbono* abono, int tipe)
{
    int r=0;
    if(tipe>=0)
    {
        abono->tipo=tipe;
        r=1;
    }
    return r;
}
int abono_set_importeFinal(eAbono* x, float total)
{
    int r=0;
    if(x!=NULL)
    {
        x->importeFinal=total;
        r=1;
    }
    return r;
}
int abono_set_id(eAbono* x,int* idAbono)
{
    int r=0;
    if(x!=NULL)
    {
        *idAbono=*idAbono+1;
        x->id=*idAbono;
        r=1;
    }
    return r;
}
int abono_set_id_cliente(eAbono* x,int idclient)
{
    int r=0;
    if(idclient>=0)
    {
        x->idCliente=idclient;
        r=1;
    }
    return r;
}
int abono_get_tipo(eAbono* x)
{
    int r;
    if(x!=NULL)
    {
        r=x->tipo;
    }
    return r;
}
int ordenarXImporte(void* x,void* y)
{
    int r=0;
    eAbono* dato1=(eAbono*)x;
    eAbono* dato2=(eAbono*)y;
    if(dato1->importeFinal > dato2->importeFinal)
    {
            r=1;
    }
    if(dato1->importeFinal < dato2->importeFinal)
    {
        r=-1;
    }
    return r;
}
int comparar(void* x, void* tipo)
{
    int r=NULL;
    eAbono* lll=(eAbono*)x;
    int y=(int)tipo;
    if(lll->tipo==y)
    {
        r=0;
    }
    if(lll->tipo>y)
    {
        r=1;
    }
    if(lll->tipo<y)
    {
        r=-1;
    }
    return r;
}
eAbono* new_abono (int* id, int tipe, int idCte, float impFinal)
{
    int ok=1;
    eAbono* nuevo;
    nuevo=(eAbono*)malloc(sizeof(eAbono));
    if(nuevo!=NULL)
    {
        if(!abono_set_id(nuevo,id)){
            ok=0;
        }
        if(!abono_setTipo(nuevo,tipe)){
            ok=0;
        }
        if(!abono_set_id_cliente(nuevo,idCte)){
            ok=0;
        }
        if(!abono_set_importeFinal(nuevo,impFinal)){
            ok=0;
        }
        if(ok==0){
            free(nuevo);
        }
    }
    return nuevo;
}
int buscarExistencia(LinkedList* lista, int idcte)
{
    int r=0;
    int i;
    eAbono* aux;
    for(i=0;i<ll_len(lista);i++)
    {
        aux=(eAbono*)ll_get(lista,i);
        if(aux->idCliente==idcte)
        {
            r=1;
        }
    }
    return r;
}


