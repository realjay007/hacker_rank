#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cinttypes>
using namespace std;

const int mod = ;

int64_t power(int64_t x, uint64_t y) {
	int64_t res = 1;
	x %= mod;
	while(y) {
		if(y & 1) res = (res*x) % mod;
		y >>= 1;
		x = (x*x) % mod;
	}
	return res;
}



struct Poly {
	vector<int> coef;
	int k;
	Poly(int r) {
		k = 0;
		coef.push_back(r);
	}
	Poly(int a, int r) {
		k = 1;
		coef.push_back(a);
		coef.push_back(r);
	}
	Poly(vector<int> cf): coef(cf) {
		k = cf.size() - 1;
	}

	int operator() (int x) {
		int64_t total = 0;
		for(int i = 1; i <= k; ++i) {
			total += (power((int64_t) x, (uint64_t) i)*coef[k-i]) % mod;
			total %= mod;
		}
		return (int) total;
	}
};

vector<vector<int>> fill(vector<int> B) {
	int k = B.size();
	vector<int> A[k];
	for(int i = 0; i < k; ++i) {
		for(int j = 0; j < k; ++j) {
			A[i].push_back(power((int64_t)i+1, k-i));
		}
		A[i].push_back(B[i]);
	}
	for(int i = 0; i )
}
