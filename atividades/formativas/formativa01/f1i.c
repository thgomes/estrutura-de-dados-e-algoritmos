#include <stdio.h>

int main()
{
    int m = 1, n = 1, soma = 0, teste = 1;

    while (m != 0) {
        scanf("%d", &m);

        if (m == 0) {
            break;
        }

        for (int i = 0; i < m; i++) {
            scanf("%d", &n);

            soma += n;
        }

        printf("Teste %d\n", teste);
        printf("%d\n\n", soma);

        soma = 0;
        teste += 1;
    }

  return 0;
}