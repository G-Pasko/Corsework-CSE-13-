#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
	char email[30];
	char name[20];
	int shoesize;
	char food[15];
}Customer;

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
int main(void){
	
	//*num_words = 0;
	//char command[10];
	char customers[1024];
	FILE* customer_file = fopen("customers.tsv", "w");
	if(customer_file == NULL){
		printf("No text file found\n");
		return 0;
	}
	
	while(fgets(customers, 1024, customer_file) != NULL){
		lineSplitter(customers);
		printf("we split the line\n");
	}

		/*out[*num_words] = strndup(customers, 5);
		*num_words += 1;
		if(*num_words >= word_space){	
			char** test = (char **)realloc(out, (word_space + 10)* sizeof(char*));
			if(test != NULL){	
				out = test;
				word_space = word_space + 10;
				
			}
			else{
				*num_words = word_space;
				fclose(vocab);
				return out;
			}
		}
		
	}*/while(true){

		char command[10];
		printf("command: ");
		scanf("%s", command);
		printf("%s\n", command);
		if(strcmp(command, "save") == 0){
			return 0;
		}
		else if(strcmp(command, "quit") == 0){
			fclose(customer_file);
			return 0;
		}
		else{
			printf("unknown command\n");
		}
	}
}
