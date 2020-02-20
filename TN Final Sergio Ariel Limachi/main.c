#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "control.h"

int main()
{
    LinkedList* listaPalabras;
    int opc;
    listaPalabras= ll_newLinkedList();
    do{
            opc=menu();
            switch(opc)
            {
            case 1:
                Listar_palabras(listaPalabras);
                break;
            case 2:
                if(cargar_datos(listaPalabras)==0)
                {
                    printf("no hay datos");
                }
                break;
            case 3:
                break;
            case 4:
                break;
            }

    }while(opc!=0);

    return 0;
}
