#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef enum { SIDE , RAZORBACK , TROTTER , SNOUTER , JOWLER } Position ;
const Position pig [7] = {
	SIDE ,
	SIDE ,
	RAZORBACK ,
	TROTTER ,
	SNOUTER ,
	JOWLER ,
	JOWLER
};

int main(void){
	int num_players = 0;
	scanf("Enter number of players%d\n", &num_players);
	if(!(num_players < 11) && (num_players > 1)){
		num_players = 2;
		fprintf(stderr, "Invalid number of players. Using 2 instead .\n");
	}
	int seed = 0;
	scanf("Enter seed%d\n", &seed);
	if(!(seed < INT_MAX && seed > 0)){
		fprintf(stderr, "Invalid ranodm seed. Using 2022 instead.\n");

		seed = 2022;
	}
	int points[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

}
		


