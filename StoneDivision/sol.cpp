#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
vector<ull> s;
int m;

struct State {
	ull a; // Amount per pile
	ull n; // Number of piles
	short t; // Turn
	State(ull amount, ull num, short turn): a(amount), n(num), t(turn) {}
};

bool checkIfDiv(ull n) {
	for(int i = 0; i < m; ++i)
		if(n % s[i] == 0) return true;
	return false;
}

int compute(const State& curr) {
	if(checkIfDiv(curr.a) == false) return (curr.t == 1)? 2 : 1;
	for(int i = 0; i < m; ++i) {
		if(curr.a % s[i] != 0) continue;
		ull q = curr.a / s[i];
		State next(q, curr.n*s[i], (curr.n % 2 == 0)? curr.t : ((curr.t == 1)? 2 : 1));
		short roundwin = compute(next);
		if(roundwin == curr.t) return curr.t;
	}
	return (curr.t == 1)? 2 : 1;
}

int main() {
	ull n, temp;
	int i, j, k;
	scanf("%lld %d", &n, &m);
	for(i = 0; i < m; ++i) {
		scanf("%lld", &temp);
		if(n % temp == 0) s.push_back(temp);
	}
	m = s.size();
	State pile(n, 1, 1);
	j = compute(pile);
	if(j == 1) printf("First\n");
	else printf("Second\n");

	return 0;
}