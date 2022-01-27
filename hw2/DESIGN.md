Project outline:
	This homework is a more of a collection of smaller problems rather than one big lab.
However, some of these functions work together and need eachother to run smoothly. I will
break down my psuedo for reach individual fucntion below. A lot of these functions I have 
been able to previously with languages like python but this is my first time doing it in a low
level assembly language.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Max Element Psuedo:

Take array
set new variable int maximum to MIN INT
loop through array and if array[i] is bigger than maximum set maximum to array[i]
once i = (len(array) -1) return maximum
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Summing all of the positive elements in an array psuedo:

Take array
Create variable called total that equals 0
Loop through array
	If array[i] is >0 then add it to total
return total
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Reduce:

Create for loop to loop through len
Set inital equal to results of f (helper function)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Max with Reduce:

If initial is smaller than comparing variable: set initial to variable
return initial
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Sum of pos with redude:

if num is >0 add num to initial
return initial
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Counting neg with redude:
if num < 0: add 1 to initial
return initial
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
