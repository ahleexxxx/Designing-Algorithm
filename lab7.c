#include "lab7.h"

//this function will print the list
void printList(Node* list){
    printf("\n\n*******PrintList********\n");
    printf("List: ");
    Node* p=list;
    while(p->next!=NULL){
        p=p->next;
        int *value=(int*)(p->data);
        printf("%d->", *value);
    }
    printf("NULL\n");
    printf("*****************************\n");
}





/*This function returns an empty list pointer and contains a placeholder "dummy" node).*/
Node * initList()
{
    Node* list=malloc(sizeof(Node));    //dummyNode
    if(list==NULL){
        printf("memory allocation error at initailizing list!\n");
        return NULL;
    }
    

    list->data=malloc(sizeof(int));
    list->next=NULL;

    return list;

}




/*This function takes a list pointer and return the size of the list.*/
int getSize(Node *list)
{
    return *((int*)(list->data));
    
}

/*This function will take a Node pointer, a void pointer which references user data, and an index at which to insert. 
It will insert the data at the given index in a new node only if the index is valid. 
If the index given is equal to the size of the list, the node will be inserted at the tail of the list. 
It will return 0 on success, or 1 on failure.*/
int insertAtIndex(Node *list, void *data, int index)
{
    Node* newNode=malloc(sizeof(Node));
    if(newNode==NULL){
        printf("the node cannot be created due to the memory allocation error\n");
        return 1;
    }

    newNode->data=data;
    
    if((index<0) || (index >=getSize(list))){
        printf("the node cannot be inserted due to the index error\n");
        return 1;
    }



    int count=0;
    Node* p=list;
    while(p->next != NULL){
        p=p->next;
        count++;
        if(index==(count-1)){
            Node* q=list;
            while(q->next != p){
                q=q->next;
            }
            newNode->next=p;
            q->next=newNode;
        }
    }

    
    ++(*((int*)(list->data)));
    
    


    return 0;
}


/*This function takes a Node pointer, and a void pointer which references user data. 
It will insert the data at the tail of the list.
It will return 0 if success, or 1 if failure.*/
int insertAtTail(Node *list, void *data)
{
    Node* newNode=malloc(sizeof(Node));
    if(newNode==NULL){
        printf("the node cannot be created due to the memory allocation error\n");
        return 1;
    }

    newNode->data=data;
    newNode->next=NULL;

    Node* p=list;
    while(p->next !=NULL){
        p=p->next;
    }
    p->next=newNode;

    
    ++(*((int*)(list->data)));
    
    
    
    return 0;
}


/*This function takes a Node pointer, and returns the data stored in the index of the list, or NULL if the index is not valid.*/
void * getAtIndex(Node *list, int index)
{
    if(index<0 || index>=getSize(list)){
        return NULL;
    }

    Node *p=list;
    for(int i=0; i<=index; i++){
        p=p->next;
    }

    return p->data;
    

}

/*This function takes a Node pointer, 
and remove the data at the given index. It will return the data of the index, or NULL if the index is invalid.*/
void * removeAtIndex(Node *list, int index)
{
    if(index<0 || index>=getSize(list)){
        return NULL;
    }

    Node* p=list;
    for(int i=0; i<=index; i++){
        p=p->next;
    }

    Node* q=list;
    while(q->next !=p){
        q=q->next;
    }

    q->next=p->next;
    void* value=p->data;


    free(p);

    --(*((int*)(list->data)));
    
    
   
    return value;
}

/*This function will free all memory allocated to the list. */
void freeList(Node **list)
{
    Node* p=*list; // pointing to dummyNode
    Node* q;
    while(p->next !=NULL){
        q=p->next;
        p->next=q->next;
        free(q);
    }
   
    free(p); //freeing dummy node

}


