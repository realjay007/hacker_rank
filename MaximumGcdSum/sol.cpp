#include <map>
#include <vector>
#include <utility>
#include <cstdio>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;
typedef vector<pair<int, int>> vpii;
typedef unsigned int uint;

// Calculate SPF (Smallest prime factor) for every number till max
// Time complexity: O(nloglogn)
vector<int> sieve(int max) {
	vector<int> spf(max+1);
	int i, j;
	spf[1] = 1;

	for(i = 2; i < max; ++i) {
		// marking smallest prime factor for every number to be itself
		spf[i] = i;
	}
	// seperately marking spf for every even number as 2
	for(i = 4; i < max; i += 2) spf[i] = 2;

	for(i = 3; i*i < max; ++i) {
		// checking if i is prime
		if(spf[i] == i) {
			// marking spf for all numbers divisible by i
			for(j = i*i; j < max; j+=i) {
				// marking spf[j] if it is not previously marked
				if(spf[j] == j) spf[j] = i;
			}
		}
	}
	return spf;
}

// Function to generate prime factors and power
map<int, int> getFactors(int n, vector<int>& spf) {
	int curr = spf[n]; // Current prime factor of n
	int cnt = 1; // Power of current prime factor
	map<int, int> factors;

	// finding prime factors and their powers
	while(n > 1) {
		n /= spf[n];

		// n is now n/spf[n]. If new n also has smallest prime factor as curr,
		// increment power
		if(curr == spf[n]) {
			++cnt;
			continue;
		}
		else {
			factors[curr] = cnt;

			// Update current prime factor as spf[n]
			// and initialise count as 1
			curr = spf[n];
			cnt = 1;
		}
	}
	return factors;
}

// Using a vector of pairs, calculate number
int getNum(map<int, int>& factors) {
	int s = 1;
	for(auto& x : factors) {
		s *= pow(x.first, x.second);
	}
	return s;
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

// Print a map of ints
void printm(map<int, int>& vec) {
	for(auto& x : vec) {
		printf("{%d, %d} ", x.first, x.second);
	}
	printf("\n");
}

void printm(map<int, vector<int>>& mp) {
	printf("{\n");
	for(auto it = mp.cbegin(); it != mp.cend(); ++it) {
		printf("\t%d => [", it->first);
		auto& vec = it->second;
		for(int i = 0, s = vec.size(); i < s; ++i) {
			printf("%d", vec[i]);
			if(i != s-1) printf(", ");
			else printf("],\n");
		}
	}
	printf("}\n");
}

void printm(map<int, map<int, int>>& mp) {
	for(auto& k : mp) {
		printf("%d => ", k.first);
		printm(k.second);
	}
	printf("\n");
}

int main() {
	int n, t, i, j, max = 0, s;
	scanf("%d", &n);
	int raw_a[n], raw_b[n];
	for(i = 0; i < n; ++i) {
		scanf("%d", &raw_a[i]);
		max = raw_a[i] > max? raw_a[i] : max;
	}
	for(i = 0; i < n; ++i) {
		scanf("%d", &raw_b[i]);
		max = raw_b[i] > max? raw_b[i] : max;
	}
	auto spf = sieve(max + 1);
	map<int, vector<int>> A;
	map<int, vector<int>> B;
	map<int, map<int, int>> C;

	// Array A
	for(i = 0; i < n; ++i) {
		t = raw_a[i];
		if(t == 1) continue;
		if(!C.count(t)) {
			C[t] = getFactors(t, spf);
		}
		auto factors = C[t];

		for(auto& f : factors) {
			if(!A.count(f.first)) {
				vector<int> temp;
				A[f.first] = temp;
			}
			A[f.first].push_back(t);
		}
	}

	// Array B
	for(i = 0; i < n; ++i) {
		t = raw_b[i];
		if(t == 1) continue;
		if(!C.count(t)) {
			C[t] = getFactors(t, spf);
		}
		auto factors = C[t];

		for(auto& f : factors) {
			if(!B.count(f.first)) {
				vector<int> temp;
				B[f.first] = temp;
			}
			B[f.first].push_back(t);
		}
	}

	if(A.empty() || B.empty()) {
		printf("1\n");
		return 0;
	}

	//printm(A);
	//printm(B);

	// Sort A
	for(auto it = A.begin(); it != A.end(); ++it) {
		auto& vec = it->second;
		sort(vec.begin(), vec.end(), [&C, it] (int a, int b) {
			auto& fa = C[a];
			auto& fb = C[b];
			if(fb[it->first] < fa[it->first]) {
				return true;
			}
			else if(fb[it->first] > fa[it->first]) {
				return false;
			}
			else {
				return b < a;
			}
		});
	}

	// Sort B
	for(auto it = B.begin(); it != B.end(); ++it) {
		auto& vec = it->second;
		sort(vec.begin(), vec.end(), [&C, it] (int a, int b) {
			auto& fa = C[a];
			auto& fb = C[b];
			if(fb[it->first] < fa[it->first]) {
				return true;
			}
			else if(fb[it->first] > fa[it->first]) {
				return false;
			}
			else {
				return b < a;
			}
		});
	}

	for(auto it = A.begin(); it != A.cend();) {
		if(!B.count(it->first)) {
			it = A.erase(it);
		}
		else ++it;
	}

	for(auto it = B.begin(); it != B.cend();) {
		if(!A.count(it->first)) {
			it = B.erase(it);
		}
		else ++it;
	}

	//printm(A);
	//printm(B);
	//printm(C);
	max = 0;
	s = 0;
	for(auto& it : A) {
		auto& vec = it.second;
		t = gcd(vec.front(), B[it.first].front());
		if(t > max) {
			max = t;
			s = vec.front() + B[it.first].front();
		}
	}

	printf("%d\n", s);


	return 0;
}

