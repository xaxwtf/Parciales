#ifndef Partidas_H_INCLUDED
#define Partidas_H_INCLUDED

typedef struct{
    int id;
    char fecha[50];
    int tipoJuego;
    int cantJugadores;
    int durPartida;
    float costo;
}ePartida;
int partida_set_id(ePartida* x,int id);
int partida_set_cantJugadores(ePartida* x,int cantJ);
int partida_set_duracionPart(ePartida* x,int dur);
int partida_set_fecha(ePartida* x,char fecha[]);
int partida_set_tipo(ePartida* x,int tipe);
int partida_set_costo(ePartida*x,float cost);
ePartida* new_partida(int id, char fecha[],int tipo,int cantj, int duracion,float costo);
int partida_get_tipo(ePartida* x);
int partida_get_cantj(ePartida* x);
int Partidas_calcular_Costo(void* x);
int partida_x_Tipo(void* dato, void* tipo);
#endif // Partidas_H_INCLUDED
