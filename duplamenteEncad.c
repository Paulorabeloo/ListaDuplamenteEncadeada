#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct no
{
    int codigo;
    char nome[30];
    struct no *next, *back;
}no;
    struct no *corrente, *inicio, *fim, *auxiliar, *auxiliar2;

void Exibir()
{
    if(inicio == NULL)
    {
        printf("\n Lista vazia");
        system("pause");
    }else{
        auxiliar = inicio;
        while(auxiliar != NULL)
        {
            printf("\n Codigo: %d", auxiliar->codigo);
            printf("\n Nome: %s\n", auxiliar->nome);
            system("pause");
            auxiliar =auxiliar->next;
        }
        }
    }

void Enterdata()
{
    printf("Informe o codigo:");
    scanf("%d", &corrente->codigo);
    printf("\nInforme o nome:");
    scanf("%s", &corrente->nome);
}

/*void Inserir()
{
    if(inicio==NULL){
        corrente=(no*)malloc(sizeof(no));
        inicio = corrente;
        fim = corrente;
        auxiliar = corrente;
        auxiliar->next=NULL;
        auxiliar->back=NULL;
        Enterdata();
    }else{
        corrente=(no*)malloc(sizeof(no));
        auxiliar->next=corrente;
        corrente->back=auxiliar;
        auxiliar = corrente;
        fim = corrente;
        corrente->next=NULL;
        Enterdata();
    }
}*/

void Classificar()
{
    int achou;
    corrente=(no*)malloc(sizeof(no));
    Enterdata();
    auxiliar=inicio;
    achou = 0;
    if(inicio == NULL){
        fim = corrente;
        inicio = corrente;
        auxiliar = corrente;
        corrente->next=NULL;
        corrente->back=NULL;
        achou = 1;
        printf("\nInstalando o primeiro no na lista");
        system("pause");
    }else{
        if(strcmp(corrente->nome,auxiliar->nome)<0){
            corrente->next=auxiliar;
            inicio = corrente;
            corrente->back=NULL;
            auxiliar->back=corrente;
            achou = 1;
            printf("\nElemento precede o primeiro da lista");
            system("pause");
        }else{
            auxiliar2=auxiliar->next;
            while(auxiliar2 != NULL){
                if(strcmp(corrente->nome,auxiliar->nome)>=0 && (strcmp(corrente->nome,auxiliar2->nome)<=0)){
                    auxiliar->next=corrente;
                    corrente->back=auxiliar;
                    auxiliar2->back=corrente;
                    corrente->next=auxiliar2;
                    achou = 1;
                    printf("\nElemento inserido no meio da lista");
                    system("pause");
                    break;
                }else{
                    auxiliar2=auxiliar2->next;
                    auxiliar=auxiliar->next;
                }
            }
        }
    }
    if(strcmp(corrente->nome,auxiliar->nome)>=0 && (achou == 0)){
        fim->next=corrente;
        corrente->back=fim;
        fim = corrente;
        corrente->next=NULL;
        achou = 1;
        printf("\nElemento inserido no final da lista");
        system("pause");

    }
}


void Consulta()
{
    char xnome[30];
    int achou, k;

    if(inicio == NULL)
    {
        printf("\n Lista vazia...");
        system("pause");
    }else{
        printf("\nInforme o nome a ser consultado:");
        scanf("%s", &xnome);
        achou = 0;
        k = 0;
        auxiliar = fim;
        while(auxiliar != NULL)
        {
            k++;
            if(strcmp(xnome,auxiliar->nome)==0){
                printf("\nRegistro encontrado na posicao %d\n", k);
                system("pause");
                achou = 1;
                break;
            }else{
                auxiliar=auxiliar->back;
            }
        }
        if(achou == 0){
            printf("\nRegistro nao consta na lista");
            system("pause");
        }
    }
}

void Excluir()
{
    char xnome[30];
    int achou, k;

    if(inicio == NULL){
        printf("\nLista vazia...");
        system("pause");
    }else{
        auxiliar = inicio;
        achou = 0;
        printf("\nInforme o nome a ser excluido:");
        scanf("%s", &xnome);

        if(strcmp(xnome,auxiliar->nome)==0){
                inicio=inicio->next;
                inicio->back=NULL;
                free(auxiliar);
                achou = 1;
                printf("\nRegistro excluido com sucesso <<Inicio da lista>>");
                system("pause");
            }else{
                corrente=auxiliar->next;
                while(corrente != NULL)
                {
                    if(strcmp(xnome,auxiliar->nome)==0){
                        corrente->back=auxiliar->back;
                        corrente=corrente->back;
                        corrente->next=auxiliar->next;
                        free(auxiliar);
                        printf("\nRegistro excluido com sucesso <<meio & fim>>");
                        system("pause");
                        achou = 1;
                        break;
                    }else{
                        auxiliar=auxiliar->next;
                        corrente=corrente->next;
                    }
                }
            }
        }
                if(strcmp(xnome, auxiliar->nome)==0 && achou == 0){
                    fim=fim->back;
                    fim->next=NULL;
                    printf("\nElemento foi removido com sucesso no fim da lista");
                    system("pause");
                    free(auxiliar);
                    achou = 1;
                }
                if(achou==0){
                    printf("\nO elemento nao esta na lista");
                    system("pause");
                }
}

void Alterar()
{
    char xnome[30];
    int achou, k;

    if(inicio == NULL)
    {
        printf("\n Lista vazia...");
        system("pause");
    }else{
        printf("\nInforme o nome a ser alterado:");
        scanf("%s", &xnome);
        achou = 0;
        k = 0;
        auxiliar = inicio;
        while(auxiliar != NULL)
        {
            k++;
            if(strcmp(xnome,auxiliar->nome)==0){
                printf("\nRegistro encontrado na posicao %d\n", k);
                printf("\nInforme o novo nome:");
                scanf("%s", auxiliar->nome);
                printf("\nRegistro atualizado com sucesso");
                system("pause");
                achou = 1;
                break;
            }else{
                auxiliar=auxiliar->next;
            }
        }
        if(achou == 0){
            printf("\nRegistro nao consta na lista");
            system("pause");
        }
    }
}

int main()
{
    auxiliar = NULL;
    corrente = NULL;
    inicio = NULL;
    int op;
    do{
        system("cls");
        printf(" [1] Inclui elementos na lista");
        printf("\n [2] Exibir os elementos da lista");
        printf("\n [3] Pesquisar elemento da lista");
        printf("\n [4] Remove elementos da lista");
        printf("\n [5] Altera elementos da lista");
        printf("\nDigite a opcao desejada:");
        scanf("%d", &op);
    switch(op)
    {
    case 1:
    Classificar();
    break;

    case 2:
    Exibir();
    break;

    case 3:
    Consulta();
    break;

    case 4:
    Excluir();
    break;

    case 5:
    Alterar();
    break;

    default :
        printf("\nOpcao invalida ... Tente novamente");
        system("pause");

    }
        }while(op != 6);
}
