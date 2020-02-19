#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "paser.h"
#include "computer.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayList)
{
    char aux1[101];
    char aux2[120];
    char aux3[50];
    char aux4[101];
    int num1,num2;
    int fnum;
    eComputer* nuevo;
    int r=0;
    r=fscanf(pFile,"%[^\n]",aux1);
    do{
        r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",aux1,aux2,aux3,aux4);
        if(r==4)
        {
            num1=atoi(aux1);
            fnum=atoi(aux3);
            num2=atoi(aux4);
            nuevo= new_computer(num1,aux2,fnum,num2," ");
            if(nuevo!=NULL)
            {
                ll_add(pArrayList,nuevo);
            }
        }
    }while(!feof(pFile));
    return r;
}
