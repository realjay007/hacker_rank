#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <inttypes.h>

const int mod = 1000000007;

int64_t acs(char* a, char* b) {
	int la = strlen(a), lb = strlen(b);
	int res[la+1][lb+1];
	int i, j;
	
	for(i = 0; i <= la; ++i) res[i][0] = 1;
	for(j = 0; j <= lb; ++j) res[0][j] = 1;
	
	for(i = 1; i <= la; ++i) {
		for(j = 1; j <= lb; ++j) {
			if(a[i-1] == b[j-1])
				//res[i][j] = res[i-1][j] + res[i][j-1];
				res[i][j] = res[i-1][j-1] * 2;
			else res[i][j] = res[i][j-1] + res[i-1][j] - res[i-1][j-1];
		}
	}
	return res[la][lb] - 1;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int q, n, i, p;
	int64_t pro;
	scanf("%d", &q);
	while(q--) {
		scanf("%d", &n);
		pro = 1;
		p = (n >> 1) + (n & 1);
		char str[n][1024];
		for(i = 0; i < n; ++i) scanf("%s", str[i]);
		
		for(i = 0; i < p; ++i) {
			pro = (pro * acs(str[i], str[n-i-1])) % mod;
		}
		printf("%"PRId64"\n", pro);
	}
	
	
	fprintf(stderr, "Done\n");

	return 0;
}
