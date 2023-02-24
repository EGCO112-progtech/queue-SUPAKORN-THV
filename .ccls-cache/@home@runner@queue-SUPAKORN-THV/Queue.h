

typedef struct {
	 NodePtr headPtr,tailPtr;
	int size;
}Queue;


void enqueue_struct(Queue* q, int x){
  Node *new_node=(Node*) malloc(sizeof(Node));
if(new_node){
  /*Finish enqueue */
  new_node->data = x;
  new_node->nextPtr = NULL;
  if(q->headPtr) q->tailPtr->nextPtr = new_node;
  else q->headPtr = new_node;
  q->tailPtr = new_node;
  q->size++;
 }
}


int dequeue_struct(Queue *q){
   NodePtr t=q->headPtr;
   if(t && q->size > 0){
   int value= t->data;
       /*Finish dequeue */
    q->headPtr = t->nextPtr;
    if(q->headPtr == NULL) q->tailPtr = NULL;
    free(t);
    q->size--;
   return value;
   }
   printf("Empty queue\n");
   return 0;
}

