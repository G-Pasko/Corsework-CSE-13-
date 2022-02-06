Design Document:

For this assignment, we are tasked with creating a calculator using the stack. To accomplish this, we will complete
stack push, stack pop, stack empty, stack delete, stack compute step. We will be using inputs included from a
.txt file titled "input.txt." We will be pusing and deleting values into the stack memory for the test file
to use and run.

Psuedocode:

Stack Push:
Create node
If new node is null return false
set item to item of new node and set next to top and set new node to top


Stack pop:
If top equals null return false
Set output to item of top
Make  temp equal top.nect
Pop top and set  top to temp

Stack empty:
If size of stack is 0, return true

Stack delete:
If Top doesnt equal null 
	set temp to top
	set top.next to top
	delete temp
	call delete again

Stack Compute Step:
If item type is number: call push stacl
call pop twice and set value of popped item to y and x respectively
if add: push node w item equal to x + y
if subtract: push node w item equal to x - y
if mult: push node w item equal to x * y
if divide: push node w item equal to x / y
	if y = 0 return false
