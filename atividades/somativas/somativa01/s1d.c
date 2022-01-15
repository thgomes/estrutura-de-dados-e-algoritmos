#include <stdio.h>
#include <string.h>

int compare(char str[], char sub[], int strIdx, int n) {
    if (n == 0) {
        if (sub[0] == str[strIdx]) {
            return 1;
        } else {
            return 0;
        }
    }
    if (sub[n] == str[strIdx+n]) {
        return compare(str, sub, strIdx, n-1);
    } else {
        return 0;
    }
}

int first_sub(char str[], char sub[], int lenStr, int lenSub, int n) {
    if (n == lenStr - lenSub) {
        if (compare(str, sub, n, lenSub - 1) == 1)
            return n;

        return -1;
    }

    if (compare(str, sub, n, lenSub - 1) == 1) 
        return n;

    return first_sub(str, sub, lenStr, lenSub,  n + 1);
}

int last_sub(char str[], char sub[], int lenStr, int lenSub, int n) {
    if (n == 0) {
        if (compare(str, sub, n, lenSub - 1) == 1)
            return n;

        return -1;
    }

    if (compare(str, sub, n, lenSub - 1) == 1) 
        return n;

    return last_sub(str, sub, lenStr, lenSub,  n - 1);
}
  
int main()
{ 
    char str[105], sub[105];
    int lenSub, lenStr, firstSub, lastSub;
    
    scanf("%s", str);
    scanf("%s", sub);

    lenStr = strlen(str);
    lenSub = strlen(sub);

    firstSub = first_sub(str, sub, lenStr, lenSub, 0);
    lastSub = last_sub(str, sub, lenStr, lenSub, lenStr - lenSub);

    if (firstSub == -1 && lastSub == -1) {
        printf("%d\n", 0);
        
    } else {
        printf("%d\n", lastSub - firstSub + lenSub);
    }

    return 0;
}