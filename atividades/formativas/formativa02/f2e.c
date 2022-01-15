#include <stdio.h>
#include <string.h>

int conta(char str[15], int n) {
    if (n == 0) {
        if (str[0] == '7') return 1;
        
        return 0;
    }

    if (str[n] == '7') return 1 + conta(str, n - 1);
    
    return conta(str, n - 1);    
}

int main()
{
    char str[15];
    int n, x;

    scanf("%s", str);

    n = strlen(str);
    n -= 1;

    x = conta(str, n);
    printf("%d\n", x);

    return 0;
}

