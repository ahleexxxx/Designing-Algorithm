#include <cs3050.h>

void bubblesort(void *array, 
				size_t nitems, 
				size_t size, 
				int (*CompareFunc)(const void *, const void*))
{
	for (int i=0;i<nitems;i++)
	{
		for (int j=0;j<nitems-1;j++)
		{
			void * item1 = array + j*size;
			void * item2 = array + (j+1)*size;
			if (CompareFunc(item1,item2)>0)
			{
				Swap(item1,item2,size);
			}
		}
	}
}

void insertionsort(void *array, 
				size_t nitems, 
				size_t size, 
				int (*CompareFunc)(const void *, const void*))
{
    for(int i=1; i<nitems; i++){
        void* key=array+i*size;
    
        int j=i-1;
        void* item=array+j*size;
        while(j>=0&& CompareFunc(key, item)<0){
            Swap(item, key, size);
            key=array+j*size;
            j--;
            item=array+j*size;
            
        }
    }

}


void heapify(void* array, int index, size_t nitems, size_t size, int (*CompareFunc)(const void *, const void*))
{
	int L=2*index;
	int R=2*index+1;
	int updatedIndex;

	void* key=array+index*size;
	void* left=array+L*size;
	void* right=array+R*size;

	void* largest;

	if(L<=nitems && CompareFunc(left, key)>0){
		largest=left;
		updatedIndex=L;
	}
	else{
		largest=key;
		updatedIndex=index;
	}

	if(R<=nitems && CompareFunc(right, largest)>0){
		largest=right;
		updatedIndex=R;
	}

	if(CompareFunc(largest, key)!=0){
		Swap(key, largest, size);
		heapify(array, updatedIndex, nitems, size, CompareFunc);
	}

}

void buildHeap(void* array, size_t nitems, size_t size, int (*CompareFunc)(const void *, const void*))
{
	
	int heapSize=nitems;
	for(int i=heapSize/2; i>=1; i--){
		heapify(array, i, nitems, size, CompareFunc);
	}

}

void heapsort(void *array, 
				size_t nitems, 
				size_t size, 
				int (*CompareFunc)(const void *, const void*))
{
	void* ary=array-size;
	//
	buildHeap(ary, nitems, size, CompareFunc);
	
	int heapSize=nitems;
	for(int i=heapSize; i>1; i--){
		void* first=ary+1*size;
		void* last=ary+i*size;
		Swap(first, last, size);
		heapify(ary, 1, i-1, size, CompareFunc);
	}
	
}




