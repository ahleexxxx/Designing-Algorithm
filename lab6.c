#include "lab6.h"


/*The function returns an empty list pointer.*/
Node * initList()
{
    return NULL;

}

/*The function takes a list pointer and returns the size of the list starting from 1*/
int getSize(Node *list)
{
    int count=0;
    for(Node* p=list; p !=NULL ; p=p->next){    //if the list is empty(NULL), for loop will be skipped and return 0(count variable)
        count++;
    }
    return count;
}

/*The function takes a double Node pointer, and a void pointer which represents the data from the user. 
The data will be inserted onto the head of the list. It will return 0 for success, or 1 for failure.*/
int insertAtHead(Node **list, void *data)
{
    Node *newNode=malloc(sizeof(Node));
    if(newNode==NULL){
        printf("memory allocation failed.\n");
        return 1;
    }
    newNode->data=data;     //if the list is empty, the code will work the same
    newNode->next=*list;
    *list=newNode;
    return 0;
}

/*The function takes a double Node pointer, 
and removes and returns the data stored at the head of the list, or NULL if the list is empty.*/
void * removeFromHead(Node **list)
{
    Node* remove=*list;
    if(remove==NULL){       //if statement will check whether the list is empty, and return NULL
        return NULL;
    }

    void* data=remove->data;
    *list=remove->next;
    free(remove);

    return data;
}

/*The function takes a double Node pointer, and free all memory allocated for the list. 
The value of the list pointer in the calling function will be set to NULL.*/
void freeList(Node **list)
{
    Node* p;
    while(*list!=NULL){
        p=*list;
        *list=p->next;
        free(p);
        p=NULL;
    }
}


//THE FUNCTIONS BELOW ARE NOT GENERIC! assume the list contains Car struct pointers.

/* the function is a getter func for getWithMostMilesDriven() function*/
float getMilesDriven(Car *car)
{
    return car->milesDriven;
}

/*The function takes a list of Car structs, 
and returns a pointer to the car in the list which has the most miles driven, or NULL if it is empty.*/
Car * getWithMostMilesDriven(Node *list)
{
    if(list==NULL){
        return NULL;
    }

    Car* car=list->data;
    for(Node* p=list->next; p !=NULL; p=p->next){
        if(getMilesDriven(car)<getMilesDriven(p->data)){
            car=p->data;
        }
    }

    return car;

}

/*This function takes a list of Car structs, and print each struct on its own line.*/
void printCars(Node *list)
{
    printf("\n****Printing Car list****\n");
    Car* car;
    for(Node* p=list; p !=NULL; p=p->next){
        car=p->data;
        printf("[CarVin #%d - milesDriven: %.2f - accidents: %d ]\n", car->vin, car->milesDriven, car->numberOfAccidents);
    }
    printf("*************************\n");
}


