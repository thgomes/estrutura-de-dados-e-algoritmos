#include <stdio.h>

float pot(float n, float expo) {
    if (expo == 0) return 1;

    if (expo < 0) return 1 / (n * pot(n, expo * -1 - 1));

    return n * pot(n, expo - 1);
}

int main()
{
  float n, expo;

  scanf("%f %f", &n, &expo);

  if (n == 0 && expo == 0) {
      printf("indefinido\n");

  } else {
      printf("%f\n", pot(n, expo));
  }

  return 0;
}

