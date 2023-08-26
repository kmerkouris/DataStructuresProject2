#include "ADTStack.h"
#include "ADTQueue.h"
#include <common_types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ADTVector.h>

int* create_int(int value)
{
    int* pointer = malloc(sizeof(int*));
    *pointer=value;
    return pointer;
}


int main(int argc ,char** argv)
{   
    FILE *fp;
    fp=fopen("output.csv","w");

    Queue queue = queue_create(NULL);

    if (argc==1)
    {
         return 1;
    }
    
    if (strcmp(argv[1],"real")==0)
    {
        for (int i = 1; i <= 9000; i++)
        { 
         
            if (i%3 == 0)
            {
                queue_remove_front(queue);
                printf("%d ,   %d\n",queue_steps(queue),queue_size(queue));
                
            }
            else 
            {
            
                queue_insert_back(queue,create_int(i));
                printf("%d ,    %d\n",queue_steps(queue),queue_size(queue));
                
            }
            
        }    
    }  

    else if (strcmp(argv[1],"amortized")==0)
    {
        int amortized=0;
        for (int i = 1; i <= 9000; i++)
        { 
       
            if (i%3 == 0)
            {
                queue_remove_front(queue);
                amortized+=queue_steps(queue);
                
            }
            else 
            {
            
                queue_insert_back(queue,create_int(i));

                amortized+=queue_steps(queue);
            }
             printf("%d , for n :  <%d>\n",amortized/i,i);
        }    
    }
        
      
      
    fclose(fp);
    free(queue);
}
