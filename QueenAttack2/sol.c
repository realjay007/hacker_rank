#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

typedef struct Point {
	int row;
	int col;
} Point;

// Make sure defend and attack are on same side of queen
Point battle(Point queen, Point defend, Point attack) {
	if(defend.row == -1) return attack;
	else {
		int d = fmax(abs(queen.row-defend.row), abs(queen.col-defend.col));
		int a = fmax(abs(queen.row-attack.row), abs(queen.col-attack.col));
		if(a < d) return attack;
		else return defend;
	}
}

int main() {
	int n, k, r, c, i, j;
	scanf("%d%d%d%d", &n, &k, &r, &c);
	long long domain = 0;
	Point queen = {.row = r, .col = c}, wall[3][3], attack = {-1, -1};
	for(i = 0; i < 3; ++i) {
		for(j = 0; j < 3; ++j) wall[i][j] = attack;
	}
	wall[1][1] = queen;
	
	for(i = 0; i < k; ++i) {
		scanf("%d %d", &r, &c);
		attack.row = r, attack.col = c;
		// Check attack position
		// Column
		if(queen.col == c) {
			// Top
			if(r > queen.row) {
				wall[0][1] = battle(queen, wall[0][1], attack);
				continue;
			}
			// Bottom
			else if(r < queen.row) {
				wall[2][1] = battle(queen, wall[2][1], attack);
				continue;
			}
		}

		// Row
		else if(queen.row == r) {
			// Left
			if(c < queen.col) {
				wall[1][0] = battle(queen, wall[1][0], attack);
				continue;
			}
			// Right
			else if(c > queen.col) {
				wall[1][2] = battle(queen, wall[1][2], attack);
				continue;
			}
		}

		// Left-top to bottom-right diagonal
		else if(queen.row+queen.col == r+c) {
			// Left top
			if(r > queen.row) {
				wall[0][0] = battle(queen, wall[0][0], attack);
				continue;
			}
			// Bottom right
			else if(r < queen.row) {
				wall[2][2] = battle(queen, wall[2][2], attack);
				continue;
			}
		}

		// Right-top to bottom-left diagonal
		else if(queen.row-queen.col == r-c) {
			// Bottom left
			if(c < queen.col) {
				wall[2][0] = battle(queen, wall[2][0], attack);
				continue;
			}
			else if(c > queen.col) {
				wall[0][2] = battle(queen, wall[0][2], attack);
				continue;
			}
		}
	}

	// Calculate distance to closest obstacle in each direction and add to domain
	// Top, Bottom, Left, Right
	domain += (wall[0][1].row != -1)? (wall[0][1].row - queen.row - 1) : n - queen.row;
	domain += (wall[2][1].row != -1)? (queen.row - wall[2][1].row - 1) : queen.row - 1;
	domain += (wall[1][0].col != -1)? (queen.col - wall[1][0].col - 1) : queen.col - 1;
	domain += (wall[1][2].col != -1)? (wall[1][2].col - queen.col - 1) : n - queen.col;

	// Diagonals clockwise from top-left
	domain += (wall[0][0].col != -1)? (queen.col - wall[0][0].col - 1) : fmin(queen.col - 1, n - queen.row);
	domain += (wall[0][2].row != -1)? (wall[0][2].row - queen.row - 1) : fmin(n - queen.col, n - queen.row);
	domain += (wall[2][2].col != -1)? (wall[2][2].col - queen.col - 1) : fmin(n - queen.col, queen.row - 1);
	domain += (wall[2][0].row != -1)? (queen.row - wall[2][0].row - 1) : fmin(queen.col - 1, queen.row - 1);

	printf("%lld\n", domain);
	
	return 0;
}
