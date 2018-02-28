#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

const int mod = 1e9 + 7;

int64_t power(int64_t x, uint64_t y, int mod) {
	int64_t res = 1;
	x %= mod;
	while(y) {
		if(y & 1) res = (res*x) % mod;
		y >>= 1;
		x = (x*x) % mod;
	}
	return res;
}

short valid(char* exp) {
  if(exp[0] == '*' || exp[strlen(exp)-1] == '*') return 0;
  char* p = strstr(exp, "***");
  if(p) return 0;
  else return 1;
}

int main() {
  freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int t, i, j, k;
	short p;
	int64_t temp;
	char* cexp;
  scanf("%d", &t);
  while(t--) {
    char exp[102400];
		int64_t val[51200] = {0};
    scanf("%s", exp);
    if(valid(exp) == 0) {
      printf("Syntax Error\n");
      continue;
    }
    i = 0;
		p = 0;
		cexp = exp;
		sscanf(cexp, "%"SCNd64"%n", &val[i++], &k);
		val[i-1] %= mod;
		cexp += k;
		while(cexp != '\0') {
			if(*cexp == '*') {
				++p;
				++cexp;
				continue;
			}
			else {
				sscanf(cexp, "%"SCNd64"%n", &temp, &k);
				if(p == 1) val[i++] = temp % mod;
				else val[i-1] = power(val[i-1], temp, mod);
				cexp += k;
				p = 0;
			}
		}
		temp = 1;
		for(k = 0; k < i; ++k) {
			temp *= val[k];
			temp %= mod;
		}
		printf("%"PRId64"\n", temp);
  }
  
  return 0;
}
