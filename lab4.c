#include "lab4.h"

/*This function creates an int array and stores the size before the array.
It takes a size_t type to represent the size of the array.
The function will return the pointer if the array is successfully created or NULL on failure */
int * createIntArray(size_t size)
{
    int* array=malloc(size*sizeof(int)+sizeof(size_t)); //memory allocation for int array
    if (array==NULL){
        printf("memory allocation error occured\n");
        return NULL;    //return NULL for failure
    }

    ((size_t*)array)[0]=size;       //casting
    array=(int*)((size_t*)array+1); //casting
    return array;
}


/*This function takes an int array pointer.
It returns the size as size_t which is stored before the array*/
size_t getSize(int *array)
{
    return *((size_t*)array-1);
}


/*This function takes an in array pointer and print out the elements in the array.
The elements will be printed on one line, and a newline will follow*/
void printArray(int *array)
{
    for(size_t i=0; i<getSize(array); i++){
        printf("%d ", array[i]);
    }
    printf("\n");

}


/*This function takes an int array pointer and
returns the sum of the even indices elements in the array*/
int sumEvenIndices(int *array)
{
    int sum=0;
    for(size_t i=0; i<getSize(array); i++){
        if(i%2==0){     //even number
            sum+=array[i];
        }
    }

    return sum;
}


/*This function takes an int array pointer which contains the size of the array as size_t type
It will free the whole memeory allocated from the createIntArray.*/
void freeArray(int *array)
{
    free((size_t*)array-1); 

}
