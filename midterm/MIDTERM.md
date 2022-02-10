# CSE 13s, Winter 2022 -- Midterm Exam

  * name: Granger Pasko
  * email: gpasko@ucsc.edu  (put yours here)

*I understand that getting help from a classmate or an external source would
be a violation of academic integrity. So I did all of this work myself.*
signed: Granger Pasko


**HOWTO do this midterm** -- this is a take-home exam, to be done by just you,
with your notes, with the reading materials, and with your ability to read man
pages and search the web. Do not consult with other students, and do not ask
people other than the course staff for help!

The midterm is due in 24 hours (+ accommodations), and turned in the same way
that we turn in homeworks. You must check in your materials into your
course git repository *and* upload the relevant commit ID on Canvas by then.
For most students, this is due at *1:20pm on Thursday 10 February 2022*. 

So make sure you check in *at least* these files into a directory called
`midterm` in your git repository:
  * your completed `MIDTERM.md` (ie, this file, filled out)
  * your completed `midterm.c`
  * your `Makefile` for compiling the code -- make sure to turn on the strict
    compiler flags before turning in.

For short answer questions, write your response in this file. For the
programming problems, write a short explanation of what your code does (and *why
it does it!*) in this file, and complete the program in `midterm.c`.

## problem 1

Write a function that returns the first *n* Fibonacci numbers, in a dynamically
allocated array of type `long long`. Recall that the sequence goes 1, 1, 2, 3,
5, 8...

Should this be done iteratively or recursively?

I believe it can be done both ways as long as you declare the array before hand.	

YOUR PLAN & EXPLANATION HERE (code goes in midterm.c)

I plan to complete the problem using an iterative method becasue I'm not as comfortable with
recursion. My plan is to have an if check to see what the input n is. If it's 0 I'll return 0.
I set two variables (num1 and num2) to 1. I'll append num1. If n == 1 ill return the array.
I'll then append num2 and if n == 2 return the array. Then Ill make a for loop and I will 
declare a temp var to be the sum of the two 1's, append that value to the array, set num1 to
value of num 2, sest num 2 to value of sum (temp). return array at the end.

## problem 2

[Bubble sort](https://en.wikipedia.org/wiki/Bubble_sort) is a simple (but
relatively inefficient) sorting algorithm that works by comparing elements in an
array and swapping them if they are in the incorrect order.

The pseudocode looks like:

* keep doing this...
  * for every element x of my input array
    * for every *other* element y of my input array
      * if x should go before y but does not, swap x and y's position in the
        array
* stop if I did not perform any swaps

Imagine that we are working at an online shoe retailer, and we want to sort our
customers by their shoe size.

Implement a function for bubble sorting procedure that sorts customers by shoe
size, ascending. Smallest shoe sizes should go first, larger shoe sizes later.

## problem 3

Recall in homework 2, we wrote a function `reduce`, which took a collection of
numbers and reduced it down to a single number, essentially a summary of that
collection.

Here we will write a version of the companion function to *reduce*, which is
called [*map*](https://en.wikipedia.org/wiki/Map_(higher-order_function)). Map
takes a function and applies that function to each element in the collection,
and returns a collection of the same shape.

In this version, we will take in a linked list of floating point numbers (see
`LLfloat` in the code) and return a *new* linked list of floating point numbers,
of the same length, where each element of the new list is the result of calling
the specified function on the corresponding number in the input list.

For example, if your input list consisted of:
`[0, 1, 2, 3]`

And your specified function computed the square of the input number, then your
function would return a new linked list (you'll have to allocate it with
`malloc` or `calloc` !) containing:
`[0, 1, 4, 9]`

YOUR PLAN & EXPLANATION HERE (code goes in midterm.c)

To do this, I will first make a helper function to find length of numbers by using recursion and adding one to 
return value every time there is a next node. I will then create a new array with length and sizeof(LLfloat) as 
params. I will for loop through the new array until i == length and set every value at i in the new array to 
f(numbers[i]) then return the new array.

## problem 4

Imagine that we are building a calendar system, and we want to find out when a
group of different users are available for a meeting. Here we will represent a
user's availability with a bit vector in the form of an `unsigned long` -- we
get 64 different appointment slots during a week, and a user can be either
*available* (the bit is set to 1) or *unavailable* (the bit is set to 0) for
that appointment slot.

Write a function that takes an array (ie, a pointer to an array) of these
bit-vector calendars, a number of users (ie, the size of the array) and returns
a single `unsigned long` where each bit in the unsigned long is set to 1 if *all
users* are available at that time.

YOUR PLAN & EXPLANATION HERE (code goes in midterm.c)
If there are 0 people return 0. If there is 1 person return their availability. If there is more, loop through
calendars and use bitwise and to comapre each persons calendar and return the result.

## problem 5 (short answer)

Consider the following code snippet:

```
float f[10];
float *p;
p = f;
p++;
```

Say that you found out that the array `f` was at memory address `0xC0FF33`. In
your own words, what did we do on the line `p++`, and what is the value of `p`
after this code runs? What is the value of `p + 5`? (give these as hexidecimal
numbers)

YOUR ANSWER HERE
After we set p = f, the address of p and f are now both 0xC0FF33. By doing p++, we move change the address of p
(which is the same as f and f[0]) to the memory address of p[1] which is 0xCOFF37. The value of p (which we get by
using the star pointer is whatever value was in f[1]. If we do p +5 instead of p++, p becomes the address of the 5th
element in f which is 0xCOFF53 and the value of p becomes f[5].

(I like that you made the Hexidecimal spell coffee. Very fitting for this mideterm lol)

## problem 6 (short answer)
In math, how many real numbers are there? Comparatively, in a computer, how many
floating point numbers (C type `float`) are there? How could you find out how
many floating point numbers there are, for sure?

YOUR ANSWER HERE
In math, there are infinite real numbers. In a computer, there are 2^32 possible numbers that a float value can be
because its 2 to the number of the number of bits allocated to the type float which is 32 unless the size is 
changed to 64 bits on a 64 bit computer.
