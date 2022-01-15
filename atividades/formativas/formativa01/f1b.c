#include <stdio.h>

int main()
{
    int n = 0;
    int count = 0;

    while (scanf("%i", &n) == 1) {
        count++;
    }

    printf("%i\n", count);

  return 0;
}