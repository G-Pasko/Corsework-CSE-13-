Granger Pasko's Design Doc

Overview:

In this assignment, we are tasked with reading and writing to and fom a text file to store customer data such as name, email, shoesize, and 
favorite food. Our program will be able to read a user input and either add a new customer, delete a customer, print the list of customers, save newly
added or deleted customers, and lastly quit the program.

Psuedo:

First off, were gonna want to create a struct called customer so that each entry can hold values for email, shoe size, name, and fav food.

For our main function, we need to first create an empty array to hold customers. Then, for each line in the text file, we seporate each section 
by splitting the line into parts wherever there is a tab. We can set the first part to email, second part to name, third part to shoe size, and 
fourth to fav food. Then we create a customer class variable with all of those attributes and push the customer to the array we created.

Then, we will create a prompt for the user to perform actions on the text file (add, delete, list, save, quit, lookup).
	
	For add, prompt the user to input the email, name, shoe size, and fav food. Then, that customer will be pushed into the array.

	For delete, will search through the customers array and if an email matches the input, we will delete the customer. Else,
		print out "user not found."
	
	For save, loop through customers array and push each part of the customer to the text file

	For list, loop thorugh customers and print each one.
	
	For lookup, loop through customers and if an email matches the input parameter, print out that customer.
