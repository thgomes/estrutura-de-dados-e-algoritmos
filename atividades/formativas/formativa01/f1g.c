#include <stdio.h>

int main()
{
    int n, spaces, asterisks;

    scanf("%i", &n);

    spaces = n - 1;
    asterisks = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }
        
        for (int k = 0; k < asterisks; k++) {
            printf("*");
        }

        asterisks += 2;
        spaces -= 1;
    
        printf("\n");
    }

  return 0;
}