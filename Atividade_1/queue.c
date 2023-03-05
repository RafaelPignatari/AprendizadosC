#include "queue.h"
#include <windows.h>

// Conta o numero de elementos na fila
// Retorno: numero de elementos na fila

int queue_size (queue_t *queue) 
{
    int contagem = 0;

    if (queue != NULL)
    {
        queue_t *proximoElemento = queue->next;
        contagem++;

        while (proximoElemento != queue)
        {
            contagem++;

            proximoElemento = proximoElemento->next;
        }
    }

    return contagem;
}

//------------------------------------------------------------------------------
// Percorre a fila e imprime na tela seu conteúdo. A impressão de cada
// elemento é feita por uma função externa, definida pelo programa que
// usa a biblioteca. Essa função deve ter o seguinte protótipo:
//
// void print_elem (void *ptr) ; // ptr aponta para o elemento a imprimir

void queue_print (char *name, queue_t *queue, void print_elem (void*) )
{
    if (queue != NULL)
    {
        print_elem(queue);
        queue_t *proximoElemento = queue->next;

        while (proximoElemento != queue)
        {
            print_elem(proximoElemento);
            proximoElemento = proximoElemento->next;
        }
    }
}

//------------------------------------------------------------------------------
// Insere um elemento no final da fila.
// Condicoes a verificar, gerando msgs de erro:
// - a fila deve existir
// - o elemento deve existir
// - o elemento nao deve estar em outra fila
// Retorno: 0 se sucesso, <0 se ocorreu algum erro

int queue_append (queue_t **queue, queue_t *elem) 
{
    if (*queue == NULL )
    {
        elem->next = elem;
        elem->prev = elem;
        *queue = elem;
        return 0;
    }
    if (elem == NULL)
    {
        return -1;
    }
    if (*queue == elem)
    {
        return -1;
    }
    queue_t *proximoElemento = (*queue)->next;
    while(1 == 1)
    {
        if(elem == proximoElemento)
            return 1;

        if(proximoElemento == (*queue))
            break;

        proximoElemento = proximoElemento->next;            
    }

    elem->next = *queue;
    (*queue)->prev->next = elem;
    elem->prev = (*queue)->prev;
    (*queue)->prev = elem;
    
    return 0;
}

//------------------------------------------------------------------------------
// Remove o elemento indicado da fila, sem o destruir.
// Condicoes a verificar, gerando msgs de erro:
// - a fila deve existir
// - a fila nao deve estar vazia
// - o elemento deve existir
// - o elemento deve pertencer a fila indicada
// Retorno: 0 se sucesso, <0 se ocorreu algum erro

int queue_remove (queue_t **queue, queue_t *elem) 
{
    if (*queue == NULL || elem == NULL || queue_size(*queue) == 0)
    {
        printf("alguma coisa pelo amor de deus");
        return 1;
    }

    queue_t *proximoElemento = (*queue)->next;
    int contador = 0;
    while(1 == 1)
    {
        printf("----------------%d\n", contador);
        contador++;

        if(elem == proximoElemento)
        {
            printf("Funfa\n");
            break; 
        }
        
        
        if(proximoElemento == (*queue))
        {
            
            return 1;        
        }
            
        proximoElemento = proximoElemento->next;            
    }

    queue_t *elemAnterior = elem->prev;
    queue_t *elemProximo = elem->next;

    elemAnterior->next = elemProximo;
    elemProximo->prev = elemAnterior;

    elem->next = NULL;
    elem->prev = NULL;

    free(elem);
    elem = NULL;
    // elem->prev = NULL;

    // free(elem->next);
    // elem->next = NULL;

    return 0;
}