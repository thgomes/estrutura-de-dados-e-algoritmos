#include <stdio.h>
#include <stdlib.h>

void radixsort(int list[], int len) {
    int *b;
    int bigger = list[0];
    int exp = 1;

    b = (int *)calloc(len, sizeof(int));

    for (int i = 0; i < len; i++) {
        if (list[i] > bigger)
    	    bigger = list[i];
    }

    while (bigger / exp > 0) {
        int bucket[10] = { 0 };

    	for (int i = 0; i < len; i++) {
    	    bucket[(list[i] / exp) % 10]++;
        }

    	for (int i = 1; i < 10; i++) {
    	    bucket[i] += bucket[i - 1];
        }

    	for (int i = len - 1; i >= 0; i--) {
    	    b[--bucket[(list[i] / exp) % 10]] = list[i];
        }

    	for (int i = 0; i < len; i++) {
    	    list[i] = b[i];
        }

    	exp *= 10;
    }

    free(b);
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

    radixsort(list, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }

    printf("\n");
    
    return 0;
}