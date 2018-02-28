#include <stdio.h>
#include <stdlib.h>

#define Q 1e5
#define X 1e10

int main() {
	int q = Q;
	long long x = X;
	printf("%d\n", q);
	while(q--) printf("%lld\n", x--);

	return 0;
}