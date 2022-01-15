#include <stdio.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

int desenfileira (celula *f, int *y) {
	celula *lixo = f->prox;
	if (lixo == NULL) return 0;
	f->prox = lixo->prox;
	*y = lixo->dado;
	free(lixo);
	return 1;
}
