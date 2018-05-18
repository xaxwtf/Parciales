typedef struct{
    int id;
    char  Nombre[50];
    char  Direcion[50];
    char  NumTarCred[50];
}eProp;
/** \brief inicializa un array en el valor que indique el programador
 *
 * \param vector: es el array al cual se le asiganara el dato
 * \param tam es el tamaño del array al cual se le asignara el dato
 * \param es el dato que se le asiganara a cada pocicion del array
 * \param desde el Indice a partir del cual le Asignara el valor indicado
 * \return
 *
 */
void inizArray(eProp vector[],int tam,int valor,int desde);
/** \brief busca el valor indicado dentro del array
 *
 * \param vector es el array en el cual se reliza la busqueda
 * \param tam es el tamaño del array
 * \param valor es el dato a ser buscando dentro del arrays
 * \return devuelve -1 si no se encuentra el dato o devuelve el indice en el cual se encontro el dato indicado
 *
 */
int busPrimeraOcurrencia(eProp vector[],int tam, int valor);

/** \brief Muestra todos los Datos de una Estructura de Eprop
 *
 * \param vector es la estructura que contiene los datos a mostrar
 * \param tam es el tamaño del array de eprop
 * \param valor es el dato asignado a una pocicion vacia que no sera mostrada
 * \return
 *
 */

void mostrarDatos(eProp vector[],int tam, int valor);
int soloNumeros(char vec[]);
void cargSoloNumeros(char mensaje[],int dep);
void ingrSoloLetras(char mensaje[],char dep[]);
int esTarjOTelefono(char vec[]);
