#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "S_Ariel.h"
#include "Control.h"
#define PERSONAL 0
#define FAMILIAR 1
#define CORPORATIVO 2

int main()
{
    int reservado=0;
    int opc=9999;
    LinkedList* clientes;
    LinkedList* abonos;
    clientes=ll_newLinkedList();
    abonos=ll_newLinkedList();
    do{
        system("cls");
        getInt(&opc,"\n-----------FINAL test------------\n1- ALTA\n2- CREAR Y COMPLETAR\n3- LISTAR\n0- SALIR\n","Error, el numero indicado es invalido",0,10,3);
        switch(opc)
        {
            case 1:
                if(cargarDatosdeArchivoTexto(clientes)==0)
                {
                    printf("\nEl archivo no existe\n");
                }
                else{
                    system("cls");
                    printf("\nDatos cargados Correctamente\n");
                    printf(" %d",clientes->size);
                    system("pause");
                }
                break;
            case 2:
                if(crearYcompletar(clientes,abonos)==-1)
                {
                    printf("\nno se pudo Generar datos\n");
                }
                else{
                    printf("\nDatos generados Correctamente\n");
                }

                break;
            case 3:
                if(listar(clientes,abonos)!=0)
                {
                    system("pause");
                }
                break;
        }

    }while(opc!=0);

    return 0;

}
