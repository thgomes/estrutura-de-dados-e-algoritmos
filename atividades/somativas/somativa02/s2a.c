#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  char matricula[10];
  double mediaAtividades;
  double mediaProvas;
  struct celula *prox;
} celula;

void relatorioMediaAtividades (celula *le, celula *l1, celula *l2, double media) { 
    celula *elemL1 = l1;
    celula *elemL2 = l2;
    for (celula *elem = le->prox; elem != NULL; elem = elem->prox) {
        if (elem->mediaAtividades > media) {
            elemL2->prox = elem;
            elemL2 = elemL2->prox;
        } else if (elem->mediaAtividades <= media) {
            elemL1->prox = elem;
            elemL1 = elemL1->prox;
        }
	}
    elemL1->prox = NULL;
    elemL2->prox = NULL;
}
