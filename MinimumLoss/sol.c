#include <stdio.h>
#include <stdlib.h>

typedef struct proj {
	int year;
	long long price;
} proj;

int comp(const void* a, const void* b) {
	const proj* x = (const proj*) a;
	const proj* y = (const proj*) b;
	
	return (x->price < y->price) - (x->price > y->price);
}

void printp(proj* p, int n) {
	int i;
	for(i = 0; i < n; ++i) {
		printf("{%d, %lld} ", p[i].year, p[i].price);
	}
	printf("\n");
}

int main() {
	int n, i, j, t;
	long long price, diff = 0;
	scanf("%d", &n);
	proj* p = (proj*) malloc(sizeof(proj) * n);
	for(i = 0; i < n; ++i) {
		scanf("%lld", &price);
		p[i].year = i+1;
		p[i].price = price;
	}
	//printp(p, n);
	qsort(p, n, sizeof(proj), comp);
	diff = p[0].price;
	//printp(p, n);
	
	for(i = 0; i < n-1; ++i) {
		for(j = i+1; j < n; ++j) {
			if(p[i].year > p[j].year) continue;
			else {
				price = p[i].price - p[j].price;
				diff = price < diff? price : diff;
				break;
			}
		}
	}

	free(p);
	
	printf("%lld\n", diff);
	
	return 0;
}