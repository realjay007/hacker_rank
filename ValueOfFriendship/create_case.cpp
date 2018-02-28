#include <cstdio>
#include <cmath>
#include <alogorithm>
#include <iterator>
#include <random>
#include <vector>
#include <utility>

using namespace std;

const int Q = 5; // max = 16
const int N = 1e2; // max = 1e5

int main() {
	int n = N;
	int q = Q;
	int m = fmin(n*(n-1)/2.0, 2.0 * n);
	int i, j, k, l;

	printf("%d\n", q);
	for(i = 0; i < q; ++i) {
		printf("%d %d\n", n, m);
		vector<pair<int, int>> vec(n*)
		for(j = 1; j <= n; ++j) {
			for(k = j+1; k <= n; ++k) {
				
			}
		}
	}

	printf("\n");

	return 0;
}