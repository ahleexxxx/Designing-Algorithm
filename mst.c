//#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "mst.h"



// These are stubs.  That is, you need to implement these functions.
#include <stdio.h>
#include <limits.h>


typedef struct Element{
    int vertex;
    float key;
    int *parent;
} Element;

typedef struct PriorityQueue{
	Element *heap;
	int heapSize;
}PriorityQueue;

void heapify(PriorityQueue *PQ, int index)
{
    int left=index*2;
    int right=index*2+1;
    int smallest;
    Element temp;
    if(left <= (PQ->heapSize) && PQ->heap[left].key < PQ->heap[index].key){
        smallest=left;
    }
    else{
        smallest=index;
    }
    if(right <= (PQ->heapSize) && PQ->heap[right].key < PQ->heap[smallest].key){
        smallest=right;
    }

    if(smallest != index){
        temp=PQ->heap[index];
        PQ->heap[index]=PQ->heap[smallest];
        PQ->heap[smallest]=temp;
    }
}

Element extractMin(PriorityQueue* PQ){
    Element min;
    min=PQ->heap[1];
    PQ->heap[1]=PQ->heap[PQ->heapSize];
    (PQ->heapSize)=(PQ->heapSize)-1;
    heapify(PQ, 1);
    return min;
}

void buildHeap(PriorityQueue *PQ)
{
    for(int i= PQ->heapSize/2; i>0; i--){
        heapify(PQ, i);
    }
}


void heapChangeKey(PriorityQueue *PQ, int v, float w)
{
    if(w <= PQ->heap[v].key){
        PQ->heap[v].key=w;
        heapify(PQ, v);
    }
    else{
        PQ->heap[v].key=w;
        while(v>1 && PQ->heap[v/2].key < PQ->heap[v].key){
            float temp=PQ->heap[v].key;
            PQ->heap[v].key=PQ->heap[v/2].key;
            PQ->heap[v/2].key=temp;
            
        }
    }
}

int indexOFv(PriorityQueue *PQ, int v)
{
    for(int i=1; i<=PQ->heapSize; i++){
        if(PQ->heap[i].vertex==v){
            return i;
        }
    }
    return -1;

}

void MST_Prim(Vertex vertices[], int startNumber, int countVertices)
{
    PriorityQueue PQ;
    PQ.heap=malloc(sizeof(int)*(countVertices+1));
    PQ.heapSize=countVertices;

    for(int u=1; u<=countVertices; u++){
        PQ.heap[u].vertex=u;
        PQ.heap[u].key=INT_MAX;
        PQ.heap[u].parent=NULL;
    }


    PQ.heap[startNumber].vertex=startNumber;
    PQ.heap[startNumber].key=0;
    PQ.heap[startNumber].parent=NULL;
    buildHeap(&PQ);


    printf("\nMST:\n");
    while(PQ.heapSize !=0 ){
        Element uExtract=extractMin(&PQ);
        int u=uExtract.vertex;
        
        for(PAdjacency p=vertices[u-1].list; p !=NULL; p=p->next){
            int v;
            if(p->pEdge->from != u){
                v=p->pEdge->from;
            }
            else{
                v=p->pEdge->to;
            }
            
            int vertex=indexOFv(&PQ, v);
            if(vertex !=-1 && p->pEdge->weight < PQ.heap[vertex].key){
                PQ.heap[vertex].parent=malloc(sizeof(int));
                *(PQ.heap[vertex].parent)=u;
                heapChangeKey(&PQ, vertex, p->pEdge->weight);
            }
        }
        buildHeap(&PQ);
        if(uExtract.parent !=NULL){
            printf("%d->%d, %.2f\n", *(uExtract.parent), uExtract.vertex, uExtract.key);
        }
        
        
    }

}
