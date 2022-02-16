Design Doc:

For this assignment, we are tasked with fidning and returning certain paths for traverssing a graph. We will need
to do it once by implementing stack and once with loops or recursion. We will also be working with structs to
help us keep track of paths and nodes. I plan to review the lecture where the professor went over graphing 
algorithems and also try to find my CSE30 assignment where we worked on graphs to get an idea of the structure.

Psuedo:
Breadth First Search:

(Psuedo code given in README)

keep a set of vertices that we have visited
keep a queue of vertices that we want to visit
put the starting vertex into the queue
while there are more places to visit in the queue:
	dequeue the next place to visit
	see if it is our intended destination -- if it is, return success!
	otherwise, make sure it is in the set of visited nodes
	enqueue each of its neighbors that have not been visited
return false if the queue becomes empty (we ran out of options)

Create graph and path delete to free all data allotted to the process
Depth-First Search:

Use the same structure as BFS except use the stack structs and functions from HW3
Use the stack to create the "to visit" set and use stack push for neighbors not in "visited"
Pop values from to add to "current"
Use stack delete functions to clear memory
