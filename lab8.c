#include "lab8.h"

// -------------------------------- STRUCT DEFINITIONS

typedef struct Node Node;

// suggested implementation
struct Queue {
	int size;
	Node *front;      //changed it to front and rear instead of head and tail 
	Node *rear;
};

struct Node {
	void *data;
	Node *next;
};


//O(1)
/*This function returns an empty Queue pointer.*/
Queue * initQueue()
{
    Queue* q=malloc(sizeof(Queue));
    if(q==NULL){
        printf("memory allocation error\n");
        return NULL;
    }
    q->size=0;
    q->front=NULL;
    q->rear=NULL;

    return q;
}


//O(1)
/*This function takes a Queue pointer and will return the size of the Queue.*/
int getSize(Queue *q)
{
    return q->size;

}


//O(1)
/*This function tkaes a Queue pointer and a data pointer. 
It will place the data at the rear/back of the queue. 
It will return 0 on success, or 1 on failure.*/
int enQueue(Queue *q, void *data)
{
    Node* newNode=malloc(sizeof(Node));
    if(newNode==NULL){
        printf("memory allocation error\n");
        return 1;
    }

    newNode->data=data;
    newNode->next=NULL;

    if(q->front==NULL){     //when the Queue is Empty
        q->front=newNode;
        q->rear=newNode;

    }
    else{
        q->rear->next=newNode;
        q->rear=newNode;
    }
    
    q->size++;
    return 0;
}


//O(1)
/*This function takes a Queue pointer, 
and it will just return the data at the front of the Queue if the queue is not empty. 
It will return NULL if the Queue is empty*/
void * peek(Queue *q)
{
    void* data;
    if(q->front==NULL){
        printf("Queue is empty\n");
        return NULL;
    }

    data=q->front->data;
    return data;
}


//O(1)
/*This function takes a Queue pointer, and remove and return the data at the front of the Queue.
It will return NULL if the queue is empty.*/
void * deQueue(Queue *q)
{
    Node* remove=q->front;
    void* data;
    if(q->front==NULL){
        printf("Queue is empty\n");
        return NULL;
    }

    data=remove->data;
    q->front=remove->next;
    if(q->front==NULL){
        q->rear=NULL;
    }

    free(remove);
    q->size--;
    return data;
}


//O(n)
/*This function takes a Queue pointer, and will free all memory allocated.*/
void freeQueue(Queue *q)
{
    Node* p;
    while(q->front !=NULL){
        p=q->front;
        q->front=p->next;
        free(p);
        p=NULL;
    }

    q->rear=NULL;
   

    free(q);
}


