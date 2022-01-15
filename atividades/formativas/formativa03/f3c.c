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

celula *busca_ultimo (celula *le) {
    celula *elemAnterior = le;
    for (celula *elem = le->prox; elem != NULL; elem = elem->prox)
        elemAnterior = elem;
    return elemAnterior;
}

int insere_inicio (celula *le, int x) {
    celula *novo = malloc (sizeof(celula));
    if (novo == NULL) return 0;
    novo->dado = x;
    novo->prox = le->prox;
    le->prox = novo;
    return 1;
}

int insere_final (celula *le, int x) {
    celula *novo = malloc (sizeof(celula));
    celula *ultimo = busca_ultimo(le);
    if (novo == NULL) return 0;
    novo->dado = x;
    novo->prox = NULL;
    ultimo->prox = novo;
    return 1;
}

int insere_antes (celula *le, int x, int y) {
    celula *novo = malloc (sizeof(celula));
    celula *anterior = busca_anterior(le, y);
    if (novo == NULL)
        return 0;
    if (anterior == NULL)
        insere_final(le, x);
    else {
        novo->dado = x;
        novo->prox = anterior->prox;
        anterior->prox = novo;
    }
    return 1;
}
