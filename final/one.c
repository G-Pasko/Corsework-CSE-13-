#include "final.h"

#include <stdio.h>

size_t word_count(char *text) {
  // Your code here!
  // Count up all the words that occur in the given string. A new word starts
  // when you see a letter a-z or A-Z.
	size_t i = 0;
	size_t count = 0;
	int word = 0;
	while(text[i] != '\0'){
		if((text[i] <= 'z' && text[i] >= 'a') || (text[i] <= 'Z' && text[i] >= 'A')){
			word = 1;
		}
		else{
			if(word == 1){
				count += 1;
				word = 0;
			}
		}
		i++;
	}
	if(word == 1){
		count +=1;
	}

  return count;
}
