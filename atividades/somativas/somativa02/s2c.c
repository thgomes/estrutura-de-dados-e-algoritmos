#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
	char dado[105];
    struct celula *prox;
} celula;

celula *criar_lista () {
    celula *le = malloc(sizeof (celula));
    le->prox = NULL;
    return le;
}

int empilha (celula *p, char *x) {
	celula *novo = malloc (sizeof(celula));
	if (novo == NULL) return 0;
    strcpy(novo->dado, x);
	novo->prox = p->prox;
	p->prox = novo;
	return 1;
}		

int desempilha (celula *p) {
	celula *lixo = p->prox;
	if (lixo == NULL) {
        printf("NULL\n");
        return 0;
    }
	p->prox = lixo->prox;
    printf("%s\n", lixo->dado);
	free(lixo);
	return 1;
}

int main () {
    char comando[10];
    char texto[105];

    celula *le = criar_lista();

    while (scanf("%s", comando) == 1) {
        if (comando[0] == 'i') {
            scanf(" %[^\n]s", texto);
            empilha(le, texto);
        } else if (comando[0] == 'd') {
            desempilha(le);
        }
    }
}





