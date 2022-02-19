Granger Pasko's HW5 Design Doc

Lab Description:

In this lab, we are making our own word game based on the popular web game called "Wordle." We will be grabbing a word from a text file and
making that our target word. The user will then get 5 attempts to guess to word. If a letter in the guessed word is in the target word but
not in the right position, we return a Y for yellow at that spot. If the letter is in the correct spot, we return g for green in that spot and
return x if its not in the word. If the word is guessed correctly, it'll return a victory message that will return the word and number of
guesses.

Plan:

Score guess:
	Use a strcmp for guess and secret. If result is 0, make result all green and return end msg.
	Else: Compare each letter in guess to that of secret and return a string with corresponding x,y,g values.

Valid Guess:
	Iterrate through the vocab list and do strcmp with guess and each word. If result ever equals 0 return true
	Else return false

Load Vocablary:
	Open file and do calloc(size_t, charr) to allocate enough room for every word in the vocab list. Then iterrate through the file and copy the strings. Finally,
	close the file and return the array of strings

Free vocabulary:
	Iterate through array of words returned by LoadVocab and free their memery addresss until the the array is empty. Once the array is empty, free the memory address of the 
	array.


