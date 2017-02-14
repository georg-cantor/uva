#include <stdio.h>

long long memo[10000]; // adjust to however big you need, but the result must fit in an int
                 // and keep in mind that fibonacci values grow rapidly :)

long long fibonacci(int n) {
  if (memo[n] != -1)
    return memo[n];

  if (n==1 || n==2)
    return 1;
  else
    return memo[n] = fibonacci(n-1) +fibonacci(n-2);
}
int main() {
  for(int i = 0; i < 10000; ++i)
    memo[i] = -1;
  printf("%lld\n", fibonacci(50));
  /*
  for (int i = 0; i < 10000; i++)
  {
    if (memo[i] == -1)
      break;
    printf("%d", memo[i]);
  }
  printf("\n");
  */
  return 0;
}