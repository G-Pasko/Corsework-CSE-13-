Design Document:

For this assignment, we are tasked with creating a calculator using the stack. To accomplish this, we will complete
stack push, stack pop, stack empty, stack delete, stack compute step. We will be using inputs included from a
.txt file titled "input.txt." We will be pusing and deleting values into the stack memory for the test file
to use and run.

Psuedocode:

Stack Push:
Get size of stack and set it to variable
Push the value to the top of the stack
Check if new size of stack is the same as old size
if yes: return false
if no: return true

Stack pop:
Create variable and set its value to the value at bottom of the stack. Then, free the bottom node of the stack and
Move the other values down one spot.

Stack empty:
If size of stack is 0, return true

Stack delete:
Recursive loop:
	If top = null return pointer
	else free bottom of of stack and run stack delete with value.next as param

Stack Compute Step:
I'm not sure how to do this one, tbh but I'll try to come back to it later after starting some of the other
functions.
