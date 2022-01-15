#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
	char dado;
    struct celula *prox;
} celula;

celula *cria_lista () {
    celula *le = malloc(sizeof (celula));
    le->prox = NULL;
    return le;
}

int empilha (celula *p, char x) {
	celula *novo = malloc (sizeof(celula));
	if (novo == NULL) return 0;
	novo->dado = x;
	novo->prox = p->prox;
	p->prox = novo;
	return 1;
}		

int desempilha (celula *p, char *y) {
	celula *lixo = p->prox;
	if (lixo == NULL) return 0;
	p->prox = lixo->prox;
	*y = lixo->dado;
	free(lixo);
	return 1;
}

int main () {
    char expressao[600];
    char x;
    int tamanho, validacao = 1;

    celula *le = cria_lista();

    scanf("%s", expressao);
    tamanho = strlen(expressao);

    for (int i = 0; i < tamanho; i++) {
        if (expressao[i] == '(' || expressao[i] == '{' || expressao[i] == '[') {
            empilha(le, expressao[i]);
        } else if (expressao[i] == ')') {
            if (desempilha(le, &x) == 0 || x != '(') {
                validacao = 0;
                break;
            }
        } else if (expressao[i] == '}') {
            if (desempilha(le, &x) == 0 || x != '{') {
                validacao = 0;
                break;
            }
        } else if (expressao[i] == ']') {
            if (desempilha(le, &x) == 0 || x != '[') {
                validacao = 0;
                break;
            }
        }
    }

    if (le->prox != NULL)
        validacao = 0;
        
    if (validacao == 1)
        printf("sim\n");
    else
        printf("nao\n");
}





