#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 2*1e4

int digits(int x) {
	int i = 0;
	while(x) {
		x /= 10;
		++i;
	}
	return i;
}

int main() {
	int n = N, x = 1;
	printf("%d\n", n);
	srand(time(0));
	
	while(n > 0) {
		x = rand();
		printf("%d", x);
		n -= digits(x);
	}
	printf("\n");

	return 0;
}