#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

celula *busca (celula *le, int x) {
    for (celula *elem = le->prox; elem != NULL; elem = elem->prox)
        if (elem->dado == x)
            return elem;
    return NULL;
}

celula *busca_rec (celula *le, int x) {
    celula *elem = le->prox;
    if (elem == NULL)
        return NULL;
    if (elem->dado == x)
        return elem;
    return busca(elem, x);
}

