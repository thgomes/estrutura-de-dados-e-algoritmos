#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

celula *criar_lista () {
    celula *le = malloc(sizeof (celula));
    le->prox = NULL;
    return le;
}

int inserir (celula *elem, int x) {
    celula *novo = malloc (sizeof(celula));
    if (novo == NULL) return 0;
    novo->dado = x;
    novo->prox = elem->prox;
    elem->prox = novo;
    return 1;
}

int remover (celula *elem, int *y) {
    celula *lixo = elem->prox;
    if (lixo == NULL) return 0;
    elem->prox = lixo->prox;
    *y = lixo->dado;
    free(lixo);
    return 1;
}

void imprime (celula *le) {
    if (le != NULL)
        for (celula *elem = le->prox; elem != NULL; elem = elem->prox) {
            printf("%d", elem->dado);
            printf(" -> ");
        }
    printf("NULL\n");
}

void imprime_rec (celula *le) {
    celula *elem = le->prox;
    if (elem != NULL) {
        printf("%d", elem->dado);
        printf(" -> ");
        imprime_rec(elem);
    } else {
        printf("NULL\n");
    }
}

celula *destruir_lista (celula *le) {
    int dado;
    while (remover(le, &dado));
    free(le);
    le = NULL;
    return le;
}

// MENU PARA TESTES
void imprime_menu (int *op) {
    printf("\n\nSelecione uma opcao:\n");
    printf("1 - Criar lista\n");
    printf("2 - Inserir elemento no inicio\n");
    printf("3 - Remover primeiro elemento\n");
    printf("4 - Imprimir lista\n");
    printf("5 - Destruir lista\n");
    printf("0 - Sair\n");
    printf("Digite sua opcao: ");
    scanf("%d", op);
}

int main () {
    int dado, op;
    celula *le;

    imprime_menu(&op);
    while (op != 0) {
        switch (op) {
        case 1:
            le = criar_lista();
            break;

        case 2:
            printf("Digite o novo dado: ");
            scanf("%d", &dado);
            if (inserir(le, dado))
                printf("Elemento inserido com sucesso. \n");
            else {
                printf("Problema na hora de inserir.\n");
                return 1;
            }
            break;

        case 3:
            if (remover(le, &dado))
                printf("Elemento removido: %d.\n", dado);
            else
                printf("A lista esta vazia.\n");
            break;

        case 4:
            imprime(le);
            break;

        case 5:
            le = destruir_lista(le);
        }

        imprime_menu(&op);
    }
}
