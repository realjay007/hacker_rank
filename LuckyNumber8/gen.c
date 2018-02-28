#include <stdio.h>
#include <string.h>

int main() {
	int n, i, j;


	printf("{");
	for(i = 0; i < 99; i += 8) {
		printf("\"%02d\", ", i);
	}
	printf("}\n\n");

	printf("{");
	for(i = 0; i < 999; i += 8) {
		printf("\"%03d\", ", i);
	}
	printf("}\n\n");

	/*printf("{");
	for(i = 104; i < 999; i += 8) {
		if((i / 100) % 2 == 1)printf("\"%2d\", ", i % 100);
	}
	printf("}\n\n");*/

	return 0;
}
