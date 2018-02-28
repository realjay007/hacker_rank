#include <stdio.h>
#include <stdbool.h>


void rotateMatrix(int n, int a[][n]) {
  if (n <= 1) {
    return; // nothing to do
  }
  int saved;
  int i, j;
  // layers 
  for (i = 0; i < n / 2; i++) {
    // elements 
    for (j = i; j < n - i - 1; j++) {
      saved = a[i][j];
      a[i][j] = a[n - j - 1][i];
      a[n - j - 1][i] = a[n - 1 - i][n - 1 - j];
      a[n - 1 - i][n - 1 - j] = a[j][n - 1 - i];
      a[j][n - 1 - i] = saved;
    }
  }
}

int main() {
  int n, q, i, j;
  long long k;
  scanf("%d %d", &n, &q);
  int h0[n][n], h1[n][n], h;
  int pat[] = {1, 0, 1, 1, 0, 0, 0};
  int ans[4];
  
  for(i = 1; i <= n; ++i) {
    for(j = 1; j <= n; ++j) {
      k = i*j;
      k *= k;
      if(k == 1) h0[i-1][j-1] = h1[i-1][j-1] = false;
      else h0[i-1][j-1] = h1[i-1][j-1] = pat[(k-2)%7];
    }
  }
  ans[0] = ans[1] = ans[2] = ans[3] = 0;
  for(i = 1; i < 4; ++i) {
    rotateMatrix(n, h1);
    for(j = 0; j < n; ++j) {
      for(k = 0; k < n; ++k) {
        if(h0[j][k] != h1[j][k]) ++ans[i];
      }
    }
  }
  
  for(i = 0; i < q; ++i) {
    scanf("%d", &j);
    printf("%d\n", ans[(j/90)%4]);
  }
  
  return 0;
}