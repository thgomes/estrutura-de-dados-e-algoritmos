#include <stdio.h>
#include <string.h>

void reverse(char str[510], int n, int len) {
    if (n == len) {
        printf("%c", str[n]);

    } else {
        reverse(str, n + 1, len);
        printf("%c", str[n]);
    }
}

int main()
{
    char str[510];
    int n, len;

    scanf("%s", str);

    len = strlen(str);
    len -= 1;
    n = 0;

    reverse(str, n, len);
    printf("\n");

    return 0;
}

