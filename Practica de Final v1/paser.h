#ifndef parser_H_INCLUDED
#define parser_H_INCLUDED
#include "LinkedList.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayList);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayList);
#endif // parser_H_INCLUDED
