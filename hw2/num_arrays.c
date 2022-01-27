#include <stdio.h>
#include <limits.h>
/*
 * All of your code goes in here. You need to finish these functions.
 */
int reduce_max(int initial, int num){
	if(initial < num){
		initial = num;
	}
	return initial;
}

int reduce_sum(int initial, int num){
	if(num >0){
		initial += num;
	}
	return initial;
}

int reduce_neg_count(int initial, int num){
	if(num < 0){
		initial ++;
	}
	return initial;
}	

int maximum(int *nums, int len) {
	int max = INT_MIN;
	int i;
	for(i = 0; i < len; i++){
		if(nums[i] > max){
			max = nums[i];
		}
	}
	return max;
}

int sum_positive(int *nums, int len) {
	int total = 0;
	int i;
	for(i = 0; i < len; i++){
		if(nums[i] > 0){
			total += nums[i];
		}
	}
	return total;
}

int reduce(int *nums, int len, int (*f)(int,int), int initial){
	for(int i = 0; i < len; i++){
		initial = f(initial, nums[i]);
	}
	return initial;
}

int maximum_with_reduce(int *nums, int size) {
	return reduce(nums, size, reduce_max, INT_MIN);
}

int sum_positive_with_reduce(int *nums, int size) {
	return reduce(nums, size, reduce_sum, 0);
}

int count_negative_with_reduce(int *nums, int size) {
	return reduce(nums, size, reduce_neg_count, 0);
}
