#include <stdio.h>

void regua(int n) {
    if (n == 1) {
        printf(".-\n");

    } else {
        regua(n - 1);

        printf(".");
        for (int i = 0; i < n; i++) {
            printf("-");
        }
        printf("\n");

        regua(n - 1);
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    if (n == 0) {
        printf("\n");

    } else {
        regua(n);
    }


    return 0;
}

