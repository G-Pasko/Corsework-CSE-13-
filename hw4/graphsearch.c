#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "graphsearch.h"

// dealing with sets of integers. We wrote these in class.
LLint *add_to_set(LLint *set, int val) {
  LLint *newfront = calloc(1, sizeof(LLint));
  newfront->val = val;
  newfront->next = set;
  return newfront;
}

bool set_contains(LLint *set, int val) {
  if (set == NULL) {
    return false;
  } else if (set->val == val) {
    return true;
  } else {
    return set_contains(set->next, val);
  }
}
//Modified stack functions from hw3
bool stack_push(Stack *s, Path new) {	//Pulled stack push from hw3
	LLPath *newnode = (LLPath *)calloc(1, sizeof(LLPath));
	if(newnode == NULL){
		return false;
	}
	newnode->val = new;
	newnode->next = s->top;
	s->top = newnode;
	return true;
}

void graph_delete(Graph **g){
	for(int i = 0; i < (*g)->vertices; i++){
		free((*g)->matrix[i]);
	}	
	free((*g)->matrix);
	free(*g);
	g = NULL;
}


void set_delete(LLint **set){
	LLint *delete = (*set);
	while((*set) != NULL){
		(*set) = (*set)->next;
		free(delete);
		set_delete(set);
	}
	free((*set));
	set = NULL;
}
bool stack_pop(Stack *s, Path *output) {	//Pulled stack pop form hw3
	if(s->top == NULL || s == NULL){
		return false;
	}
	*output = s->top->val;
	LLPath *temp = s->top;
	s->top = s->top->next;
	free(temp);
	return true;
}

bool stack_empty(Stack *s) {
	if(s->top == NULL){
		return true;
	}
	return false;
}

Stack *stack_create(void) {		//Pulled stack create from hw3
	Stack *out;
	out = (Stack *)calloc(1, sizeof(Stack));
	return out;
}

void stack_delete(Stack **s) {
	while((*s)->top != NULL){
		LLPath *delete = (*s)->top;
		(*s)->top = (*s)->top->next;
		free(delete);
	}
	free((*s));
	s = NULL;
}

// Linked lists of paths. You'll need to implement these.

// Returns the new front of the queue, for a queue of Path structs.
// Usually this will be the old front of the queue, but if q is NULL, then it
// will allocate a new linked list node and return that.
LLPath *enqueue_path(LLPath *q, Path path) {
  // YOUR CODE HERE
	LLPath *newnode = calloc(1, sizeof(LLPath));	//Copied from demo but changed types to match lab
	newnode->val = path;
	if(q == NULL){
		return newnode; 
	}
	LLPath *cur = q;
	while(cur->next != NULL){
		cur = cur->next;
	}
	cur->next = newnode;
	return q;
}

bool dequeue_path(LLPath **q, Path *ret) {
  // YOUR CODE HERE
	if(*q == NULL){			//Copied from demo but changed types to match lab
		return false;
	}	
	*ret = (*q)->val;
	LLPath *freethis = *q;
	*q = (*q)->next;
	free(freethis);
	return true;
}

// We wrote these in class.
Graph *graph_create(int vertices) {
  Graph *g = (Graph *)malloc(sizeof(Graph));
  g->vertices = vertices;
  g->matrix = (int **)calloc(vertices, sizeof(int*));
  for (int i=0; i < vertices; i++) {
    g->matrix[i] = (int *)calloc(vertices, sizeof(int));
  }
  return g;
}

void graph_add_edge(Graph *g, int i, int j) {
  g->matrix[i][j] = 1;
}

bool graph_has_edge(Graph *g, int i, int j) {
  return g->matrix[i][j];
}

// Convenience method for you -- returns a new Path where you have added another
// vertex along the path.
Path path_extend(Path path, int new_vertex) {
  Path out;
  out.steps = path.steps;
  for (int i=0; i < path.steps; i++) {
    out.vertices_visited[i] = path.vertices_visited[i];
  }
  out.vertices_visited[path.steps] = new_vertex;
  out.steps += 1;
  return out;
}

// Print out a path nicely for the user.
void print_path(Path path) {
  if (path.steps == 0) {
    puts("(empty path)");
  }
  for (int i=0; i < path.steps; i++) {
    printf("%s%d",
        (i == 0) ? "" : " -> ",
        path.vertices_visited[i]);
  }
  puts("");
}

// Breadth-first search!
Path graph_find_path_bfs(Graph *g, int i, int j) {
  // YOUR CODE HERE.
	LLint *visited = NULL;			//Same initialization as demo but changed type to match lab
	LLPath *to_visit = NULL;		
	Path test_path;				//Create test path to obtain initial to_visit values	
	test_path.steps = 0;			//Set steps to 0 because thats the only way to make it run for some reason
	to_visit = enqueue_path(to_visit, path_extend(test_path, i));	//Use path extned to make new path for param
									//so that to_return doesnt get uninitialized
	
	while(to_visit != NULL){
		Path current;				//Initialize new path to return
		dequeue_path(&to_visit, &current);	//Enter to visit value into next node on current path
		int current_val = current.vertices_visited[current.steps -1];
		if(current_val == j){
			//graph_delete(&g);
			free(to_visit);
			set_delete(&visited);
			return current;
		}
		
		visited = add_to_set(visited, current_val);	// Add most recent node to "visited"
		for(int nieghbor = 0; nieghbor < g->vertices; nieghbor++){
			if(graph_has_edge(g, current_val, nieghbor) && !set_contains(visited, nieghbor)){
				to_visit = enqueue_path(to_visit, path_extend(current, nieghbor));
			}	//For loop is meant to obtain next possible nodes and put them in to_visit
		}
	}
  free(to_visit);
  set_delete(&visited);		
  Path empty = {0, {0}};
  return empty;
}

// Depth-first search!
Path graph_find_path_dfs(Graph *g, int i, int j) {
  /* YOUR CODE HERE.
	keep a set of vertices that we have visited
	keep a stack of vertices that we want to visit
	put the starting vertex into the stack
	while there are more places to visit in the stack:
		pop the next place to visit
		see if it is our intended destination -- if it is, return success!
		otherwise, add to set of visited nodes if not in set
		push each of its neighbors that have not been visited
	return false if the stack becomes empty (we ran out of options)
*/
	
	LLint *visited = NULL;		//Create set to hold visited nodes	
	Stack *to_visit = stack_create();	//Create stack to hold nodes to visit
	Path test_path;				//Create path to implement starting point using path_extend
	test_path.steps = 0;
	stack_push(to_visit, path_extend(test_path, i));
	int prev_node = -1;
	while(to_visit != NULL){		//While there are nodes to visit...
		Path current;
		stack_pop(to_visit, &current);
		int current_val = current.vertices_visited[current.steps - 1];
		if(prev_node == current_val){		//Inf loop check for impossible graphs
  			set_delete(&visited);
  			stack_delete(&to_visit);
			Path empty = {0, {0}};
			return empty;
		}
		prev_node = current_val;
		if(current_val == j){
			stack_delete(&to_visit);
			set_delete(&visited);
			return current;
		}
		visited = add_to_set(visited, current_val);     // Add most recent node to "visited"
		for(int nieghbor = 0; nieghbor < g->vertices; nieghbor++){
			if(graph_has_edge(g, current_val, nieghbor) && !set_contains(visited, nieghbor)){
				stack_push(to_visit, path_extend(current, nieghbor));                         
				}       //For loop is meant to obtain next possible nodes and put them in to_visit
                 }
         }
  stack_delete(&to_visit);
  set_delete(&visited);
  Path empty = {0, {0}};
  return empty;
}
