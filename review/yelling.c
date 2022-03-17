#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  // You're going to have to use argc to decide whether to open up a file, or to
  // read from stdin.
  // If you haven't seen them before, you will likely want to use the functions
  // `fgetc()` and `fputc()`.
/*	if(argc > 1){
		for(int i = 1; i < argc; i++){
			FILE* file = fopen(argv[i], 'r');
		}
		return 0;
	}
	char input[256];
	fgets(input, 256, stdin);
	for(int j = 0; j < 256){
		if((input[j] < =122) &&(input[j] >= 97)){
			input[j] -= 20;
		}
		//return 0;
	}
	printf("%s\c", input);
	*/
  return 0;
}
