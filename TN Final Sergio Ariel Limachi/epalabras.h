#ifndef epalabras_H_INCLUDED
#define epalabras_H_INCLUDED
typedef struct{
    char dato [21];
}epalabra;
int  palabra_set_dato(epalabra* x , char dato[]);
epalabra* new_palabra(char dato[]);

#endif

