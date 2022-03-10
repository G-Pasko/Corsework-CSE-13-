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


Customer *add_to_list(char *email, char *name, int shoesize, char *food, Customer *bucket){
	Customer* new_cust;
	new_cust = malloc(sizeof(Customer));
	new_cust->email = strdup(email);
	new_cust->name = strdup(name);
	new_cust->shoesize = shoesize;
	new_cust->food = strdup(food);
	new_cust->next = bucket;

	return new_cust;
}
	
void add_customer_to_hashtable(char* email, char *name, int shoesize, char *food,
    Customer **buckets, size_t num_buckets) {

	size_t which_bucket = hash(email) % num_buckets;

	buckets[which_bucket] = add_to_list(email, name, shoesize, food, buckets[which_bucket]);
	

	printf("customer %s goes in bucket %lu .\n", name, which_bucket);
}

	

int main(void){
	char email[30];
	char name[30];
	int shoesize;	
	Customer* buckets[NUM_BUCKETS] = {NULL};
	char food[20];
	char customers[1024];
	FILE* customer_file = fopen("customers.tsv", "r");
	if(customer_file == NULL){
		printf("No text file found\n");
		return 0;
	}
	while(fgets(customers, 1024, customer_file)){
		sscanf(customers, "%s\t%[^\t]\t%d\t%[^\n]", email, name, &shoesize, food);
		//fscanf(" %*[^\t] %128[^\t]%*[^\t] %*[^\t] %128[^\n]%*[^\n]", name_string, desc_string);
		add_customer_to_hashtable(email, name, shoesize, food, buckets, NUM_BUCKETS);
		//lineSplitter(customers);
		printf("we split the line\n");
	}

	fclose(customer_file);

	FILE* write_customer_file = fopen("customers.tsv", "a");
	while(true){

		char command[10];
		printf("command: ");
		scanf("%s", command);
		//printf("%s\n", command);
		//FILE* customer_file = fopen("customers.tsv", "w");
		if(strcmp(command, "save") == 0){
			
			Customer* node;
			for(int i = 0; i < 10; i++){
				node = buckets[i];
				while(node != NULL){
					printf("%s\t%s\t%d\t%s\n", node->email, node->name, node->shoesize, node->food);
					fprintf(write_customer_file,"%s\t%s\t%d\t%s\n", node->email, node->name, node->shoesize, node->food);
					node = node->next;
				}
			}

		}

		else if(strcmp(command, "quit") == 0){
			Customer* node;
			for(int i  = 0; i < 10; i++){
				node = buckets[i];
				while(node != NULL){
					Customer* temp = node->next;
					free(node);
					node = temp;
				}
			}
			fclose(write_customer_file);
			return 0;
		}

		else if(strcmp(command, "add") == 0){
			printf("Enter email:\n");
			scanf("%s", email);
			printf("Enter name:\n");	
			scanf("%s", name);
			printf("Enter shoe size:\n");
			scanf("%d", &shoesize);
			printf("Enter favorite food:\n");
			scanf("%s", food);
			//Customer.next = (email, name, *shoesize, food);
			add_customer_to_hashtable(email, name, shoesize, food, buckets, NUM_BUCKETS);
			printf("%s %s %d %s\n", email, name, shoesize, food);
		}
		else if(strcmp(command, "lookup") == 0){
			printf("email address?\n");
			scanf("%s", email);
			size_t which_bucket = hash(email) % NUM_BUCKETS;

			Customer* node;
			node = buckets[which_bucket];
			int result = 0;
			while(node != NULL) {
				if (strcmp(node->email, email) == 0) {
					printf("%s %s %d %s\n", node->email, node->name, node->shoesize, node->food);
					result = 1;
					break;
				}
				node = node->next;
  			}
			if(result != 1){
				printf("email not found\n");
			}	
		}

		else if(strcmp(command, "delete") == 0){
			printf("email address?\n");
			scanf("%s", email);
			size_t which_bucket = hash(email) % NUM_BUCKETS;
			Customer* node;
			node = buckets[which_bucket];
			int result = 0;
			while(node != NULL) {
				if(strcmp(node->email, email) == 0) {
					
					free(node->shoesize);
					free(node->food);
					free(node->email);
					free(node->name);
					free(node);
					result = 1;
					/*for(int i = 0; i < 10; i++){
						node = buckets[i];
						while(node != NULL){
							printf("%s\t%s\t%d\t%s\n", node->email, node->name, node->shoesize, node->food);
							fprintf(write_customer_file,"%s\t%s\t%d\t%s\n", node->email, node->name, node->shoesize, node->food);
							node = node->next;
						}
					}*/

					break;
				}
				node = node->next;
			}
			if(result == 0){
				printf("email not found\n");
			}
		}
		
		else if(strcmp(command, "list") == 0){
			Customer* node;
			for(int i = 0; i < 10; i++){
				node = buckets[i];
				while(node != NULL){
					printf("%s %s %d %s\n", node->email, node->name, node->shoesize, node->food);
					node = node->next;
				}
			}
		}	
		else{
			printf("unknown command\n");
		}
	}
}
