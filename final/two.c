#include "final.h"
#include <limits.h>
#include <stdio.h>

void find_two_biggest(LLint *linkedlist, int *biggest, int *nextbiggest) {
  // Your code here!
	int top = INT_MIN;;
	int sec = INT_MIN;
	LLint *current = linkedlist;
	while(current != NULL){
		if(current->val > sec){
			if(current->val > top){
				top = current->val;
			}
			else{
				sec = current->val;
			}
		}
		current = current->next;
	}	
	*biggest = top;
	*nextbiggest = sec;
	
  return;
}
