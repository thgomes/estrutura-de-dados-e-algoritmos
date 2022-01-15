#include <stdio.h>

int main()
{
    int n, v;

    scanf("%i", &n);

    if (n <= 10) {
        v = 7;
    } else if (n <=30) {
        v = 7 + (n - 10);
        
    } else if (n <= 100) {
        v = 27 + (n - 30) * 2;

    } else {
        v = 167 + (n - 100) * 5;
    }

    printf("%i\n", v);

  return 0;
}