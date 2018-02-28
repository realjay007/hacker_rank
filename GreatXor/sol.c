#include <stdio.h>

int main() {
	long long q, k, x, i, s, t;
	scanf("%lld", &q);
	while(q--) {
		scanf("%lld", &x);
		s = 0;
		k = 1;
		while(k <= x) {
			if(x & k) {
				s += ((k << 1) > x)? x - k : (k << 1) - k;
			}
			k <<= 1;
		}
		printf("%lld\n", x - s - 1);
	}

	return 0;
}