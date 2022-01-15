#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

celula *busca_anterior (celula *le, int x) {
    celula *elemAnterior = le;
    for (celula *elem = le->prox; elem != NULL; elem = elem->prox) {
        if (elem->dado == x)
            return elemAnterior;
        elemAnterior = elem;
    }
    return NULL;
}

int remove_depois (celula *p) {
    celula *lixo = p->prox;
    if (lixo == NULL) return 0;
    p->prox = lixo->prox;
    free(lixo);
    return 1;
}

int remove_elemento (celula *le, int x) {
    celula *elem = busca_anterior(le, x);
    remove_depois(elem);
    return 1;
}

int remove_todos_elementos (celula  *le, int x) {
    for (celula *elem = busca_anterior(le, x); elem != NULL; elem = busca_anterior(le, x))
        remove_depois(elem);
    return 1;
}

