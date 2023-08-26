///////////////////////////////////////////////////////////////////////
//
// Υλοποίηση του ADT Queue μέσω του ADT Stack (dependent data structure)
//
///////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <assert.h>

#include "ADTQueue.h"
#include "ADTStack.h"
#include "ADTVector.h"


// Ένα Queue είναι pointer σε αυτό το struct.
struct queue {
	Stack stack_front_bottom;
	Pointer front_in_bott;
	int steps;
}; 


Queue queue_create(DestroyFunc destroy_value) {
	Queue queue = malloc(sizeof(struct queue));
	queue->stack_front_bottom = stack_create(destroy_value);
	queue->front_in_bott = NULL;
	return queue;
}

int queue_size(Queue queue) {
	return stack_size(queue->stack_front_bottom);
}

Pointer queue_front(Queue queue) {
	return queue->front_in_bott;
}

Pointer queue_back(Queue queue) {
	return stack_top(queue->stack_front_bottom);
}

void queue_insert_back(Queue queue, Pointer value) {
	if (stack_size(queue->stack_front_bottom)==0)
	{
		queue->front_in_bott = value;
		
	}
	stack_insert_top(queue->stack_front_bottom,value);
	queue->steps=1;

	
}

void queue_remove_front(Queue queue) {
	//temporary container
	Vector vec = vector_create(0,NULL);
	Stack stack = queue->stack_front_bottom;

	DestroyFunc temporary = stack_set_destroy_value(stack,NULL);

	while(stack_size(stack)>1)
	{
		vector_insert_last(vec,stack_top(stack));
		
		stack_remove_top(stack);

		
	}

	if (stack_size(stack)>0)
	{
		queue->steps=vector_size(vec);
	}
	else
	{
		queue->steps=1;
	}
	

	stack_set_destroy_value(stack,temporary);
	if (stack_size(stack)>0)
	{
		stack_remove_top(stack);
	}
	queue->front_in_bott= vector_size(vec)>0 ? vector_node_value(NULL,vector_last(vec)):NULL;
	
	
	for(int i = vector_size(vec) - 1; i >= 0; i--)
	{
		stack_insert_top(stack, vector_get_at(vec, i));
	
		
	}
		
	
	

	vector_destroy(vec);
 
}    


DestroyFunc queue_set_destroy_value(Queue queue, DestroyFunc destroy_value){
	return stack_set_destroy_value(queue->stack_front_bottom, destroy_value);
}

int queue_steps(Queue queue)
{
	return queue->steps;
}


void queue_destroy(Queue queue) {
	stack_destroy(queue->stack_front_bottom);
	free(queue);
}