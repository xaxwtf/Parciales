#ifndef computer_H_INCLUDED
#define computer_H_INCLUDED
typedef struct{
    int id;
    char descripcion [120];
    int  precio;
    int idTipo;
    char oferta[30];

}eComputer;
int computer_set_id(eComputer* x, int id);
int computer_set_precio(eComputer* x, int precio);
int computer_set_idTipo(eComputer* x, int  idTipo);
eComputer* new_computer(int id,char descripcion[], float precio, int idTipo, char oferta[]);
int computer_get_idtipo(eComputer* x);
int compararxTipo(void* dato1 ,void* dato2);
int computer_setearOferta(void* dato);
int computer_x_Tipo(void* dato, void* tipo);
#endif
