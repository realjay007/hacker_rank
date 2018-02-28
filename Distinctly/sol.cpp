#include <queue>
#include <cstdio>
#include <list>
#include <bitset>
using namespace std;

struct edge {
  int u;
  int v;
};

int main() {
	
	freopen("in.txt", "r", stdin);
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int n, i, x, y;
  long long int sum = 0;
  scanf("%d", &n);
  int colors[n+1];
	list<int> discolor;
  for(i = 1; i <= n; ++i) {
		scanf("%d", &colors[i]);
		discolor.push_back(colors[i]);
	}
	discolor.sort();
	discolor.unique();
	int distinct = discolor.size();
  edge edges[n-1];
  for(i = 0; i < n-1; ++i) scanf("%d %d", &(edges[i].u), &(edges[i].v));
  
  list<int> adj[n+1];
  for(i = 0; i < n-1; ++i) {
    adj[edges[i].u].push_back(edges[i].v);
    adj[edges[i].v].push_back(edges[i].u);
  }
  for(i = 0; i < n-1; ++i) {
    adj[edges[i].u].remove(edges[i].v);
    adj[edges[i].v].remove(edges[i].u);
    
    bool visited[n+1];
    list<int> d1, d2;
    
   for(x = 1; x <= n; ++x) visited[x] = false;
    queue<int> qu;
    qu.push(edges[i].u);
    visited[edges[i].u] = true;
    
    while(!qu.empty()) {
      int s = qu.front();
      qu.pop();
      d1.push_back(colors[s]);
      
      for(auto j = adj[s].cbegin(); j != adj[s].cend(); ++j) {
        if(!visited[*j]) {
          visited[*j] = true;
          qu.push(*j);
        }
      }
    }
    
    /**for(x = 1; x <= n; ++x) visited[x] = false;
    qu.push(edges[i].v);
    visited[edges[i].v] = true;
    
    while(!qu.empty()) {
      int s = qu.front();
      qu.pop();
      d2.push_back(colors[s]);
      
      for(auto j = adj[s].cbegin(); j != adj[s].cend(); ++j) {
        if(!visited[*j]) {
          visited[*j] = true;
          qu.push(*j);
        }
      }
    }**/
    
    d1.sort();
    d2.sort();
    d1.unique();
    d2.unique();
    
    sum += d1.size() * d2.size();
    adj[edges[i].u].push_back(edges[i].v);
    adj[edges[i].v].push_back(edges[i].u);
  }
  printf("%lld\n", sum);
  
  return 0;
}
