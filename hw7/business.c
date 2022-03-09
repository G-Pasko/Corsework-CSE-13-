#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NUM_BUCKETS 10
typedef struct Customer{
	char *email;
	char *name;
	int shoesize;
	char *food;
	struct Customer *next;
} Customer;

unsigned long hash(char *str){
	unsigned long hash = 5381;
	int c;

	while (*str != '\0') {
		c = *str;
		hash = ((hash << 5) + hash) + (unsigned char)c; /* hash * 33 + c */
		str++;
	}
	return hash;
}

/*
void lineSplitter(char *line){
		
	const char seporator[] = "\t";
	char temp = strtok(line, seporator);
	if(temp == NULL){
		return;
	}
	
	printf("%s\n", temp);
	
	while(true){
		temp = strtok(NULL, seporator);
		if(temp == NULL){
			break;
		}
		printf("%c\n", temp);
	}

}
*/
//size_t NUM_BUCKETS = 10;

Customer *add_to_list(char *email, char *name, int shoesize, char *food, Customer *bucket){
	Customer* new_cust;
	new_cust = malloc(sizeof(Customer));
	new_cust->email = strdup(email);
	new_cust->name = strdup(name);
	new_cust->food = strdup(food);
	new_cust->next = bucket;

	return new_cust;
}
	
void add_customer_to_hashtable(char* email, char *name, int shoesize, char *food,
    Customer **buckets, size_t num_buckets) {

  size_t which_bucket = hash(name) % num_buckets;

  buckets[which_bucket] = add_to_list(email, name, shoesize, food, buckets[which_bucket]);

  printf("customer %s goes in bucket %lu .\n", name, which_bucket);
}

	

int main(void){
	//size_t NUM_BUCKETS = 10;	
	//*num_words = 0;
	//char command[10];
	char email[50];
	char name[30];
	int shoesize;	
	Customer* buckets[NUM_BUCKETS] = {NULL};
	char food[50];
	char customers[1024];
	FILE* customer_file = fopen("customers.tsv", "r");
	if(customer_file == NULL){
		printf("No text file found\n");
		return 0;
	}
	while(fgets(customers, 1024, customer_file)){
		fscanf(customers, "%s\t%[^\t]\t%d\t%[^\n]", email, name, &shoesize, food);
		add_customer_to_hashtable(email, name, shoesize, food, buckets, NUM_BUCKETS);
		//lineSplitter(customers);
		printf("we split the line\n");
	}

	fclose(customer_file);

	FILE* write_customer_file = fopen("customers.tsv", "w");
	while(true){

		char command[10];
		printf("command: ");
		scanf("%s", command);
		printf("%s\n", command);
		//FILE* customer_file = fopen("customers.tsv", "w");
		if(strcmp(command, "save") == 0){
			return 0;
		}
		else if(strcmp(command, "quit") == 0){
			fclose(write_customer_file);
			return 0;
		}

		else if(strcmp(command, "add") == 0){
			return 0;

		}
		else if(strcmp(command, "lookup") == 0){
			return 0;
		}

		else if(strcmp(command, "delete") == 0){
			return 0;
		}
		
		else if(strcmp(command, "list") == 0){
			return 0;
		}
		else{
			printf("unknown command\n");
		}
	}
}
