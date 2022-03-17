#include "review.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Functions for you to implement. Most of the work for this homework will be
// done in here, but you'll also need to make changes to review.h and yelling.c.

// Problem 1
void sum_and_difference(int a, int b, int *sum, int *difference) {
  //  Your code goes here!
	*sum = a + b;
	*difference = a - b;
}

// Problem 2

// This one ought to be recursive.
size_t ll_length(LLint *node) {
  // change this, clearly.
	if(node == NULL){
		return 1;
	}	
	return (1 + ll_length(node->next));
}

// Do this one iteratively.
size_t ll_length_iterative(LLint *node) {
	size_t size = 1;
	while(node != NULL){
		size +=1;
		node = node->next;
	}
  // These are just default return values; they're for you to change.
  return size;
}

// Problem 3.

void reverse_doubles_with_stack(double *array, size_t array_len) {
  // This function will reverse the order of the array pointed to by *array.
  // Make sure to define your linked list data structure in review.h, and use
  // stack behavior (LIFO) to get the numbers in the reversed order.
  // There is a way to do this without a stack data structure, I know. But this
  // is for practice with data structures.
	LLdouble *top = NULL;
	//top->val = NULL;
	//top->next = NULL;
	//top->val = NULL;
	for(size_t i = 0; i < array_len; i++){
		LLdouble *new = (LLdouble *)malloc(sizeof(LLdouble));
		new->val = array[i];
		new->next = top;
		top = new;
	}
	for(size_t j = 0; j < array_len; j++){
		array[j] = top->val;
		LLdouble *temp = top->next;
		free(top);
		top = NULL;
		top = temp;
	}		
}

// Problem 4.

tnode *word_observe(char *word, tnode *node) {
  // This function returns a pointer to a tnode because you may have to allocate
  // a new one. You might take a NULL pointer to start with.
  // Also, this means that you can very cleanly do this with recursion.
	if(node != NULL){
		if(strcmp(word, node->word) == 0){
			node->count ++;
			return node;
		}
		if(strcmp(word, node->word) > 0){
			if(node->right != NULL){
				return(word_observe(word, node->right));
			}
			tnode *new = (tnode *)malloc(sizeof(tnode));
			new->count = 1;
			node->word = word;
			node->right = new;
			return new;
		}
			
		if(strcmp(word, node->word) < 0){
			if(node->left != NULL){
				return(word_observe(word, node->word));
			}
			tnode *new = (tnode *)malloc(sizeof(tnode));
			new->count = 1;
			new->word = word;
			node->left = new;
			return new;
		}
	}
	node = (tnode *)malloc(sizeof(tnode));
	node->count = 1;
	node->word = word;
	node->left = NULL;
	node->right = NULL;	
}

int word_count(char *word, tnode *node) {
  // Default return values; here for you to change.
	if(node != NULL){
		if(strcmp(word, node->word) == 0){
			return node->count;
		}
		if(strcmp(word, node->word) < 0 && node->left != NULL){
			return word_count(word, node->left);
		}
		if(strcmp(word, node->word) > 0 && node->right != NULL){
			return word_count(word, node->left);		
		}
	}
	return 0;
}

void delete_tree(tnode *node) {
  // Free the whole tree and all associated memory. This can be recursive or
  // not, your choice!
	if(node->left == NULL && node->right == NULL){
		free(node);
	}
	else if(node->left == NULL){
		delete_tree(node->right);
	}
	delete_tree(node->left);
		
}
