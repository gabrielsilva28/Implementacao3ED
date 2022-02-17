#ifndef DLLIST_H
#define	DLLIST_H
typedef struct _dllist_ DLList;
typedef struct _dlnode_ DLNode;
typedef struct _funcionario_ Funcionario;

DLList *dllCriar();
int dllInserirComoUltimo( DLList *l,void *item);
void *dllBuscar(DLList *l,	void *chave, int (*cmp)(void *, void *));
void *dllRetirarEspecifico(DLList *l, void *chave, int (*cmp)(void *, void *));
void *dllPegarPrimeiro(DLList *l);
void *dllPegarProximo(DLList *l);
int dllEsvaziar(DLList *l);
int dllDestruir(DLList *l);
int cmpID(void *chave, void *item);
int cmpSalario(void *chave, void *item);
int cmpNome(void *chave, void *item);

#endif
