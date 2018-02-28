#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

void printv(vector<int>&);

int main() {
	int n, k, t, s, i, j;
	scanf("%d %d", &n, &k);
	vector<int> x;
	x.reserve(n);
	for(i = 0; i < n; ++i) {
		scanf("%d", &t);
		x.push_back(t);
	}

	sort(x.begin(), x.end());

	//printv(x);

	t = 0;
	while(!x.empty()) {
		i = *x.cbegin();
		auto p = find_if(x.begin(), x.end(), [i, k] (int f) {
			return f > (i + k);
		});
		--p;
		i = *p;
		x.erase(remove_if(x.begin(), x.end(), [i, k] (int f) {
			int l = f > i? f - i : i - f;
			return l <= k;
		}), x.end());

		//printv(x);
		++t;
	}

	printf("%d\n", t);

	return 0;
}

void printv(vector<int>& v) {
	int n = v.size();
	printf("\n");
	for(int i = 0; i < n; ++i) {
		printf("%d%s", v[i], i == n-1? "\n":", ");
	}
	return;
}
