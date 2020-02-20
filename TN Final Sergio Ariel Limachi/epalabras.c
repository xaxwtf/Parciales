#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "epalabras.h"
int  palabra_set_dato(epalabra* x , char dato[])
{
    int r=0;
    if(strlen(dato)<30)
    {
        strcpy(x->dato,dato);
        r=1;
    }
    return r;
}
epalabra* new_palabra(char dato[])
{
    epalabra* nuevo;
    nuevo=(epalabra*)malloc(sizeof(epalabra));
    if(nuevo!=NULL)
    {
        if(!palabra_set_dato(nuevo,dato)){
            free(nuevo);
            nuevo=NULL;
        }
    }
    return nuevo;
}
/*int palabra_comparar(void* dato1, void* dato2)
{
    epalabra* aux1;
    epalabra* aux2;
    aux1=(epalabra*)dato1;
    aux2=(epalabra*)dato2;
    if(strcmp(aux1,aux2)=1)
    {


    }
}*/
