Granger's Design Doc

~~Thoughts and Plan~~

	This lab is a challenge activity that tasks us with building a wordle solver. This solver will be built on the processs of giving letters scores baseed on how often
	they show up in words. Then words are then scored  by the accumulation of the scores of the letters in the word. Then, we will filter the vocabularly to remove all words that have 
	one of the grey letters in them. Next, we remove all words that don't contain the letters in yellow (if there are any) and then remove the words with the yellow letters in
	the same position as the guess. Finally, for filtering green letters, we remove  all words without thee green letters in the same position as the guess.

~~Psuedo~~

	Score letter:
		Create int score at 0
		loop through vocab
		loop through word and if the letter of interest shows up, add 1 to score andmove onto next word.
	Score word:
		Set int score to 0
		Create an empty char array
		For each letter, if the letter hasnt been accounted for, run score letter and add letter score to "score." 
			Add letter to array
		
	Filter Vocab Grey:
		For every word in vocab: if it contains the letter given, free the word and set the pointer to NULL
	Filter Vocab Yellow:
		For every word in vocab: if the word doesnt contain the letter OR the word contains the letter at the same position: free word in vocab and set pointer to NULL
	Filter Vocab Green:
		For every word in vocab: if the word doesnt have the letter in the same position. 	



