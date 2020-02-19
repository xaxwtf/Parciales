#ifndef control_H_INCLUDED
#define control_H_INCLUDED
#include "LinkedList.h"
int menu();
int Cargar_desde_Archivo(LinkedList* lista);
int listar(LinkedList* lista);
int generar_Archivo_segun_tipo(LinkedList* lista);
#endif
