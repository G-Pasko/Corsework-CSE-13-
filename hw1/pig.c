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
	int num_players;
	printf("num_players initialzied\n");
	printf("Enter number of players: \n");
	scanf("%d", &num_players);
	if(!(num_players < 11) && (num_players > 1)){
		num_players = 2;
		fprintf(stderr, "Invalid number of players. Using 2 instead .\n");
	}
	printf("num players defined\n");
	
	int seed = 0;
	printf("Enter seed: \n");
	scanf("%d", &seed);
	if(!(seed < INT_MAX && seed > 0)){
		fprintf(stderr, "Invalid ranodm seed. Using 2022 instead.\n");
		seed = 2022;
	}
	int points[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int player_index = 0;
	while(player_index < (num_players + 1)){
		printf("%s", names[player_index]);
		int roll = (random() % 7);
		switch(pig[roll]){
			case SIDE:
				;
			case RAZORBACK:
				points[player_index] += 10;
			case TROTTER:
				points[player_index] +=10;
			case SNOUTER:
				points[player_index] += 15;
			case JOWLER:
				points[player_index] += 5;
			}
		if(points[player_index] >= 100){
			printf("Congradulations %s\n", names[player_index]);
		break;
		}
	}
	return 0;
}
		


