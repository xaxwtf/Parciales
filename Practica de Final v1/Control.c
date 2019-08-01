#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "paser.h"
#include "S_Ariel.h"
#include "eCliente.h"
#include "abono.h"
#define PERSONAL 0
#define FAMILIAR 1
#define CORPORATIVO 2
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

int crearYcompletar(LinkedList* listaCte,LinkedList* listaAb)
{
    int r=-1;
    int cont;
    eCliente* actualCte;
    eCliente* auxBsq;
    eAbono* nuevo;
    int auxID=0;
    float importeParcial,importeFinal;
    for(int i=0;i<ll_len(listaCte;i++)
    {
        /*actualCte=(eCliente*)ll_get(listaCte,i);
        buscarTodaslasOcurrencias(listaAb,)*/

    }

    return r;
}
int listar(eCliente* listaCte, eAbono* listaAb)
{
    int r=0;
    int i,k;
    eCliente* aux;
    eAbono* abono;
    ll_sort(listaAb,ordenarXImporte,1);
        for(i=0;i<ll_len(listaAb);i++)
        {
            abono=(eAbono*)ll_get(listaAb,i);
            printf("\nID ABONO: %d  IMPORTE FINAL:%4.2f TIPO: %d \n",abono->id,abono->importeFinal,abono->tipo);
            for(k=0;k<ll_len(listaCte);k++)
            {
                aux=(eCliente*)ll_get(listaCte,k);
                if(aux->id==abono->idCliente)
                {
                    printf("%d  %20s %c  %10s %5.2f \n",aux->id,aux->nombre,aux->sexo,aux->numeroTelefono,aux->Importe);
                }
            }
            r=i;
        }
        return r;
}
