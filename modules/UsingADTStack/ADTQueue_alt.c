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
    Stack stack_back_bottom;
    int steps;
    Pointer pointer_bot1;//bottom
    Pointer pointer_bot2;//bottom
}; 


Queue queue_create(DestroyFunc destroy_value) {
	Queue queue = malloc(sizeof(*queue));
	queue->stack_front_bottom = stack_create(destroy_value);
    queue->stack_back_bottom = stack_create(destroy_value);
	queue->pointer_bot1 = NULL;
    queue->pointer_bot2 = NULL;
	return queue;
}

int queue_size(Queue queue) {
    
	return stack_size(queue->stack_front_bottom)+stack_size(queue->stack_back_bottom);
}

//εχω την 2η στοιβα που επιστρεφει stack2 για το στοιχειο στο εμπρος μερος
Pointer queue_front(Queue queue) {
    //αν το μεγεθος της δευτερης στοιβας δεν ειναι 0 επιστρεφςι απο εκει την τιμη 
    if (stack_size(queue->stack_back_bottom)!=0)
    {
        return stack_top(queue->stack_back_bottom);
    }
    return queue->pointer_bot1;
    
	
}

//εχω την 1η στοιβα που επιστρεφει stack για το στοιχειο στο πισω μερος
Pointer queue_back(Queue queue) {
    //αν το μεγεθος της πρωτης στοιβας δεν ειναι 0 επιστρεφςι απο εκει την τιμη 
	if (stack_size(queue->stack_front_bottom)!=0)
    {
        return stack_top(queue->stack_front_bottom);
    }
    return queue->pointer_bot2;
    
}

void queue_insert_back(Queue queue, Pointer value) {
	if (stack_size(queue->stack_front_bottom)==0)
	{
        queue->pointer_bot1 = value;
	}
    stack_insert_top(queue->stack_front_bottom,value);
    queue->steps=1;
}

void queue_remove_front(Queue queue) {
    
	if(stack_size(queue->stack_back_bottom) == 0)
    {
        DestroyFunc temp = stack_set_destroy_value(queue->stack_front_bottom, NULL);
        int size = stack_size(queue->stack_front_bottom);
        //copy to stack2
        for(int i = 0; i < size; i++){
            stack_insert_top(queue->stack_back_bottom, stack_top(queue->stack_front_bottom));

           
            if(stack_size(queue->stack_back_bottom) == 1)
            {
                queue->pointer_bot2 = stack_top(queue->stack_back_bottom);
                
            }
            stack_remove_top(queue->stack_front_bottom);
            
        }
        
        queue->pointer_bot1=NULL;
        stack_set_destroy_value(queue->stack_front_bottom, temp);
    }
    if (stack_size(queue->stack_back_bottom)>0)
    {
        stack_remove_top(queue->stack_back_bottom);
        queue->pointer_bot1=NULL;
       

    }
    
    if (stack_size(queue->stack_back_bottom)>1)
    {
        //τοσα removes τοσα βηματα στην πολυπλοκοτητα
        queue->steps=stack_size(queue->stack_back_bottom);
    }
    else if(stack_size(queue->stack_back_bottom)>0)
    {
        queue->steps=1;
    }

    
    

    if(stack_size(queue->stack_back_bottom) == 0)
    {   
        queue->pointer_bot2 = NULL;
    }
    
   
    
}
DestroyFunc queue_set_destroy_value(Queue queue, DestroyFunc destroy_value){
	return stack_set_destroy_value(queue->stack_back_bottom, destroy_value);
}

int queue_steps(Queue queue)
{
	return queue->steps;
}

void queue_destroy(Queue queue) {
	stack_destroy(queue->stack_front_bottom);
    stack_destroy(queue->stack_back_bottom);
	free(queue);
}