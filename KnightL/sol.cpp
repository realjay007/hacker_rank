#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

struct Move {
	int row;
	int col;
	int move_no;

	Move(int r = 0, int c = 0, int m_n = 0): row(r), col(c), move_no(m_n) {

	}

	vector<Move> getPossibleMoves(int a, int b, int n) {
		vector<Move> poss;
		poss.reserve(8);
		int x[] = {1, 1, -1, -1};
		int y[] = {1, -1, 1, -1};
		int s, t;

		for(int i = 0; i < 4; ++i) {
			s = this->row + (a * x[i]);
			t = this->col + (b * y[i]);
			Move m(s, t, this->move_no+1);
			if(m.row >= 0 && m.col >= 0) poss.push_back(m);

			m.row = this->row + (b * y[i]);
			m.col = this->col + (a * x[i]);
			if(m.row >= 0 && m.col >= 0) poss.push_back(m);
		}

		return poss;
	}

	void print() {
		printf("{row = %d, col = %d, move_no = %d}\n", this->row, this->col, this->move_no);
	}

};

int main() {
	int n, a, b;
	scanf("%d", &n);
	Move orig;

	for(a = 0; a < n; ++a) {
		for(b = 0; b < n; ++b) {
			int min = n*n+1, f = 0;
			queue<Move> qmoves;
			vector<bool> visited(n*n, false);
			qmoves.push(orig);

			while(!qmoves.empty()) {
				printf("a = %d, b = %d\n", a, b);
				++f;
				auto move = qmoves.front();
				qmoves.pop();
				visited[move.row*n+move.col] = true;
				if(move.row == n-1 && move.col == n-1) {
					min = move.move_no;
					break;
				}
				else {
					auto moves = move.getPossibleMoves(a+1, b+1, n);
					for(auto& m : moves) {
						if(!visited[m.row*n+m.col]) {
							qmoves.push(m);
							m.print();
						}
					}
				}
				if(f == 10) return 0;
			}
			printf("%d \n", min == n*n+1? -1 : min);
		}
		printf("\n");
	}

	return 0;
}
