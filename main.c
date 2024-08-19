#include <stdio.h>

#include "ArvoreBinaria.h"

// Constantes
enum {
    OP_NAO_SELECIONADA = 0,
    OP_ADICIONAR,
    OP_BUSCAR,
    OP_EXCLUIR,
    OP_SAIR
};

// Protótipos
int menu();

int main(void) {
    int opcao = OP_NAO_SELECIONADA;
    int valor = 0;

    inicializar();

    while(opcao != OP_SAIR)
    {
        opcao = menu();
        switch (opcao) {
            case OP_ADICIONAR:
                printf("Digite um numero: ");
                scanf("%d", &valor);
                adicionar(inicio, novoNo(valor));
                break;
            case OP_BUSCAR:
                printf("Digite um numero: ");
                scanf("%d", &valor);
                struct no *p = buscar(inicio, valor);
                if(p==NULL)
                {
                    printf("Nao encontrei!\n");
                }
                else
                {
                    printf("Encontrei %d.\n", p->dado);
                }
                break;
            case OP_EXCLUIR:
                printf("Digite um numero: ");
                scanf("%d", &valor);
                excluir(valor);
                break;
            case OP_SAIR:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }

    finalizar(inicio);
    return 0;
}

int menu()
{
    int op = OP_NAO_SELECIONADA;
    printf("Menu\n");
    printf("%d - Adicionar\n", OP_ADICIONAR);
    printf("%d - Buscar\n", OP_BUSCAR);
    printf("%d - Excluir\n", OP_EXCLUIR);
    printf("%d - Sair\n", OP_SAIR);
    printf("Digite sua opcao: ");
    scanf("%d", &op);

    return op;
}
