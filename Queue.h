#ifndef Queue_h
#define Queue_h
#define RAMEN 100
#define DONBURI 69
#define TAKOYAKI 49
struct node
{
    int order_number;
    int qty;
    struct node *nextPtr;
};

typedef struct node Node;
typedef struct node* NodePtr;


typedef struct {
	 NodePtr headPtr,tailPtr;
	int size;
}Queue;


void enqueue_struct(Queue* q, int x, int y){ //stuct, order_number, qty
  Node *new_node=(Node*) malloc(sizeof(Node));
if(new_node){
  /*Finish enqueue */
  //Insert new data to new_node
  new_node->order_number = x; //set order_number to x
  new_node->qty = y; //set qty to y
  new_node->nextPtr = NULL;
  printf("My order is %d\n", new_node->order_number);

  //Node operation
  if(q->headPtr) q->tailPtr->nextPtr = new_node;
  else q->headPtr = new_node;
  q->tailPtr = new_node;
  q->size++;
 }
}


int dequeue_struct(Queue *q, int silent){
   NodePtr t=q->headPtr;
   if(t && q->size > 0){
   int value;
     switch(t->order_number){
       case 1 : if(silent==0) printf("Ramen\n"); value = RAMEN; break;
       case 2 : if(silent==0) printf("Donburi\n"); value = DONBURI; break;
       case 3 : if(silent==0) printf("Takoyaki\n"); value = TAKOYAKI; break;
       default : if(silent==0) printf("No Food\n"); value = 0;
     }
     value *= t->qty;
       /*Finish dequeue */
    //Node operation
    q->headPtr = t->nextPtr;
    if(q->headPtr == NULL) q->tailPtr = NULL;
    free(t);
    q->size--;
   return value; //return value that customer has to pay
   }
   return 0;
}

#endif