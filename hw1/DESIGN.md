#This is my design document

Outline of process:

The goal of this lab is to create a simple dice rolling game for 2 to 10 players where the goal is to roll the dye, or
pig, enough times to reach 100 points before the other players.

I think that I will first have to create a user input to determine the number of players and give it a check 
to determine wether or not the number of players entered is a valid value (between 2 and 10). If it does not fit within
that range, two palyers will be used instead. Player 1 (indexed at 0) will roll a die which will have 7 sides with 5
outcomes. These outcomes will be allocated with a number between 1 and 7 with two of the outcomes (landiing on its
side and landing on an ear will both be allocated to two numbers due to their extra chance of being rolled). Depedning on
the roll, points will be allocated to the corresponding players score which will be initialized at the beginning of the
program. I will use cases to determine how many points are rewarded to the player for each roll outcome. Once the player
index reaches the end, it will be set back to 0 (player 1). This porocess will continue until one player reaches the
score of 100 or more.

Psuedocode:

prompt number of players
paste enum function
check if number of players is in bound
	if yes: continue with user input as players
	if no: continue with 2 as players
create array for player scores
initialize player index at 0
while x (player index) is <= num of players +1
	prompt player x to roll
	use cases to determine allocation of points and whos turn is next (by incrimenting x)
	break if playerx's score is >=100



 
