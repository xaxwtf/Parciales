#ifndef eCliente_H_INCLUDED
#define eCliente_H_INCLUDED
typedef struct{
    int id;
    char nombre[50];
    char sexo;
    char numeroTelefono[20];
    float Importe;
}eCliente;
int setIDclient(eCliente*client,int dato);
int setNombreClient(eCliente* client,char nombre[]);
int setNumTelClient(eCliente* client, char tel[]);
int setImporteClient(eCliente* client,float imp);
eCliente* newCliente(int id,char nombre[],char sexo,char numTel[],float importe);
int cliente_get_Id(eCliente* x);
float cliente_get_importe(eCliente* x);
#endif // eCLiente_H_INCLUDED
