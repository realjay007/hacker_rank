#include <stdint.h>

int64_t power(int64_t x, int64_t y, int mod) {
	int64_t res = 1;
	x %= mod;
	while(y) {
		if(y & 1) res = (res*x) % mod;
		y >>= 1;
		x = (x*x) % mod;
	}
	return res;
}
