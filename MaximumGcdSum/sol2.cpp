#include <cstdio>
#include <map>
#include <vector>
#include <cmath>

using namespace std;
typedef map<int, vector<int>> mvi;

vector<int> factorise(int, mvi&);
void read(int, map<int, int>&, mvi&);
int gcd(int, int);

int main() {
	int n, i, j, s, t, max;
	scanf("%d", &n);
	map<int, int> A, B;
	mvi C;

	read(n, A, C);
	read(n, B, C);

	for(auto it = A.begin(); it != A.cend();) {
		if(!B.count(it->first)) {
			it = A.erase(it);
		}
		else ++it;
	}

	max = -1;
	for(auto it : A) {
		t = gcd(it.second, B[it.first]);
		if(t > max) {
			max = t;
			s = it.second + B[it.first];
		}
		else if(t == max) {
			t = it.second + B[it.first];
			s = t > s? t : s;
		}
	}

	printf("%d\n", s);

	return 0;
}

vector<int> factorise(int n, mvi& C) {
	auto root = sqrt(n);
	vector<int> factors;
	for(int i = 1; i <= root+1; ++i) {
		if(n % i == 0) {
			if(n/i == i) factors.push_back(i);
			else {
				factors.push_back(i);
				factors.push_back(n/i);
			}
		}
	}
	return factors;
}

void read(int n, map<int, int>& A, mvi& C) {
	int i, t;
	map<int, bool> treated;
	for(i = 0; i < n; ++i) {
		scanf("%d", &t);
		if(treated.count(t)) continue;
		if(!C.count(t)) {
			C[t] = factorise(t, C);
		}
		auto& factors = C[t];
		treated[t] = true;
		for(auto f : factors) {
			if(!A.count(f)) {
				A[f] = t;
			}
			else {
				A[f] = t > A[f]? t : A[f];
			}
		}
	}
}

int gcd(int u, int v) {
	int t;
	while(u > 0) {
		if(u < v) {
			t = u;
			u = v;
			v = t;
		}
		u -= v;
	}
	return v;
}
