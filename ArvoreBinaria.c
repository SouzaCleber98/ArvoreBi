
#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

// Variáveis
struct no *inicio;
struct no *anterior;

// Funções
void inicializar()
{
    inicio = NULL;
}

void finalizar(struct no *quem)
{
    if(quem != NULL) {
        if (quem->esquerda != NULL) {
            printf("Processado o lado esquerdo de %d\n", quem->dado);
            finalizar(quem->esquerda);
        }
        if (quem->direita != NULL) {
            printf("Processado o lado direito de %d\n", quem->dado);
            finalizar(quem->direita);
        }
        printf("Excluindo %d\n", quem->dado);
        free(quem);
    }
}

void adicionar(struct no *aonde, struct no *quem)
{
    if(inicio == NULL)
    {
        printf("Adicionando %d no inicio\n", quem->dado);
        inicio = quem;
    }
    else
    {
        if(quem->dado > aonde->dado)
        {
            // processar lado direito
            if(aonde->direita == NULL)
            {
                printf("Adicionando %d a direita de %d\n", quem->dado, aonde->dado);
                aonde->direita = quem;
            }
            else
            {
                printf("Indo para a direita de %d\n", aonde->dado);
                adicionar(aonde->direita, quem);
            }
        }
        else
        {
            // processar lado esquerdo
            if(aonde->esquerda == NULL)
            {
                printf("Adicionando %d a esquerda de %d\n", quem->dado, aonde->dado);
                aonde->esquerda = quem;
            }
            else
            {
                printf("Indo para a esquerda de %d\n", aonde->dado);
                adicionar(aonde->esquerda, quem);
            }
        }
    }
}

struct no *novoNo(int dado)
{
    struct no *p = malloc(sizeof(struct no));
    if(!p)
    {
        printf("Erro de alocacao de memoria\n");
        exit(EXIT_FAILURE);
    }
    p->esquerda = NULL;
    p->dado = dado;
    p->direita = NULL;

    return p;
}

struct no *buscar(struct no * aonde, int dado)
{
    if(inicio == NULL)
    {
        return NULL;
    }
    else
    {
        if(aonde == inicio)
        {
            anterior = inicio;
        }
        if(aonde->dado == dado)
        {
            return aonde;
        }
        else
        {
            anterior = aonde;
            if(dado > aonde->dado)
            {
                // direito
                if(aonde->direita != NULL)
                {
                    return buscar(aonde->direita, dado);
                }
                else
                {
                    return NULL;
                }
            }
            else
            {
                // esquerdo
                if(aonde->esquerda != NULL)
                {
                    return buscar(aonde->esquerda, dado);
                }
                else
                {
                    return NULL;
                }
            }
        }
    }
}

void excluir(int dado)
{
    struct no *p = buscar(inicio, dado);
    if(p != NULL)
    {
        if(p == inicio)
        {
            inicio = NULL;
        }
        else {
            if (p->dado > anterior->dado) {
                anterior->direita = NULL;
            } else {
                anterior->esquerda = NULL;
            }
        }
        if(p->esquerda != NULL)
        {
            adicionar(inicio, p->esquerda);
        }
        if(p->direita != NULL)
        {
            adicionar(inicio, p->direita);
        }
        free(p);
    }
}