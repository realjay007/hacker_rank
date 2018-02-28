#include <stdio.h>
#include <assert.h>
int mod = 1000000007, comb[2001][2001];
int main() {
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	// Computing Binomial coefficients
	for (int i = 0; i <= 2000; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; j++) {
			comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
			if (comb[i][j] >= mod) comb[i][j] -= mod;
		}
	}
	int t; scanf("%d", &t);
	while (t--) {
		int n, m; scanf("%d%d", &n, &m);
		// assert(1 <= n and 1 <= m and n + m - 1 <= 2000);
		printf("%d\n", comb[n + m - 1][n]);
	}
	fprintf(stderr, "Done\n");
	
	return 0;
}