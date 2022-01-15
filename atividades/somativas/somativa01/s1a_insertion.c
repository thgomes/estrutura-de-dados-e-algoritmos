#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int list[], int len) {
    int key, j;
    for (int i = 1; i < len; i++) {
        key = list[i];
        j = i -1;
        while (j >= 0 && list[j] > key) {
            list[j+1] = list[j];
            j -= 1;
        }
        list[j+1] = key;
    }
}

int main()
{ 
    int n;
    int* list;

    scanf("%d", &n);

    list = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf(" %d", &list[i]);
    }

    insertion_sort(list, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }

    printf("\n");
    
    return 0;
}