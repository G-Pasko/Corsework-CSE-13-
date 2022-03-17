#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char **argv) {
  // You're going to have to use argc to decide whether to open up a file, or to
  // read from stdin.
  // If you haven't seen them before, you will likely want to use the functions
  // `fgetc()` and `fputc()`.

	FILE* file = stdin;
	if(argc > 1){
		fclose(file);
		file = fopen(argv[1], 'r');
		
	}
	//FILE* file = stdin;
	char input[256];
	fgets(input, 256, file);
	
	for(int j = 0; j < 256; j++){
		if((input[j] <= 'z') && (input[j] >= 'a')){
			input[j] = toupper(input[j]);
		}
		//return 0;
	}
	printf("%s\n", input);
	fclose(file);
  return 0;
}
