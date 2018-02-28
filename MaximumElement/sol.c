#include <stdio.h>
#include <stdlib.h>

#include "../../lib/c/stack.h"

int main() {
  
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int n, x, q, max = 0;
  node* head = (node*) malloc(sizeof(node));
  node* tail = (node*) malloc(sizeof(node));
  head->x = 0;
  head->next = tail->next = tail;
  scanf("%d", &n);
  while(n--) {
    scanf("%d", &q);
    switch(q) {
      case 1: scanf("%d", &x);
              add(head, x);
              max = (x > max)? x : max;
              break;
      case 2: x = pop(head);
              max = (max == x)? getMax(head) : max;
              break;
      case 3 :printf("%d\n", max);
              break;
    }
  }
  
  return 0;
}
