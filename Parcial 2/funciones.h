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
/** \brief verifica que el Array Recibido Contega Solamente Numerod
 *
 * \param es el Array a ser Analizado
 * \return retorna 1 si EL array contiene solamente Numeros y 0 si no
 *
 */
int soloNumeros(char vec[]);

/** \brief Veririca que la cadena Recibida Contenga Solamente Letras
 *
 * \param es el Array a Ser Analizado
 * \return retorna 1 si la cadena  contiene Solo letras y 0 si no
 *
 */
int soloLetras(char vec[]);

/** \brief Veririca que la cadena Recibida es Una Tarjeta o un Telefono
 *
 * \param es la Cadena a ser Analizada
 * \return retorna 1 si la cadena es una tarj. o telf. o 0 si no
 *
 */
int esTarjOTelefono(char vec[]);
/** \brief solicita un string  y lo guarda
 *
 * \param mensaje: es el MensajeVeririca que la cadena Recibida Contenga Solamente Letras a ser Mostrado AL solicitar el String
 * \param dep : es la Dirrecion Donde Se guardara el Dato Obtenido
 * \return
 *
 */
void solCadena(char mensaje[],char dep[]);
/** \brief Verifica si La cadena Recibida es AlfaNumerico
 *
 * \param es la cadena a ser Analizada
 * \return 1 si la cadena es Alfanumerica y 0 si no
 *
 */
int esAlfaNumer(char vec[]);

