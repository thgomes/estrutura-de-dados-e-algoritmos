#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int coluna;
  int valor;
  struct celula *prox;
} celula;

celula *cria_lista () {
    celula *le = malloc(sizeof (celula));
    le->prox = NULL;
    return le;
}

int insere (celula *elem, int coluna, int valor) {
    celula *novo = malloc (sizeof(celula));
    if (novo == NULL) return 0;
    novo->coluna = coluna;
    novo->valor = valor;
    novo->prox = elem->prox;
    elem->prox = novo;
    return 1;
}

int multiplica (celula *le, int *v) {
    int soma =  0;
    if (le != NULL)
        for (celula *elem = le->prox; elem != NULL; elem = elem->prox)
            soma = soma + elem->valor * v[elem->coluna];
    return soma;
}

int main () {
    int m, n, linha = 0, coluna = 0, valor = 0;
    
    scanf("%d %d", &m, &n);

    celula* matriz = (celula*) malloc(sizeof(celula) * m);
    int* v = (int*) malloc(sizeof(int) * n);

    for (int i = 0; i < m; i++)
        matriz[i] = *cria_lista();

    while (linha != -1 || coluna != -1 || valor != -1) {
        scanf("%d %d %d", &linha, &coluna, &valor);
        insere(&matriz[linha], coluna, valor);
    }

    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    
    for (int i = 0; i < m; i++)
        printf("%d\n", multiplica(&matriz[i], v));
}





