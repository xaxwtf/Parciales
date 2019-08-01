#ifndef abono_H_INCLUDED
#define abono_H_INCLUDED
typedef struct{
    int id;
    int tipo;
    int idCliente;
    float importeFinal;
}eAbono;
int abono_setTipo(eAbono* abono, int tipe);
int abono_set_importeFinal(eAbono* x, float total);
int abono_set_id(eAbono* x, int* idAbono);
int abono_set_id_cliente(eAbono* x,int idclient);
int abono_get_tipo(eAbono* x);
int ordenarXImporte(void* x,void* y);
int comparar(void* x, void* tipo);
eAbono* new_abono (int* id, int tipe, int idCte, float impFinal);
int buscarExistencia(LinkedList* lista, int idcte);
#endif // abono_H_INCLUDED
