#include <stdio.h>

int arr[11][11];
int m = 0, n = 0;

int ff(int i, int j) {
	if (i < 0 || i >= m || j < 0 || j >= n 
		|| arr[i][j] == -1 || arr[i][j] == 1)
		return 0;
	else {
		arr[i][j] = 1;
		return 1 + ff(i+1, j) + ff(i-1, j) + ff(i, j+1) + ff(i, j-1) + ff(i+1, j-1) + ff(i-1, j+1) + 
			ff(i+1, j+1) + ff(i-1, j-1);
		}
}

int max(int x, int y) {
	return (x > y)? x : y;
}

int main() {

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) {
			int x;
			scanf("%d", &x);
			arr[i][j] = x-1; 
			// -1 = 0s, 0 }
		}
		int mx = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (arr[i][j] == 0)
					mx = max(mx, ff(i, j));
			}
		}
		printf("%d\n", mx);
		return 0;
}