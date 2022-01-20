#This is my design document

Outline of process:

I think that I will first have to create a user input to determine the number of players and give it a check 
to determine wether or not the number of players entered is a valid value (between 2 and 10). If it does not fit within
that range, two palyers will be used instead. Player 1 (indexed at 0) will roll a die which will have 7 sides with 5
outcomes. These outcomes will be allocated with a number between 1 and 7 with two of the outcomes (landiing on its
side and landing on an ear will both be allocated to two numbers due to their extra chance of being rolled). Depedning on
the roll, points will be allocated to the corresponding players score which will be initialized at the beginning of the
program. Once the player index reaches the end, it will be set back to 0 (player 1). This porocess will continue until
one player reaches the score of 100 or more.

Psuedocode:

prompt number of players
check if number of players is in bound
	if yes: continue with user input as players
	if no: continue with 2 as players
 
