#include <cstdio>
#include <ctime>
#include <set>

using namespace std;

int main() {
	clock_t t1 = clock();

	int q, n, m, i, j, k, s, t;
	long long total = 0;
	scanf("%d", &q);
	while(q--) {
		total = 0;
		scanf("%d %d", &n, &m);
		set<int> net[n+1];
		for(i = 1; i <= n; ++i) net[i].insert(i);
		for(i = 0; i < m; ++i) {
			scanf("%d %d", &s, &t);
			// Add to S
			for(auto p = net[s].cbegin(); p != net[s].cend(); ++p) {
				net[*p].insert(net[t].cbegin(), net[t].cend());
			}
			// Add to T
			for(auto p = net[t].cbegin(); p != net[t].cend(); ++p) {
				net[*p].insert(net[s].cbegin(), net[s].cend());
			}
			for(j = 1; j <= n; ++j) total += net[j].size();
			total -= n;
		}
		printf("%lld\n", total);
	}

	clock_t t2 = clock();

	printf("\n\n%.2f ms\n", 1000.0 * (t2-t1)/CLOCKS_PER_SEC);

	return 0;
}