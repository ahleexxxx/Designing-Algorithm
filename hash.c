//#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "hash.h"

// These are stubs.  That is, you need to implement these functions.

//inserting the element in a hashtable
int InsertFailCollision(	void * hashtable, int elementSize, int elementCountMax,
                            int key, void * element, int (*HashFunc)(int key))
{
    int index=(*HashFunc)(key);
    if(index>=0 && index<=elementCountMax){
        char *check=(hashtable+elementSize*index);
        if(*check==0){
            memcpy((hashtable+elementSize*index), element, elementSize);
            return 0;
        }
        else{
            return -1;
        }
    }
    return -1;
    
}

//Searching the element
void * SearchNoCollision(void * hashtable, int key, int elementSize, int (*HashFunc)(int key))
{
    int index=(*HashFunc)(key);
    char *item=malloc(sizeof(char)*elementSize);
    for(int i=0; i<elementSize; i++){
        item[i]=*((char*)hashtable+elementSize*index+i);
    }

    if(item[0] !=0){
        return item;
    }
    else{
        return NULL;
    }
    
}

//division method
int DivMethod(int key)
{
	return key%100;
    
}

//I created Myfloor function rather than using floor function in math.h, because I had compiling issue using floor function
int Myfloor(double num)
{
    return (int)num;
}

//multiplication method
int MultMethod(int key)
{
    double A= (sqrt(5)-1)/2.00;
    //return floor(TABLESIZE*((key*A)-floor(key*A)));
    return Myfloor(TABLESIZE*(key*A-Myfloor(key*A)));
}



//Chaining method starts from here
typedef struct Node {
    void* element;
	int key;
    struct Node* next;
} Node;

//creating chain table
void * AllocateChainTable(int elementCountMax)
{
	Node** ChainTable=malloc(sizeof(Node*)*elementCountMax);
	if(ChainTable==NULL){
		//printf("failed allocating ChainTable\n");
		return NULL;
	}

    for(int i=0; i<elementCountMax; i++)
	{
		ChainTable[i]=NULL;
	}

    return ChainTable;
   
}

//returning the memory allocated for chain table
void FreeChainTable(void * hashtable)
{
	Node** ChainTable=hashtable;
	for(int i=0; i<TABLESIZE; i++)
	{
		free(ChainTable[i]);
	}

    free(ChainTable);

}

//inserting the element, creating a linked list when collision occurs
int InsertChain(	void * hashtable, int elementSize, int elementCountMax,
                            int key, void * element, int (*HashFunc)(int key))
{
	Node** ChainTable=hashtable;
	int index=(*HashFunc)(key);
	
	Node* newNode=malloc(sizeof(Node));
	if(newNode==NULL)
	{
		//printf("memory issue!\n");
		return -1;
	}

	newNode->element=element;
	newNode->key=key;
	newNode->next=ChainTable[index];
	ChainTable[index]=newNode;


	return 0;
}

//finding the the element based on key value
void * SearchChain(void * hashtable, int key, int elementSize, int (*HashFunc)(int key))
{
	Node** ChainTable=hashtable;
    int index=(*HashFunc)(key);
	
	Node* p=ChainTable[index];
	while(p != NULL) {
		if(p->key==key) return p->element;
		else p=p->next;
	}
    
    return NULL;
}
