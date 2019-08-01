#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <string.h>
#include "eCliente.h"
#include "S_Ariel.h"
int setIDclient(eCliente* client,int dato)
{ int r=0;
    if(dato>=0)
    {
        client->id=dato;
        r=1;
    }
    return r;
}
int setNombreClient(eCliente* client,char nombre[])
{
    int r=0;
    int tam=strlen(nombre);
    if(tam<= 50)
    {
        strcpy(client->nombre,nombre);
        r=1;
    }
    return r;
}
int setSexoClient(eCliente* client,char sexo)
{
    int r=0;
    if(sexo=='f'|| sexo=='m'||sexo=='M'||sexo=='F')
    {
        client->sexo=sexo;
        r=1;
    }
    return r;
}
int setNumTelClient(eCliente* client, char tel[])
{
    int r=0;
    int tam=strlen(tel);
    if(tel<=21)
    {
        strcpy(client->numeroTelefono,tel);
        r=1;
    }
    return r;
}
int setImporteClient(eCliente* client,float imp)
{
    int r=0;
    if(imp>0)
    {
        client->Importe=imp;
        r=1;
    }
    return r;
}
eCliente* new_Cliente(int id,char nombre[],char sexo,char numTel[],float importe)
{
    int ok=1;
    eCliente* nuevo;
    nuevo=(eCliente*)malloc(sizeof(eCliente));
    if(nuevo!=NULL)
    {
        if(setIDclient(nuevo,id)==0){
            ok=0;
        }
        if(setNombreClient(nuevo,nombre)==0){
            ok=0;
        }
        if(setSexoClient(nuevo,sexo)==0){
            ok=0;
        }
        if(setNumTelClient(nuevo,numTel)==0){
            ok=0;
        }
        if(setImporteClient(nuevo,importe)==0){
            ok=0;
        }
        if(ok==0){
            free(nuevo);
        }
    }
    return nuevo;
}
int cliente_get_Id(eCliente* x)
{
    int r=-1;
    if(x!=NULL)
    {
        r=x->id;
    }
    return r;
}
float cliente_get_importe(eCliente* x)
{
    float aux;
    if(x!=NULL)
    {
        aux=x->Importe;
    }
    return aux;
}

