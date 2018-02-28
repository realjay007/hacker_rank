#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>

const int MOD = 1e9+7;
const int D = 8;

uint64_t c2(const char*, const char*, int);
uint64_t c3(const char*, const char*, int);
uint64_t power(int64_t, uint64_t, int);
void print(int64_t* arr, int n) {
	int i;
	for(i = 0; i < n; ++i) printf("%"PRId64" ", arr[i]);
	printf("\n");
}

int main() {
	clock_t t1 = clock();

	int n, i, j, k, l;
	int64_t a = 0, t;
	scanf("%d", &n);
	char arr[n+1];
	int64_t evp[n], odp[n], af[10][n];
	scanf("%s", arr);

	for(i = 0; i < n; ++i) {
		arr[i] -= 48;
		if(i == 0) {
			t = 1;
			evp[0] = (arr[0] % 2 == 0)? 1 : 0;
			odp[0] = (arr[0] % 2 == 1)? 1 : 0;
		}
		else {
			t = (t << 1) % MOD;
			evp[i] = evp[i-1];
			odp[i] = odp[i-1];
			if(arr[i] % 2 == 0) evp[i] = (t + evp[i]) % MOD;
			else odp[i] = (t + odp[i]) % MOD;
		}
		for(j = 0; j < 10; ++j) af[j][i] = 0;
	}

	for(i = n-1; i >= 0; --i) {
		if(i < n-1) {
			for(j = 0; j < 10; ++j) af[j][i] = af[j][i+1];
			++af[arr[i]][i];
		}
		else af[arr[i]][i] = 1;
	}

	//print(evp, n);
	//print(odp, n);
	//for(j = 0; j < 10; ++j) print(af[j], n);

	for(i = 0; i < n; ++i, a %= MOD) {
		t = a;
		// D1
		if(arr[i] % 8 == 0) ++a;
		switch ((int) arr[i]) {
			case 0:
			case 4:
			case 8:
				if(i < n-1) a += af[0][i+1] + af[8][i+1];
				if(i < n-1 && i > 0) a += ((af[0][i+1] + af[8][i+1]) * evp[i-1]) % MOD;
				if(i < n-1 && i > 0) a += (af[4][i+1] * odp[i-1]) % MOD;
				break;
			case 1:
			case 5:
			case 9:
				if(i < n-1) a += af[6][i+1];
				if(i < n-1 && i > 0) a += (af[6][i+1] * evp[i-1]) % MOD;
				if(i < n-1 && i > 0) a += (af[2][i+1] * odp[i-1]) % MOD;
				break;
			case 2:
			case 6:
				if(i < n-1) a += af[4][i+1];
				if(i < n-1 && i > 0) a += (af[4][i+1] * evp[i-1]) % MOD;
				if(i < n-1 && i > 0) a += ((af[0][i+1] + af[8][i+1]) * odp[i-1]) % MOD;
				break;
			case 3:
			case 7:
				if(i < n-1) a += af[2][i+1];
				if(i < n-1 && i > 0) a += (af[2][i+1] * evp[i-1]) % MOD;
				if(i < n-1 && i > 0) a += (af[6][i+1] * odp[i-1]) % MOD;
				break;
		}
		//printf("%"PRId64"\n", a-t);
	}

	printf("%"PRId64"\n", a);

	clock_t t2 = clock();

	printf("\n%.2f ms\n", 1000.0*(t2-t1)/CLOCKS_PER_SEC);

	return 0;
}

uint64_t c2(const char* str, const char* sub, int n) {
	int64_t a = 0;
	int i, j;
	for(i = 0; i < n-1; ++i, a %= MOD) {
		if(str[i] == sub[0]) {
			for(j = i+1; j < n; ++j)
				if(str[j] == sub[1]) {
					++a;
				}
		}
	}
	return a;
}

uint64_t c3(const char* str, const char* sub, int n) {
	int64_t a = 0, t = 0;
	int i, j, k;
	for(i = 0; i < n-2; ++i, a %= MOD) {
		t = 0;
		if(str[i] == *sub) {
			t = c2(str + i + 1, sub + 1, n - i - 1);
			if(t != 0) {
				a += t;
				a += power(2, i, MOD) - 1;
			}
		}
	}
	return a;
}

uint64_t power(int64_t x, uint64_t y, int mod) {
	int64_t res = 1;
	x %= mod;
	while(y) {
		if(y & 1) res = (res*x) % mod;
		y >>= 1;
		x = (x*x) % mod;
	}
	return res;
}