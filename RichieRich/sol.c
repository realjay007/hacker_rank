#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  int n, k, i, j, a, b;
  int it_num = 0;
  scanf("%d %d\n", &n, &k);
  char* num = (char*) malloc((n+1)*sizeof(char));
  int ini_palin[(n+1)/2];
  scanf("%s", num);
  
  for(i = 0; i < n/2.0; ++i) {
    a = num[i] - '0';
    b = num[n-i-1] - '0';
    if(a == b) {
      ini_palin[i] = 1;
    }
    else {
      ini_palin[i] = 0;
      j = a > b? a : b;
      num[i] = num[n-i-1] = j + '0';
      ++it_num;
    }
  }
  
  // printf("%s\n", num);
  
  if(it_num <= k) {
    for(i = 0; i < n/2.0 && it_num < k; ++i) {
      if(num[i] == '9') continue;
      if(ini_palin[i] == 0) {
        num[i] = num[n-i-1] = '9';
        ++it_num;
      }
      else if(k - it_num > 1) {
        num[i] = num[n-i-1] = '9';
        it_num += 2;
      }
    }
    printf("%s\n", num);
  }
  else {
    printf("-1\n");
  }
  
  free(num);
  
  return 0;
}
