#include <stdio.h>

int main()
{
    int n[4];
    int maior;

    scanf("%i %i %i %i", &n[0], &n[1], &n[2], &n[3]);

    maior = n[0];
    for (int i = 0; i < 4; i++) {
        if (n[i] > maior) {
            maior = n[i];
        }
    }

    printf("%i\n", maior);

  return 0;
}