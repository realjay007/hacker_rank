#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void fillMin(int* b, int* a, int i, int j) {
	int index, s = i;
	if(j-i == 1) {
		b[0] = a[i];
		b[1] = a[j];
		return;
	}
	for(b[0] = a[i]; i <= j; ++i) {
		if(a[i] < b[0]) {
			index = i;
			b[0] = a[i];
		}
	}
	i = s;
	for(b[1] = (index == i)? a[++i] : a[i]; i <= j; ++i) {
		if(i == index) continue;
		if(a[i] < b[1]) {
			b[1] = a[i];
		}
	}
}

int main() {
  freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int n, i, j, k, max = 0;
  scanf("%d", &n);
  int a[n], b[2];
  for(i = 0; i < n; ++i) scanf("%d", &a[i]);
  for(i = 0; i < n-1; ++i) {
    for(j = i+1; j < n; ++j) {
      fillMin(b, a, i, j);
			k = b[0] ^ b[1];
      max = (k > max)? k : max;
    }
  }
  
  printf("%d\n", max);
  
  return 0;
}
