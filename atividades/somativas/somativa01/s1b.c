#include <stdio.h>
#include <stdlib.h>

struct Number {
    int value;
    int index;
};

typedef struct Number Number;

void merge(Number lista[], int inicio, int meio, int fim) {
    int len_left = meio - inicio;
    int len_right = fim - meio;
    Number left[len_left], right[len_right];
    int top_left = 0, top_right = 0;

    for (int i = 0; i < len_left; i++) {
        left[i].value = lista[inicio + i].value;
        left[i].index = lista[inicio + i].index;
    }
    for (int j = 0; j < len_right; j++) {
        right[j].value = lista[meio + j].value;
        right[j].index = lista[meio + j].index;
    }

    for (int k = inicio; k < fim; k++) {
        if (top_left >= len_left) {
            lista[k].value = right[top_right].value;
            lista[k].index = right[top_right].index;
            top_right++;
        } else if (top_right >= len_right) {
            lista[k].value = left[top_left].value;
            lista[k].index = left[top_left].index;
            top_left++;
        } else if (left[top_left].value < right[top_right].value) {
            lista[k].value = left[top_left].value;
            lista[k].index = left[top_left].index;
            top_left++;
        } else {
            lista[k].value = right[top_right].value;
            lista[k].index = right[top_right].index;
            top_right++;
        }
    }
}

void mergesort(Number lista[], int inicio, int fim) {
    if (fim - inicio > 1) {
        int meio = (fim + inicio) / 2;
        mergesort(lista, inicio, meio);
        mergesort(lista, meio, fim);
        merge(lista, inicio, meio, fim);
    }
}

int binary_search(Number list[], int left, int right, int item) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
  
        if (list[mid].value == item)
            return mid;

        if (list[mid].value > item)
            return binary_search(list, left, mid - 1, item);

        return binary_search(list, mid + 1, right, item);
    }

    return -1;
}
  
int main()
{ 
    int n, m, x, count = 0, y;
    Number nlist[145000];

    scanf("%d %d", &n, &m);

    //Number* nlist = (Number*)malloc(sizeof(Number));

    for (int i = 0; i < n; i++) {
        scanf("%d", &nlist[i].value);
        nlist[i].index = count;
        count++;
    }

    mergesort(nlist, 0, n);

    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        y = binary_search(nlist, 0, n - 1, x);
        if (y == -1) {
            printf("%d\n", -1);
        } else {
            printf("%d\n", nlist[y].index);
        }
    }

    return 0;
}