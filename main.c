#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "Node.h"
#include "Queue.h"

int main(int argc , char **argv) {
  NodePtr headPtr=NULL;
  NodePtr tailPtr=NULL;
/* For struct Queue */
  Queue  q;
   q.headPtr=NULL;
   q.tailPtr=NULL;
   q.size=0;
  
   int i,x,count=0,input;
   

 for(i=1;i<argc;i+=2/*i++*/){
        if(strcmp(argv[i],"x")==0){
            //x=dequeue(&headPtr,&tailPtr);
            printf("Customer no: %d\n",++count);  
            x = dequeue_struct(&q,0);
            i--;
            if(x!=0) {
              printf("You have to pay %d\n",x);
            
            do{
              printf("Cash: ");
              scanf(" %d", &input);
              }while(input < x);
              if(input-x > 0) printf("Change is: %d\n", input-x);
            }
              printf("Thank you\n\n");
        }
        else {
        //enqueue(&headPtr,&tailPtr, atoi(argv[i]));
        enqueue_struct(&q, atoi(argv[i]), atoi(argv[i+1])); //stuct, order_number, qty
        //i++;
          }
 }
  printf("=============================================\n");
  switch(q.size)
    {
      case 0: printf("There is no person left in the queue.\n"); break;
      case 1: printf("There is %d person left in the queue.\n", q.size); 
              dequeue_struct(&q,1); break;
      default: printf("There are %d ppl left in the queue.\n", q.size);
               while(q.size>0) dequeue_struct(&q,1); //dequeue all queues
    }
  printf("=============================================\n");
  printf("Queue's size is now %d!\n",q.size);
  return 0;
}
