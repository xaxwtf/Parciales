#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "paser.h"
#include "epalabras.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayList)
{
    char aux1[21];
    epalabra* nuevo;
    int r=0;
    do{
        r=fscanf(pFile,"%[^\n]\n",aux1);
        printf("%s \n",aux1);
        /*if(r==1)
        {
            nuevo = new_palabra(aux1);
            if(nuevo!=NULL)
            {

                ll_add(pArrayList,nuevo);
            }
        }*/
    }while(!feof(pFile));
    return r;
}
