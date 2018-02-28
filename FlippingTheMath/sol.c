#include <stdio.h>

int main() {
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int q, n, m, i, j, max, lmax;
	scanf("%d", &q);
	while(q--) {
		scanf("%d", &n);
		max = 0;
		m = n << 1;
		int grid[m][m];
		for(i = 0; i < m; ++i)
			for(j = 0; j < m; ++j) scanf("%d", &grid[i][j]);
		
		for(i = 0; i < n; ++i) {
			for(j = 0; j < n; ++j) {
				lmax = grid[i][j];
				lmax = (grid[m-i-1][j] > lmax)? grid[m-i-1][j] : lmax;
				lmax = (grid[m-i-1][m-j-1] > lmax)? grid[m-i-1][m-j-1] : lmax;
				lmax = (grid[i][m-j-1] > lmax)? grid[i][m-j-1] : lmax;
				max += lmax;
			}
		}
		
		printf("%d\n", max);
	}
	
	fprintf(stderr, "Done\n");
	
	return 0;
}