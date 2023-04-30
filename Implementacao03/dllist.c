#include "dllist.h"
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct _dlnode_{
    void *dado;
    struct _dlnode_ *proximo,*anterior;
}DLNode;

typedef struct _dllist_{
    DLNode *primeiro;
    DLNode *atual;
 }DLList;

typedef struct _funcionario_{
    char nome[30];
    int idade;
    char cargo[30];
    int ID;
    float salario;
}Funcionario;

DLList *dllCriar(){
	DLList *l;
	l=(DLList *)malloc(sizeof(DLList));
	if(l!=NULL){
		l->primeiro=NULL;
		l->atual=NULL;
		return l;
	}
	return NULL;
}


int dllInserirComoUltimo( DLList *l,void *item){
	DLNode *ultimo,*novo_no;
	if(l!=NULL){
		novo_no=(DLNode *) malloc(sizeof(DLNode));
		if(novo_no!=NULL){
			novo_no->dado=item;
			novo_no->proximo=NULL;
			if(l->primeiro !=NULL){
				ultimo = l->primeiro;
				while(ultimo->proximo!=NULL){
					ultimo=ultimo->proximo;
				}
				ultimo->proximo=novo_no;
				novo_no->anterior=ultimo;
			}else{
				l->primeiro=novo_no;
				novo_no->anterior= NULL;
			}
			return TRUE;
		}
	}
	return FALSE;
}


void *dllBuscar(DLList *l,	void *chave, int (*cmp)(void *, void *))
{
    void *dado;
    DLNode *atual;

    if(l != NULL)
    {
        if(l->primeiro != NULL)
        {
            atual = l->primeiro;
            while(atual->proximo != NULL && cmp(chave, atual->dado) != TRUE)
            {
                atual = atual->proximo;
            }
            if(cmp(chave, atual->dado) == TRUE)
            {
                return atual->dado;
            }
        }
    }
    return NULL;
}

void *dllPegarPrimeiro(DLList *l)
{
    void *dado;
    if(l !=	NULL)
    {
        if (l->primeiro != NULL)
        {
            l->atual = l->primeiro;
			dado = l->atual->dado;
            return dado;
        }
    }
    return NULL;
}

void *dllPegarProximo(DLList *l)
{
    void *dado;
    if(l !=	NULL)
    {
        if (l->atual != NULL)
        {
            l->atual = l->atual->proximo;
            dado = l->atual->dado;
            return dado;
        }
    }
    return NULL;
}


void *dllRetirarEspecifico(DLList *l, void *chave, int (*cmp)(void *, void *))
{
    void *dado;
    DLNode *atual, *anterior,*especifico,*proximo;

    if(l != NULL)
    {
        if(l->primeiro != NULL)
        {
            especifico = l->primeiro;
            anterior = NULL;
            while(especifico->proximo != NULL && cmp(chave, especifico->dado) != TRUE)
            {
                especifico = especifico->proximo;
            }

            if(cmp(chave, especifico->dado) == TRUE)
            {
                dado = especifico->dado;
                proximo=especifico->proximo;
                anterior=especifico->anterior;

                if(anterior!=NULL)
                {
                    anterior->proximo = proximo;
                }
                else
                {
                    l->primeiro = proximo;
                }
                if(proximo!=NULL){
                	proximo->anterior=anterior;
				}

                free(especifico);
                return dado;
            }
        }
    }
    return NULL;
}

int dllEsvaziar(DLList *l)
{
    DLNode *atual, *proximo;
    if(l != NULL)
    {
        if(l->primeiro != NULL)
        {
            atual = l->primeiro;
            proximo = atual->proximo;
            free(atual);
            while(proximo != NULL)
            {
                atual = proximo;
                proximo = atual->proximo;
                free(atual);
            }

            l->primeiro = NULL;
            return TRUE;
        }
    }
    return FALSE;
}

int dllDestruir(DLList *l)
{
    if(l != NULL)
    {
        if(l->primeiro == NULL)
        {
            free(l);
            return TRUE;
        }
    }
    return FALSE;
}


int cmpNome(void *chave, void *item)
{
    char *chave_nome;
    Funcionario *item_no;

    chave_nome = (char *)chave;
    item_no = (Funcionario *)item;

    if (strcmp(chave_nome,item_no->nome) == FALSE) {
        return TRUE;
    }
    else{
        return FALSE;
    }
}

int cmpID(void *chave, void *item)
{
    int *chave_ID;
    Funcionario *item_no;

    chave_ID = (int *)chave;
    item_no = (Funcionario *)item;

    if (*chave_ID == item_no->ID)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int cmpSalario(void *chave, void *item)
{
    float *chave_salario;
    Funcionario *item_no;

    chave_salario = (float *)chave;
    item_no = (Funcionario *)item;

    if (*chave_salario == item_no->salario)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}



