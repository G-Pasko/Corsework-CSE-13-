#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// PROBLEM 1

long long *fibonacci_numbers(int n) {
  // You're going to have to allocate an array, fill it in, and return it.
	long long* output = NULL;
	output = (long long *)calloc(n, sizeof(long long));
	if(n == 0){
		return output;
	}
	long long num1 = 1;
	long long num2 = 1;
	
	output[0] = num1;
	if(n == 1){
		return output;
	}
	output[1] = num2;
	if(n == 2){
		return output;
	}
	int i;
	for(i = 2; i < n; i++){
		long long temp = num1 + num2;
		num1 = num2;
		num2 = temp;
		output[i] = num2;
	}
	
  // The array should be of length n.
  // Recall the first few entries should be 1, 1, 2, 3, 5, 8, ...

  return output;
}


// PROBLEM 2

typedef struct {
  int shoe_size;
  int customer_id;
  int num_purchases;
} ShoeCustomer;

void bubble_sort_customers(ShoeCustomer* customers, int n_customers) {
  // Your code here! Make them sorted!
	for(int i = 0; i < n_customers; i++){
		for(int k = i + 1; k < n_customers; k++){
			if(customers[i].shoe_size > customers[k].shoe_size){
				ShoeCustomer temp = customers[i];
				customers[i] = customers[k];
				customers[k] = temp;
			}
		}
	}
		
}

// PROBLEM 3


// A linked list of floating point numbers.
typedef struct LLfloat {
  float val;
  struct LLfloat *next;
} LLfloat;

float sqr(float in){
	return in * in;
}

// Helper function to find length of numbers
int length_of(LLfloat *list, int counter){
	if(list->next != NULL){
		counter ++;
		return length_of(list->next, counter);
	}
	return counter;

}

LLfloat *map_floats(float (*f)(float), LLfloat *numbers)  {
  // finish this function.
  // Should it be recursive? It's up to you, but it could be recursive!

	if(numbers == NULL){
		return NULL;
	}
	int length = length_of(numbers, 1);	
	LLfloat *new_array = (LLfloat *)calloc(length, sizeof(LLfloat));

	for(int i = 0; i < length; i++){
		new_array[i].val = f(numbers[i*2].val);
		
	}
	return new_array;
}

// PROBLEM 4

unsigned long compute_availability(unsigned long *calendars, int num_users) {
	unsigned long availability = 0;
	if(num_users == 0){
		return availability;
	}
	if(num_users == 1){
		return calendars[0];
	}
	availability = calendars[0];
	
	for(int i = 1; i < num_users; i++){
		availability = calendars[i] & availability;
	}
	return availability;
}

// put examples for testing your functions in the main! You're going to have to
// figure out how to test these.
int main(void) {
	int user_input;
	printf("Test for problem 1\n");
	printf("Enter Fibonacci position\n");
	scanf("%d", &user_input);
	for(int i = 0; i < user_input; i++){
		
		printf("%llu\n", fibonacci_numbers(user_input)[i]);
	}

	printf("Test for problem 2\n");	
	ShoeCustomer *list;
	list = (ShoeCustomer *)calloc(5, sizeof(ShoeCustomer));
	list[0].shoe_size = 7; 
	list[1].shoe_size = 4;
	list[2].shoe_size = 9;
	list[3].shoe_size = 6;
	list[4].shoe_size = 8;
	
	for(int i = 0; i < 5; i++){
		printf("List at %d pre-sort: %d\n", i, list[i].shoe_size);
	}
	bubble_sort_customers(list, 5);
	for(int i = 0; i < 5; i++){
		printf("List at %d post-sort: %d\n", i, list[i].shoe_size);
	}
		
	printf("\nTest for problem 3\n");
	LLfloat *linkedList  = (LLfloat *)calloc(1, sizeof(LLfloat));
	LLfloat *newLL1  = (LLfloat *)calloc(1, sizeof(LLfloat));
	LLfloat *newLL2  = (LLfloat *)calloc(1, sizeof(LLfloat));
	LLfloat *newLL3  = (LLfloat *)calloc(1, sizeof(LLfloat));
	linkedList->val = 10;
	newLL1->val = 9;
	newLL2->val = 9;
	newLL3->val = 9;
	linkedList->next = newLL1;
	newLL1->next = newLL2;
	newLL2->next = newLL3;
	newLL3->next = NULL;
	linkedList = map_floats(sqr, linkedList);
	printf("%f\n", linkedList->val);
	
	printf("Test for problem 4\n");
	unsigned long calanders[4];
	calanders[0] = 2;
	calanders[1] = 3;
	calanders[2] = 19; 
	calanders[3] = 22;
	printf("%lu\n", compute_availability(calanders, 4));
	return 0;
}
