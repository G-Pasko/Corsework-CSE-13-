#include "final.h"

#include <stdio.h>
#include <string.h>

// YOUR CODE GOES IN THIS FUNCTION!! Probably don't change the other ones.
WordCountTable *sum_word_count_tables(WordCountTable *table_a,
                                      WordCountTable *table_b) {

  // Your code here! You can change whatever you want in this function.
  // return an empty one just so we don't crash.
  WordCountTable *out = build_word_count_table(table_a->num_buckets);
	char *table_a_words[256];
	size_t i = 0;
	int j = 0;
	int leave;
	WordCountNode *top;
	while(i < table_a->num_buckets){
		if(table_a->buckets[i] != NULL){
			top = table_a->buckets[i];
			while(top != NULL){
				while(table_a_words[j] != NULL){
					if(strcmp(top->word, table_a_words[j]) == 0){
							leave = 1;
							break;
					}
					j++;
				}
				table_a_words[j] = top->word;
				if(leave != 1){	
					set_word_count(top->word, top->count, out);
					//printf("%s : %d\n", top->word, top->count);
				}
				top=top->next;
				leave = 0;
				j = 0;
				
			}
		}
		i++;
	}
	i = 0;
	j = 0;
	
	while(i < table_b->num_buckets){
		if(table_b->buckets[i]){
			top = table_b->buckets[i];
			while(top != NULL){
				if(top->count == get_word_count(top->word, table_b)){

					set_word_count(table_b->buckets[i]->word, get_word_count(table_b->buckets[i]->word, out) + table_b->buckets[i]->count, out);
				}
				top = top->next;
			}
		}
		i++;
	}


  return out;
}

//// more functions, table infrastructure. Please don't change these.

// Thank you Dan Bernstein.
unsigned long hash(char *str) {
  unsigned long hash = 5381;
  int c;

  while (*str != '\0') {
    c = *str;
    hash = ((hash << 5) + hash) + (unsigned char)c; /* hash * 33 + c */
    str++;
  }
  return hash;
}

WordCountNode *set_word_count_in_list(char *word, int count,
                                      WordCountNode *bucket) {
  WordCountNode *new_node;

  new_node = malloc(sizeof(WordCountNode));
  new_node->word = strdup(word);
  new_node->count = count;
  new_node->next = bucket;
  return new_node;
}

void set_word_count(char *word, int count, WordCountTable *table) {
  size_t which_bucket = hash(word) % table->num_buckets;

  // We're going to "overwrite" the previous value here (if it exists) by simply
  // putting a new value at the front of the linked list in the appropriate
  // bucket. This is faster and simpler, but will use more memory.
  table->buckets[which_bucket] =
      set_word_count_in_list(word, count, table->buckets[which_bucket]);
}

// Construct an empty WordCountTable.
WordCountTable *build_word_count_table(size_t num_buckets) {
  WordCountTable *out;

  out = calloc(1, sizeof(WordCountTable));
  out->num_buckets = num_buckets;

  // bunch of NULL pointers to WordCountNode.
  out->buckets = calloc(num_buckets, sizeof(WordCountNode *));
  return out;
}

int get_word_count_in_list(char *word, WordCountNode *node) {
  if (node == NULL) {
    return 0;
  }

  if (strcmp(word, node->word) == 0) {
    return node->count;
  }
  return get_word_count_in_list(word, node->next);
}

int get_word_count(char *word, WordCountTable *table) {
  size_t which_bucket = hash(word) % table->num_buckets;

  return get_word_count_in_list(word, table->buckets[which_bucket]);
}
