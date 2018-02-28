#include <vector>
#include <cstdio>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Train {
public:
	int start;
	int end;


	int length() {
		return this->end - this->start + 1;
	}

	Train(int begin, int stop): start(begin), end(stop) {

	}

	Train operator + (const Train& tr) {
		Train new_t(*this);
		new_t.start = tr.start < new_t.start? tr.start : new_t.start;
		new_t.end = tr.end > new_t.end? tr.end : new_t.end;
		return new_t;
	}

	void operator += (const Train& tr) {
		this->start = tr.start < this->start? tr.start : this->start;
		this->end = tr.end > this->end? tr.end : this->end;
	}

	bool operator < (const Train& tr) {
		return this->start < tr.start;
	}

	bool operator >(const Train& tr) {
		return this->end > tr.start;
	}

	bool crosses(const Train& tr) {
		bool cross = this->end >= tr.start && tr.end >= this->start;
		//printf("{%d, %d} and {%d, %d} %s!\n", this->start, this->end, tr.start, tr.end, cross? "cross" : "do not cross");
		return cross;
	}

};

typedef unordered_map<int, vector<Train>> umiv;

void printv(vector<Train> vt) {
	for(auto i = vt.cbegin(); i != vt.cend(); ++i) {
		printf("{%d, %d} ", i->start, i->end);
	}
	printf("\n");
}

void printm(umiv mp) {
	for(auto i = mp.cbegin(); i != mp.cend(); ++i) {
		printf("%d:\n", i->first);
		printv(i->second);
	}
	printf("\n");
}

int main() {
	int n, m, k, i, j, s, t, u;
	long long tracks = 0, total;
	umiv trains;
	scanf("%d %d %d", &n, &m, &k);
	total = 1 * m;
	total *= n;
	trains.reserve(k);

	for(i = 0; i < k; ++i) {
		scanf("%d %d %d", &s, &t, &u);
		Train ft(t, u);
		if(trains.count(s)) {
			trains[s].push_back(ft);
		}
		else {
			vector<Train> vt;
			vt.push_back(ft);
			trains[s] = vt;
		}
	}

	//printm(trains);
	for(auto &x : trains) {
		vector<Train> cvt;
		sort(x.second.begin(), x.second.end());
		Train ftr = x.second[0];
		for(auto tr : x.second) {
			if(ftr.crosses(tr)) {
				ftr = ftr + tr;
			}
			else {
				cvt.push_back(ftr);
				ftr = tr;
			}
		}
		cvt.push_back(ftr);
		x.second = cvt;
		for(auto tr : cvt) {
			tracks += tr.length();
		}
	}

	printf("%lld\n", total - tracks);

	return 0;
}
