#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
	int dado;
    struct celula *prox;
} celula;

celula *criar_lista () {
    celula *le = malloc(sizeof (celula));
    le->prox = le;
    return le;
}

void enfileira (celula **le, int x) {
    celula *novo = malloc(sizeof(celula));
    novo->prox = (*le)->prox;
    (*le)->prox = novo;
    (*le)->dado = x;
    *le = novo;
}

int desenfileira (celula *f, int *y) {
	celula *lixo = f->prox;
	if (lixo == NULL) return 0;
	f->prox = lixo->prox;
	*y = lixo->dado;
	free(lixo);
	return 1;
}

int main () {
    int n, lixo;
    int *a;

    celula *le = criar_lista();

    scanf("%d", &n);

    a = (int*)malloc(n * sizeof(int));

    for (int i = 1; i <= n; i++) {
        enfileira(&le, i);
    }

    int j = 0;
    while (le->prox->prox != le) {
        desenfileira(le, &lixo);
        a[j] = lixo;
        desenfileira(le, &lixo);
        enfileira(&le, lixo);
        j++;
    }
    
    printf("Cartas descartadas:");
    for (int i = 0; i < n-2; i++)
        printf(" %d,", a[i]);
    printf(" %d\n", a[n-2]);

    printf("Carta restante: %d\n", le->prox->dado);
}





/*
void empilha (celula *le, celula *novo) {
	novo->prox = NULL;
	if (le->prox == NULL)
		le->prox = novo;
	else
		for (celula *elem = le->prox; elem != NULL; elem = elem->prox) 
			if (elem->prox == NULL) {
				elem->prox = novo;
                break;
            }
}	
*/