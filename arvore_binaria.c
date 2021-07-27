#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000000

typedef struct No
{
	int chave;
	struct No *esq;
	struct No *dir;
}No;

typedef struct Arv
{
	No *raiz;
}Arv;

void Inicializar(Arv *arvore);
void Inserir(Arv *arvore, int key);
void Buscar(Arv *arvore);

int main()
{
    clock_t tic = clock();
    Arv arv;

    int i, *v = (int*) malloc(MAX * sizeof(int));

    for (i = 0; i < MAX; i++)
    {
        v[i] = i+1;
    }

    for (i = 0; i < MAX; i++)
    {
        int temp = v[i];
        int randomIndex = rand() % MAX;

        v[i] = v[randomIndex];
        v[randomIndex] = temp;
    }


    Inicializar(&arv);
    for (i = 0; i < MAX; i ++)
    {
        Inserir(&arv, v[i]);
    }

    clock_t toc = clock();
    printf("Tempo gasto: %f segundos\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    for (i = 0; i < 5; i++)
    {
        clock_t c1 = clock();
        Buscar(&arv);
        clock_t c2 = clock();

        printf("Tempo gasto: %f segundos\n", (double)(c2 - c1) / CLOCKS_PER_SEC);
    }

	return 0;
}

void Inicializar(Arv *arvore)
{
    arvore->raiz = NULL;
}

void Inserir(Arv *arvore, int key)
{
    if (arvore->raiz == NULL)
    {
        No *novo = (No*) malloc(sizeof(No));
        novo->chave = key;
        novo->esq = NULL;
        novo->dir = NULL;

        arvore->raiz = novo;
    }
    else
    {
        No *novo = (No*) malloc(sizeof(No));
        novo->chave = key;
        novo->esq = NULL;
        novo->dir = NULL;

        No *aux = arvore->raiz;
        while (aux != NULL)
        {
            if (key >= aux->chave)
            {
                if (aux->dir == NULL)
                {
                    aux->dir = novo;
                    break;
                }
                aux = aux->dir;
            }

            if (key < aux->chave)
            {
                if(aux->esq == NULL)
                {
                    aux->esq = novo;
                    break;
                }
                aux = aux->esq;
            }
        }
    }
}

void Buscar(Arv *arvore)
{
    int key = rand() % 1000000;
    No *aux = arvore->raiz;
    while (aux != NULL)
    {
        if (key > aux->chave)
            aux = aux->dir;
        else if (key < aux->chave)
            aux = aux->esq;
        else
            return;
    }
}
