
#include <stdio.h>
#include <stdlib.h>

int binary_search(int list[], int item, int left, int right) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
  
        if (list[mid] == item)
            return mid;

        if (list[mid] > item)
            return binary_search(list, left, mid - 1, item);

        return binary_search(list, mid + 1, right, item);
    }

    return -1;
}
  
int main()
{
    int numbers[] = {1, 2, 3, 5, 7, 8, 9, 13, 27, 31, 43, 70};

    printf("%d\n", binary_search(numbers, 5, 0, 12-1));

    return 0;
}