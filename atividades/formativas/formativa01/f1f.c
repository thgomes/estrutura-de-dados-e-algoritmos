#include <stdio.h>

int main()
{
    int n;

    scanf("%i", &n);

    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%02d ", i);
        }
        printf("\n");
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%02d ", j);
        }
        printf("\n");
    }

  return 0;
}