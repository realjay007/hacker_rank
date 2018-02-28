#include <cstdio>
#include <vector>

using namespace std;

double avg(vector<double> nums) {
	long double total = 0.0;
	if(nums.size() == 0) {
		return 0.0;
	}
	else {
		for(auto &x : nums) {
			total += x;
		}
		return (double) (total/nums.size());
	}
}

int main() {
	int a, b, i, j;
	scanf("")

	return 0;
}
