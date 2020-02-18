#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux=this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    Node* nAnt;
    Node* nAct;
    if(this!=NULL)
    {
        if(nodeIndex>= 0&& nodeIndex<ll_len(this))
        {
            if(nodeIndex==0)
            {
                pNode=this->pFirstNode;
            }
            else
            {
                nAct=this->pFirstNode;
                while(nodeIndex>0)
                {
                    nAnt=nAct;
                    nAct=nAnt->pNextNode;
                    nodeIndex--;
                }
                pNode=nAct;
            }
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    int returnAux = -1;
    Node* prev;
    Node* next;
    Node* nuevoNodo;

    if( this != NULL)
    {
        if(nodeIndex >= 0 && nodeIndex <= ll_len(this))
        {
            nuevoNodo = (Node*)malloc(sizeof(Node));
            if(nuevoNodo != NULL)
            {
                nuevoNodo->pElement = pElement;
                nuevoNodo->pNextNode = NULL;

                if(nodeIndex == 0)
                {
                    nuevoNodo->pNextNode = this->pFirstNode;
                    this->pFirstNode = nuevoNodo;
                }
                else
                {
                    prev = this->pFirstNode;
                    next = prev->pNextNode;

                    while( nodeIndex > 1)
                    {
                        prev  = next;
                        next  = prev->pNextNode;
                        nodeIndex--;
                    }

                    prev->pNextNode = nuevoNodo;
                    nuevoNodo->pNextNode = next;
                }
                this->size++;
                returnAux = 0;
            }
        }
    }

    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux=addNode(this,this->size,pElement);
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* aux;
    if(this!=NULL)
    {
        if(index>=0 && index<this->size)
        {
            aux=getNode(this,index);
            returnAux=aux->pElement;
        }

    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* aux;
    if(this!=NULL)
    {
        if(index>=0&&index<ll_len(this))
        {
            aux=getNode(this,index);
            aux->pElement=pElement;
            returnAux=0;
        }
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* prev;
    Node* next;
    if(this!=NULL)
    {
        if(index>=0 && index<ll_len(this))
        {
            if(index==0)
            {
                prev=this->pFirstNode;
                next=prev->pNextNode;
                this->pFirstNode=next;
                free(prev);
            }
            else{
                next=this->pFirstNode;
                while(index>0)
                {
                    prev=next;
                    next=prev->pNextNode;
                    index--;
                }
                prev->pNextNode=next->pNextNode;
                free(next);
            }
            this->size--;
            returnAux=0;
        }
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len;
    if(this!=NULL)
    {
        for(len=ll_len(this)-1;len>=0;len--)
        {
            ll_remove(this,len);
        }
        returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        ll_clear(this);
        free(this);
        returnAux=0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* prev;
    Node* next;
    if(this!=NULL)
    {
        next=this->pFirstNode;
        if(next->pElement==pElement)
        {
            returnAux=0;
        }
        else{

            for(i=1;i<ll_len(this);i++)
            {
                prev=next;
                next=prev->pNextNode;
                if(next->pElement==pElement)
                {
                    returnAux=i;
                    break;
                }
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        if(ll_len(this)>0)
        {
            returnAux=0;
        }
        else{
            returnAux=1;
        }
    }
    else{
        returnAux=-1;
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux=addNode(this,index,pElement);
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* aux;
    if(this!=NULL)
    {
        if(index>=0 && index<ll_len(this))
        {
            aux=getNode(this,index);
            returnAux=aux->pElement;
            ll_remove(this,index);
        }
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* aux;
    if(this!=NULL)
    {
        returnAux=0;
        for(i=0;i<ll_len(this);i++)
        {
            aux=getNode(this,i);
            if(aux->pElement==pElement)
            {
                returnAux=1;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    Node* aux;
    if(this!=NULL&&this2!=NULL)
    {
        returnAux=1;
        for(i=0;i<ll_len(this2);i++)
        {
            aux=getNode(this2,i);
            if(ll_contains(this,aux->pElement)==0)
            {
                returnAux=0;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* aux=NULL;
    int i;
    int k=0;
    Node* prev;
    Node* next;
    if(this!=NULL)
    {
        if((from>=0 && to>0)&& (from<ll_len(this)&&to<=ll_len(this)))
        {
            aux=ll_newLinkedList();
            if(aux!=NULL)
            {
                next=this->pFirstNode;
                if(from==0)
                {
                    addNode(aux,k,next->pElement);
                    for(i=1;i<to;i++)
                    {
                        prev=next;
                        next=prev->pNextNode;
                        addNode(aux,i,next->pElement);
                    }
                }
                else{
                    for(i=1;i<ll_len(this);i++)
                    {
                        prev=next;
                        next=prev->pNextNode;
                        if(i>=from && i<to)
                        {
                            addNode(aux,k,next->pElement);
                            k++;
                        }
                    }
                }
            }
        }
    }

    return aux;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL)
    {
        cloneArray=ll_subList(this,0,ll_len(this));
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i,k;
    Node* datoA;
    Node* datoB;
    void* valor;
    if(this!=NULL)
    {
        if(pFunc!=NULL)
        {
            switch(order)
            {
                case 1:
                    for(i=0;i<ll_len(this);i++)
                    {
                        for(k=i+1;k<ll_len(this);k++)
                        {
                            datoA=getNode(this,i);
                            datoB=getNode(this,k);
                            if(pFunc(datoA->pElement,datoB->pElement)==1)
                            {
                                valor=datoA->pElement;
                                datoA->pElement=datoB->pElement;
                                datoB->pElement=valor;
                            }

                        }
                    }
                    returnAux=0;
                    break;
                case 0:
                    for(i=0;i<ll_len(this);i++)
                    {
                        for(k=i+1;k<ll_len(this);k++)
                        {
                            datoA=getNode(this,i);
                            datoB=getNode(this,k);
                            if(pFunc(datoA->pElement,datoB->pElement)==-1)
                            {
                                valor=datoA->pElement;
                                datoA->pElement=datoB->pElement;
                                datoB->pElement=valor;
                            }

                        }
                    }
                    returnAux=0;
                    break;

                default:
                    returnAux=-1;
            }

        }



    }

    return returnAux;

}
int ll_maps(LinkedList* lista, int(*pfunc)(void*))
{
    int returnAux =-1;
    int i;
    void* valor;
    if(lista!=NULL)
    {
         for(i=0;i<ll_len(lista);i++)
         {
             valor=ll_get(lista,i);
             pfunc(valor);
             returnAux=i;
         }
    }
    return returnAux;
}
LinkedList* ll_Filter(LinkedList* lista,int(*pfunc)(void*, void*),int x)
{
    LinkedList* nuevo;
    int i;
    void* actual;
    if(lista!=NULL)
    {
        nuevo=ll_newLinkedList();
        if(nuevo!=NULL)
        {
            for(i=0;i<ll_len(lista);i++)
            {
                actual=ll_get(lista,i);
                if(pfunc(actual,x)==0)
                {
                    ll_add(nuevo,actual);
                }
            }
        }

    }
    return nuevo;
}

