#include <stdio.h>

int main()
{
    int n = 1, a, b, teste = 1;
    char name1[15], name2[15];

    while (n != 0) {
        scanf("%d", &n);

        if (n == 0) {
            break;
        }

        scanf("%s %s", name1, name2);
        printf("Teste %d\n", teste);

        for (int i = 0; i < n; i++) {
            scanf("%d %d", &a, &b);

            if ((a + b) % 2 == 0) {
                printf("%s\n", name1);
            } else {
                printf("%s\n", name2);
            }
        }

        printf("\n");
        teste++;
    }

  return 0;
}