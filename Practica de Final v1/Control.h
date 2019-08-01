#ifndef Control_H_INCLUDED
#define Control_H_INCLUDED
#include "abono.h"
#include "eCliente.h"
int cargarDatosdeArchivoTexto(LinkedList* lista);
int crearYcompletar(LinkedList* listaCte,LinkedList* listaAb);
int listar(eCliente* listaCte, eAbono* listaAb);
#endif // Control_H_INCLUDED
