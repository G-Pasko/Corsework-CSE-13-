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
	int num_players_input;
	int prev_player = 99;
	//printf("num_players initialzied\n");
	printf("How many players? ");
	scanf("%d", &num_players_input);
	if(!(num_players < 11) && (num_players > 1)){
		num_players = 2;
		fprintf(stderr, "Invalid number of players. Using 2 instead .\n");
	}
	else{
		num_players = num_players_input;
		//printf("num players defined as %d\n", num_players);
	}
	
	int seed = 0;
	int seed_input;
	printf("Random seed: ");
	if((scanf("%d", &seed_input) == 1) && (seed_input < INT_MAX) && (seed_input > 0)){
	//printf("seed is: %d and seed_input is %d\n", seed, seed_input);
		//if((seed_input < INT_MAX) && (seed_input > 0)){
			//seed = seed_input;
                //printf("seed defined as %d\n", seed);

		//fprintf(stderr, "Invalid ranodm seed. Using 2022 instead.\n");
		//seed = 2022;
		//}
		seed = seed_input;
		
	}
	else{
		fprintf(stderr, "Invalid random seed. Using 2022 instead.\n");
                seed = 2022;

		//seed = seed_input;
		//printf("seed initialzized as %d", seed);
	}
	srandom(seed);
	int points[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int player_index = 0;
	while(player_index < (num_players + 1)){
		//printf("player_index: %d. prev_player: %d\n", player_index, prev_player);
		//printf("%d", player_index == prev_player);
		if(player_index != prev_player){
			printf("%s rolls the pig... ", names[player_index]);
		}
		int roll = (random() % 7);
		switch(pig[roll]){
			case SIDE:
				printf("pig lands on side\n");
				if(points[player_index] >= 100){
					printf("\n%s wins with %d points!\n", names[player_index], points[player_index]);
					return 0;
				}
				prev_player = player_index;
				player_index += 1;
				//prev_player = player_index;
				break;
			case RAZORBACK:
				printf("pig lands on back ");
				points[player_index] += 10;
				if(points[player_index] >= 100){
					printf("\n%s wins with %d points!\n", names[player_index], points[player_index]);
					return 0;
				}
				prev_player = player_index;
				break;
			case TROTTER:
				printf("pig lands upright ");
				points[player_index] +=10;
				if(points[player_index] >= 100){
					printf("\n%s wins with %d points!\n", names[player_index], points[player_index]);
					return 0;
				}
				prev_player = player_index;
				break;
			case SNOUTER:
				printf("pig lands on snout ");
				points[player_index] += 15;
				if(points[player_index] >= 100){
					printf("\n%s wins with %d points!\n", names[player_index], points[player_index]);
					return 0;
				}
				prev_player = player_index;
				break;
			case JOWLER:
				printf("pig lands on ear ");
				points[player_index] += 5;
				if(points[player_index] >= 100){
					printf("\n%s wins with %d points!\n", names[player_index], points[player_index]);
					return 0;
				}
				prev_player = player_index;
				break;
			}
		
		//if(points[player_index] >= 100){
			//printf("Congradulations %s\n", names[player_index]);
			//break;		
		//}
		
		if(player_index == num_players){
			player_index = 0;
		} 	
	}
	return 0;
}
