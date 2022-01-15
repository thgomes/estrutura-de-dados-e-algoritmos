#include <stdio.h>

int main()
{
    int n = 0, maior = 0;

    scanf("%i", &maior);
    while (scanf("%i", &n) == 1) {
        if (maior < n) {
            maior = n;
        }
    }

    printf("%i\n", maior);

  return 0;
}