#include <stdio.h>
#include <stdlib.h>

void merge(int lista[], int inicio, int meio, int fim) {
    int len_left = meio - inicio;
    int len_right = fim - meio;
    int left[len_left], right[len_right];
    int top_left = 0, top_right = 0;

    for (int i = 0; i < len_left; i++) {
        left[i] = lista[inicio + i];
    }

    for (int j = 0; j < len_right; j++) {
        right[j] = lista[meio + j];
    }

    for (int k = inicio; k < fim; k++) {
        if (top_left >= len_left) {
            lista[k] = right[top_right];
            top_right++;

        } else if (top_right >= len_right) {
            lista[k] = left[top_left];
            top_left++;

        } else if (left[top_left] < right[top_right]) {
            lista[k] = left[top_left];
            top_left++;

        } else {
            lista[k] = right[top_right];
            top_right++;
        }
    }
}

void mergesort(int lista[], int inicio, int fim) {
    int meio;
    if (fim - inicio > 1) {
        meio = (fim + inicio) / 2;
        mergesort(lista, inicio, meio);
        mergesort(lista, meio, fim);
        merge(lista, inicio, meio, fim);
    }
}
  
int main()
{
    int n, x;
    int* an;

    scanf("%d", &n);

    an = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf(" %d", &an[i]);
    }

    mergesort(an, 0, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", an[i]);
    }

    printf("\n");

   return 0;
}