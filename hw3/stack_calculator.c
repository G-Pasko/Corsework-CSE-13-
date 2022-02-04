#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack_calculator.h"

// Allocate a new Stack struct and return a pointer to it.
Stack *stack_create(void) {
  // this one is complete, no need to change it!
  Stack *out;
  out = (Stack *)calloc(1, sizeof(Stack));
  return out;
}

// Add a new node at the front of the stack. Return false if we are unable to do
// so (eg, if memory allocation fails).
bool stack_push(Stack *s, CalculatorItem item) {
  // your code here					
	//int old_size = sizeof(s);
	//printf("%lu/n", sizeof(s));
	Node *newnode = (Node *)calloc(1, sizeof(item));
	if(newnode == NULL){
		return false;
	}
	if(item.type == NUMBER){	
		newnode->item = item;
		newnode->next = s->top;
		s->top = newnode;
		return true;
	}
	return stack_compute_step(s, item);
	
}

// Pop the stack and put the result into the output pointer.
// return false if the stack is NULL or if it is empty.
bool stack_pop(Stack *s, CalculatorItem *output) {
  // your code here
	if(s->top == NULL){
		return false;
	}
	//*output = s->top_item;
	free(s->top->next);
	free(s->top);
	stack_push(s, *output);
	/*Node* newtop = s->top->next;
	free(s->top);
	s->top = newtop;*/
	return true;
}

// Returns true if the specified stack is empty.
bool stack_empty(Stack *s) {
  // your code here
	if(s->top == NULL){
		return true;
	}
	return false;
	
	//return true;
}

// Free all of the memory used by this stack, including its linked list.
// When you are done, set the pointer to NULL.
void stack_delete(Stack **s) {
  // your code here
	if(s == NULL){
		*s = NULL;
	}
	Node* next_top = (*s)->top->next;
	next_top->next = (*s)->top->next->next;
	free((*s)->top);
	(*s)->top = next_top;
	stack_delete(s);

	/*while(s != NULL){
		Node* next_node = (Node *)s->top->next;
		free(s->top);
		s->top = next_node;
	}*/
}

// Returns true if we were able to successfully perform the computation step,
// and false if there was an error of some kind.
bool stack_compute_step(Stack *s, CalculatorItem item) {
  // your code here
	CalculatorItem  computed_item;
	CalculatorItem second = s->top->item;
	CalculatorItem first = s->top->next->item;
	if(item.type == ADD){
		computed_item.value = first.value + second.value;
		stack_pop(s, &computed_item);
	}
		
		
		
  return true;
}
