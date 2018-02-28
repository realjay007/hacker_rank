#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
using namespace std;


int main() {
	
	freopen("in.txt", "r", stdin);
	
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int n, m, i, x, y;
  long long int max = 0, lmax = 0;
  scanf("%d %d", &n, &m);
  int pop[n];
  for(i = 0; i < n; ++i) scanf("%d", &pop[i]);
  vector<int> edges[n+1];
  for(i = 0; i < m; ++i) {
    scanf("%d %d", &x, &y);
    edges[x].push_back(y);
    edges[y].push_back(x);
  }
  
  for(i = 1; i <= n; ++i) {
    bool visited[n+1], can_attend[n+1];
		for(x = 1; x <= n; ++x) can_attend[x] = visited[x] = false;
    queue<int> qu;
    qu.push(i);
    visited[i] = can_attend[i] = true;
    while(!qu.empty()) {
			int s = qu.front();
			qu.pop();
			
			for(auto j = edges[s].begin(); j != edges[s].end(); ++j) {
				if(!visited[*j]) {
					visited[*j] = true;
					qu.push(*j);
					bool f = true;
					for(auto k = edges[*j].begin(); k != edges[*j].end(); ++k) {
						if(can_attend[*k]) f = false;
					}
					can_attend[*j] = f;
				}
			}
		}
		lmax = 0;
		for(x = 1; x <= n; ++x) {
			if(can_attend[x]) {
				lmax += pop[x-1];
				// printf("%d\n", x);
			}
		}
    max = (lmax > max)? lmax : max;
		// printf("\n\n");
  }
	
	printf("%lld\n", max);
  
  return 0;
}
