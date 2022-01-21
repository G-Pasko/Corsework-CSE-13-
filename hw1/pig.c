#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "names.h"

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
	int player_index = 0;
	while(player_index < (num_players + 1)){
		printf(names[player_index]);
		//roll pig
		//add points to player
		if(points[player_index] >= 100){
			printf("Congradulations ", names.h[player_index]);
	}
}
		


