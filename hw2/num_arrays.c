#include <stdio.h>
#include <limits.h>
/*
 * All of your code goes in here. You need to finish these functions.
 */

int maximum(int *nums, int len) {
	int max = INT_MIN;
	int i;
	for(i = 0; i < len(nums); i++){
		if(nums[i] > max){
			max = nums[i];
		}
	}
	return max;
	return 0;
}

int sum_positive(int *nums, int len) {
  return 0;
}

int reduce(int *nums, int len, int (*f)(int,int), int initial){
  return 0;
}

int maximum_with_reduce(int *nums, int size) {
  return 0;
}

int sum_positive_with_reduce(int *nums, int size) {
  return 0;
}

int count_negative_with_reduce(int *nums, int size) {
  return 0;
}
