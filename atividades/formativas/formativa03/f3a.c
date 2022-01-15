#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

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
