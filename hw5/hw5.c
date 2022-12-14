#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Returns true if the guess is an exact match with the secret word, but
// more importantly, fills in the result with the following:
// - 'x' goes in a slot if the corresponding letter in the guess does not appear
//   anywhere in the secret word
// - 'y' goes in a slot if the corresponding letter in the guess appears in the
//   secret word, but not in the corresponding slot
// - 'g' goes in a slot if the corresponding letter in the guess appears in the
//   corresponding slot in the secret word.
//   You can assume that result points at enough memory for a string of length
//   5. (ie, at least 6 bytes long)
bool score_guess(char *secret, char *guess, char *result) {
  // TODO(you): finish this function
	printf("%s\n", secret);

	int track = 0;
	while(strncmp(secret, guess, 5) != 0){
		//int track = 0;
		for(int i = 0; i < 5; i++){
			if(guess[i] == secret[i]){
				result[i] = 'g';
				track = 1;
				//strcpy(result, ('g'));
			}
			for(int j = i; j < 5; j++){
				if(track == 0 && guess[i] == secret[j]){
					result[i] = 'y';
					track = 2;	
				}
			}
			if(track == 0){
				result[i] = 'x';
				//strcpy(result, ('x'));
			}
		
			track = 0;
		}
		return false;
	}
	for(int j = 0; j < 5; j++){
		result[j] = 'g';
	}
	return true;
}

// Returns true if the specified guess is one of the strings in the vocabulary,
// and false otherwise. num_words is the length of the vocabulary.
// A simple linear scan over the strings in vocabulary is fine for our purposes,
// but consider: could you do this search more quickly?
bool valid_guess(char *guess, char **vocabulary, size_t num_words) {
  // TODO(you): finish this function
	for(size_t i = 0; i < num_words; i++){
		if(strcmp(guess, vocabulary[i]) == 0){
			return true;
		}
	}
	//printf("%d\n", *guess == **vocabulary);
	//printf("%zu\n", num_words);
  return false;
}

// Returns an array of strings (so, char **), where each string contains a word
// from the specified file. The file is assumed to contain 5-letter words, one
// per line.
// Also, this function sets the value pointed at by *num_words to be the number
// of words read.
// This will need to allocate enough memory to hold all of the char* pointers --
// so you will keep track of the size of your char** array and then use realloc
// to make the array larger over time, so that you have enough space for the
// dynamically-growing array of char *.
// Use fopen to open the input file for reading,
// strdup (or strndup) to make copies of each word read from that file, and
// fclose to close the file when you are done reading from it.
// Each element of the array should be a single five-letter word,
// null-terminated.
char **load_vocabulary(char *filename, size_t *num_words) {
	//printf("Load vocab started\n");

	char **out = (char **)calloc(10, sizeof(char*));
	// TODO(you): finish this function
	*num_words = 0;
	size_t word_space = 10;
	char buf[512];
	FILE* vocab = fopen(filename, "r");
	//printf("vocab file has been opened\n");
	while(fgets(buf, 512, vocab) != NULL){
		//printf("Inside while loop\n");	
		out[*num_words] = strndup(buf, 5);
		*num_words += 1;	
		if(*num_words >= word_space){	
			//printf("Before realloc\n");
			char** test = (char **)realloc(out, (word_space + 10)* sizeof(char*));
			if(test != NULL){	
				//printf("Post realloc check\n");
				out = test;
				//free(test);
				word_space = word_space + 10;
				//out = (char **)realloc(out, word_space * sizeof(char));
				//printf("Post realloc\n");
				
			}
			else{
				*num_words = word_space;
				fclose(vocab);
				return out;
			}
		}
		
	}
	fclose(vocab);
	//printf("Vocab text file closed\n");
	//*num_words = word_count;
	//printf("%zu\n", *num_words);
	return out;
}

// Free each of the strings in the vocabulary, as well as the pointer vocabulary
// itself (which points to an array of char *).
void free_vocabulary(char **vocabulary, size_t num_words) {
  // TODO(you): finish this function
	for(size_t i = 0; i < num_words; i++){
		free(vocabulary[i]);
	}
	free(vocabulary);
	
}

// Once your other functions are working, please revert your main() to its
// initial state, but please feel free to change it, during development. You'll
// want to test out each individual function!
int main(void) {
  char **vocabulary;
  size_t num_words;
  int num_guesses = 0;

  srand(time(NULL));

  // load up the vocabulary and store the number of words in it.
  vocabulary = load_vocabulary("vocabulary.txt", &num_words);

  // Randomly select one of the words from the file to be today's SECRET WORD.
  int word_index = rand() % num_words;
  char *secret = vocabulary[word_index];

  // input buffer -- we'll use this to get a guess from the user.
  char guess[80];

  // buffer for scoring each guess.
  char result[6] = {0};
  bool success = false;

  printf("time to guess a 5-letter word! (press ctrl-D to exit)\n");
  while (!success) {
    printf("guess: ");
    if (fgets(guess, 80, stdin) == NULL) {
      break;
    }
    // Whatever the user input, cut it off at 5 characters.
    guess[5] = '\0';

    if (!valid_guess(guess, vocabulary, num_words)) {
      printf("not a valid guess\n");
      continue;
    } else {
      num_guesses++;
    }
    success = score_guess(secret, guess, result);
    printf("%s\n", guess);
    printf("%s\n", result);
  }

  if (success) {
    printf("you win, in %d guesses!\n", num_guesses);
  }
  free_vocabulary(vocabulary, num_words);

  return 0;
}
