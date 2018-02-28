#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>

const int D = 8;
const int MOD = 1e9+7;

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

int main() {

	clock_t t1 = clock();


	int n, i, j, k, l, s;
	int64_t a = 0;
	
	scanf("%d", &n);
	char arr[n];
	int evens[n];
	scanf("%s", arr);
	
	for(i = 0, s = 0; i < n; ++i) {
		// scanf("%1d", &arr[i]);
		arr[i] -= 48;
		arr[i] %= D;
		if(arr[i] % 2 == 0) evens[s++] = i;
	}

	/*
	for(i = 0; i < s; ++i, a %= MOD) {

		if(arr[evens[i]] % D == 0) ++a;

		if(evens[i] > 0) {
			for(j = evens[i]-1; j >= 0; --j) {
				l = arr[j] * 10 + arr[evens[i]];
				if(l % D == 0) ++a;
			}
		}

		if(evens[i] > 1) {
			for(j = evens[i]-1; j > 0; --j) {
				for(k = j-1; k >= 0; --k) {
					l = arr[k] * 100 + arr[j] * 10 + arr[evens[i]];
					if(l % D == 0) {
						a += power(2, k, MOD);
            //printf("%d\n", l);
					}
				}
			}
		}
	}*/

	
	for(i = 0; i < n; ++i, a %= MOD) {
    if(arr[i] % 2 != 0) continue;
    
		if(arr[i] % D == 0) ++a;

		if(i > 0) {
			for(j = i-1; j >= 0; --j) {
				l = arr[j] * 10 + arr[i];
				if(l % D == 0) ++a;
        if(i > 1) {
          for(k = j-1; k >= 0; --k) {
            l = arr[k] * 100 + arr[j] * 10 + arr[i];
            if(l % D == 0) {
						  a += power(2, k, MOD);
              //printf("%d\n", l);
            }
				  }
        }
			}
		}
	}


	printf("%"PRId64"\n", a);

	clock_t t2 = clock();

	printf("\n%.2f ms\n", 1000.0*(t2-t1)/CLOCKS_PER_SEC);

	return 0;
}