#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;

struct State {
	vector<int> piles; // Array of the amount of items in each pile
	vector<bool> zeros; // Array of trhe availablity of a zero move on pile
	int length;
	short turn; // Turn;
	State() {}
	State(vector<int> p, vector<bool> z, short t): piles(p), zeros(z), turn(t), length(p.size()) {}
};

short compute(const State& curr) {
	for(int i = 0; i < curr.length; ++i) {
		if(curr.piles[i] <= 0) continue;
		// Reduce to two
		if(curr.piles[i] > 2) {
			State next = curr;
			next.piles[i] = 2;
			next.turn = (curr.turn == 1)? 2 : 1;
			short r1 = compute(next);
			if(r1 == curr.turn) return curr.turn;
		}
		// Reduce to 1
		if(curr.piles[i] > 1) {
			State next = curr;
			next.piles[i] = 1;
			next.turn = (curr.turn == 1)? 2 : 1;
			short r1 = compute(next);
			if(r1 == curr.turn) return curr.turn;
		}
		// Make zero move
		if(curr.zeros[i]) {
			State next = curr;
			next.turn = (curr.turn == 1)? 2 : 1;
			next.zeros[i] = false;
			short r1 = compute(next);
			if(r1 == curr.turn) return curr.turn;
		}
		// Reduce to zero
		State next = curr;
		next.turn = (curr.turn == 1)? 2 : 1;
		next.piles[i] = 0;
		short r1 = compute(next);
		if(r1 == curr.turn) return curr.turn;
	}
	// Base case;
	return (curr.turn == 1)? 2 : 1;
}

int main() {
	int g, n, i, j, k;
	short t;
	scanf("%d", &g);
	while(g--) {
		vector<int> piles;
		vector<bool> zeros;
		scanf("%d", &n);
		for(i = 0; i < n; ++i) {
			scanf("%d", &j);
			piles.push_back(j);
			zeros.push_back(true);
		}
		State start(piles, zeros, 1);
		t = compute(start);
		//t = 2;
		if(t == 1) printf("W\n");
		else printf("L\n");
	}
	return 0;
}