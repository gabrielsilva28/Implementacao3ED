#include "dllist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define TRUE 1
#define FALSE 0

typedef struct _funcionario_{
    char nome[30];
    int idade;
    char cargo[30];
    int ID;
    float salario;
}Funcionario;

int main()
{
    int qtd_insercoes = 0, opcao;
    DLList *lista = NULL;

    do
    {
        opcao = 0;
        printf("Selecione uma opcao:\n1 - Criar a lista\n2 - Inserir um item na lista\n3 - Buscar um item da lista\n4 - Remover um item da lista\n5 - Exibir os itens da lista\n6 - Esvaziar a lista\n7 - Destruir a lista\n8 - Sair do programa\n");
        scanf("%d", &opcao);
        fflush(stdin);
        printf("\n");
        switch(opcao)
        {
            case 1:
                if(lista == NULL)
                {
                    lista = dllCriar();
                    if(lista != NULL)
                    {
                        printf("Lista criada com sucesso!\n");
                    }
                    else
                    {
                        printf("Erro ao criar lista!\n");
                    }
                }
                else
                {
                    printf("A lista ja foi criada!\n");
                }
                break;
            case 2:
                if(lista != NULL)
                {
                    Funcionario *funcionario = (Funcionario *)malloc(sizeof(Funcionario));
                    if(funcionario != NULL)
                    {
                        printf("Insira o nome do funcionario: \n");
                        fgets(funcionario->nome, 30, stdin);
                        printf("Insira o cargo do funcionario: \n");
                        fgets(funcionario->cargo, 30, stdin);
                        printf("Insira a idade do funcionario: \n");
                        scanf("%d", &funcionario->idade);
                        printf("Insira o ID do funcionario: \n");
                        scanf("%d", &funcionario->ID);
                        printf("Insira o salario para o funcionario:\n");
                        scanf("%f", &funcionario->salario);
                        if(dllInserirComoUltimo(lista, (void *)funcionario) == FALSE)
                        {
                            printf("Erro ao inserir funcionario!\n");
                        }
                        else
                        {
                            printf("Funcionario adicionado com sucesso!\n");
                            qtd_insercoes++;
                        }
                    }
                }
                else
                {
                    printf("A lista nao foi criada!\n");
                }
                break;
                
                     
            case 3:
                if(lista != NULL)
                {
                    Funcionario *a;
                    int opcao_interna;
                    printf("Deseja buscar o item pelo nome, ID ou salario?\n1 - Nome\n2 - ID\n3 - Salario\n");

                    scanf("%d", &opcao_interna);
                    printf("\n");

                    switch(opcao_interna)
                    {
                        case 1: ;
                            char nome[30];
                    		printf("Digite o nome:\n");
                    		fgets(nome, 30, stdin);
                    		fgets(nome, 30, stdin);

                            a = (Funcionario *)dllBuscar(lista, (void *)&nome, cmpNome);
                            if(a != NULL)
                            {
                                printf("\nInformacoes do funcionario:\n\nNome: %sIdade: %d \nCargo: %sID: %d \nSalario: %.2f\n", a->nome, a->idade, a->cargo, a->ID, a->salario);
                            }
                            else
                            {
                                printf("\nFuncionario nao encontrado ou lista vazia!\n");
                            }
                            break;
                        case 2: ;
                            int ID;

                            printf("Digite o ID do Funcionario:\n");
                            scanf("%d", &ID);
							a = (Funcionario *)dllBuscar(lista, (void *)&ID, cmpID);
                            if(a != NULL)
                            {
                                printf("\nInformacoes do funcionario:\n\nNome: %sIdade: %d \nCargo: %sID: %d \nSalario: %.2f\n", a->nome, a->idade, a->cargo, a->ID, a->salario);
                            }
                            else
                            {
                                printf("\nFuncionario nao encontrado ou lista vazia!\n");
                            }
                    		
                            break;
                        case 3: ;
                        	float salario;

                            printf("Digite o salario:\n");
                            scanf("%f", &salario);
                            a = (Funcionario *)dllBuscar(lista, (void *)&salario, cmpSalario);
                            if(a != NULL)
                            {
                                printf("\nInformacoes do funcionario:\n\nNome: %sIdade: %d \nCargo: %sID: %d \nSalario: %.2f\n", a->nome, a->idade, a->cargo, a->ID, a->salario);
                            }
                            else
                            {
                                printf("\nFuncionario nao encontrado ou lista vazia!\n");
                            }
                        	
                            break;
                    		
                        default:
                            printf("Opcao invalida!\n");
                    }
                }
                else
                {
                    printf("A lista nao foi criada!\n");
                }
                break;
                
            case 4:
                if(lista != NULL)
                {
                    Funcionario *a;
                    int opcao_interna = 0;
                    printf("Deseja remover o item pelo nome, ID ou salario?\n1 - Nome\n2 - ID\n3 - Salario\n");   
                    scanf("%d", &opcao_interna);
                    fflush(stdin);
                    
                    printf("\n");

                    switch(opcao_interna)
                    {
                        case 1: ;
                            char nome[30];
                    		printf("Digite o nome:\n");
                    		fgets(nome, 30, stdin);
                            a = (Funcionario *)dllRetirarEspecifico(lista, (void *)&nome, cmpNome);
                            if(a != NULL)
                            {
                                qtd_insercoes--;
                                printf("\nInformacoes do funcionario removido:\n\nNome: %sIdade: %d \nCargo: %sID: %d \nSalario: %.2f\n", a->nome, a->idade, a->cargo, a->ID, a->salario);
                            }
                            else
                            {
                                printf("Funcionario nao encontrado ou lista vazia!\n");
                            }
                            break;
                        case 2: ;
                            int ID;
                            printf("Digite o ID:\n");
                            scanf("%d", &ID);
                            a = (Funcionario *)dllRetirarEspecifico(lista, (void *)&ID, cmpID);
                            if(a != NULL)
                            {
                                qtd_insercoes--;
								printf("\nInformacoes do funcionario removido:\n\nNome: %sIdade: %d \nCargo: %sID: %d \nSalario: %.2f\n", a->nome, a->idade, a->cargo, a->ID, a->salario);
                            }
                            else
                            {
                                printf("Funcionario nao encontrado ou lista vazia!\n");
                            }
                            break;
                        case 3: ;
                        	float salario;
                            printf("Digite o salario:\n");
                            scanf("%f", &salario);
                            a = (Funcionario *)dllRetirarEspecifico(lista, (void *)&salario, cmpSalario);
                            if(a != NULL)
                            {
                                qtd_insercoes--;
                                printf("\nInformacoes do funcionario removido:\n\nNome: %sIdade: %d \nCargo: %sID: %d \nSalario: %.2f\n", a->nome, a->idade, a->cargo, a->ID, a->salario);
                            }
                            else
                            {
                                printf("Funcionario nao encontrado ou lista vazia!\n");
                            }
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                }
                else
                {
                    printf("A lista nao foi criada!\n");
                }
                break;
            case 5:
                if(lista != NULL)
                {
                    Funcionario *a;
                    a = (Funcionario *)dllPegarPrimeiro(lista);
                    if(a != NULL)
                    {
                       printf("\nInformacoes do funcionario:\n\nNome: %sIdade: %d \nCargo: %sID: %d \nSalario: %.2f\n", a->nome, a->idade, a->cargo, a->ID, a->salario);
                        for(int i = 1; i < qtd_insercoes; i++)
                        {
                            a = (Funcionario *)dllPegarProximo(lista);
                            if(a != NULL)
                            {
                                printf("\nInformacoes do funcionario:\n\nNome: %sIdade: %d \nCargo: %sID: %d \nSalario: %.2f\n", a->nome, a->idade, a->cargo, a->ID, a->salario);
                            }
                        }
                    }
                    else
                    {
                        printf("A lista esta vazia!\n");
                    }
                }
                else
                {
                    printf("A lista nao foi criada!\n");
                }
                break;
            case 6:
                if(lista != NULL)
                {
                    if(dllEsvaziar(lista) == FALSE)
                    {
                        printf("A lista ja esta vazia!\n");
                    }
                    else
                    {
                        qtd_insercoes = 0;
                        printf("Lista esvaziada com sucesso!\n");
                    }
                }
                else
                {
                    printf("A lista nao foi criada!\n");
                }
                break;
            case 7:
                if(lista != NULL)
                {
                    if(dllDestruir(lista) == FALSE)
                    {
                        printf("A lista nao esta vazia! Esvazie-a antes de destruir\n");
                    }
                    else
                    {
                        lista = NULL;
                        printf("Lista destruida com sucesso!\n");
                    }
                }
                else
                {
                    printf("A lista nao foi criada!\n");
                }
                break;
            case 8:
                dllEsvaziar(lista);
                dllDestruir(lista);
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
        printf("\n");
    }while(opcao != 8);

    return 0;
}


