#include <stdio.h>
#include <stdlib.h>
#include "S_Ariel.h"
#include "control.h"
#include "LinkedList.h"

int main()
{
    LinkedList* listaComputer;
    listaComputer=ll_newLinkedList();
    int opc=-1;
    do{
       opc = menu();
       switch(opc)
       {
           case 1:
               if(Cargar_desde_Archivo(listaComputer))
               {
                   printf("se cargo Correctamente");
               }
               else{
                printf("No existe");
               }
                break;
           case 2:
                if(!listar(listaComputer))
                {
                    printf("no hay datos");
                }
                break;
           case 3:
               generar_Archivo_segun_tipo(listaComputer);
                break;
           case 4:
                break;
       }

    }while(opc!=0);
    return 0;
}
