#include "final.h"

#include <stdio.h>

int depth_of_value(int value, BinaryTree *tree) {
  // Your code here!
  // Remember -- return 0 if the value is found at the root node, and -1 if the
  // value is not found in the tree at all.
  // You don't have to handle trees where the same value occurs more than once,
  // but if it does happen, you ought to return the shallowest depth of that
  // value.
  // Also remember that this is just a binary tree, not a binary *search* tree
	int level = -1;
	if(tree != NULL){
		if(tree->val == value){
			return ++level;
		}
		level = depth_of_value(value, tree->left);
		if(level >= 0){
			return ++level;
		}
		level = depth_of_value(value, tree->right);
		if(level >= 0){
			return ++level;
		}
	}
	return level;

}
// Code inspired by "Geeks for Geeks"
// Link: https://www.geeksforgeeks.org/search-a-node-in-binary-tree/
