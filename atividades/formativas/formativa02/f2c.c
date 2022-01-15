#include <stdio.h>
#include <string.h>

int soma(int n, char str[15]) {
    if (n == 0) return str[0] - '0';

    return str[n] - '0' + soma(n - 1, str);
}

int main()
{
    char str[15];
    int n;

    scanf("%s", str);
    
    n = strlen(str) - 1;
    
    printf("%d\n", soma(n, str));

    return 0;
}

