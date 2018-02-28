#include <stdio.h>

long long flor2(long long n) {
	long long res = 1;
	if(n == 0) return 0;
	while(n) {
		res <<= 1;
		n >>= 1;
	}
	return res >> 1;
}

void copy(int* arr1, int* arr2, int n) {
	int i;
	for(i = 0; i < n; ++i) arr2[i] = arr1[i];
}

void print(int* arr, int n) {
	int i;
	for(i = 0; i < n-1; ++i) printf("%d ", arr[i]);
	printf("%d\n", arr[n-1]);
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int n;
	long long m, i, j, k;
	scanf("%d %lld", &n, &m); --m;
	int mat1[n], mat2[n];
	for(i = 0; i < n; ++i) scanf("%d", &mat1[i]);
	while(m > 0) {
		k = flor2(m);
		for(j = 0; j < n; ++j) {
			mat2[j] = mat1[j] ^ mat1[(k+j)%n];
		}
		copy(mat2, mat1, n);
		m -= k;
	}
	print(mat2, n);
	
	fprintf(stderr, "Done\n");
	
	return 0;
}