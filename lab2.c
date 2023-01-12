#include "lab2.h"

/*This functions takes a file pointer and the pointer to store the size of an array.
An array will be dynamically created through malloc and store the integers in the array from the file opened
It will return the pointer to the array unless an error occurs*/
int * createIntArrayFromFile(FILE *file, int *size)
{
    fscanf(file, "%d", size);
    if(size==0){        //error handling
        return NULL;
    }

    int * array=(int*)malloc((*size)*sizeof(int));      //an array created
    if(array==NULL){    //error handling
        return NULL;
    }

    for(int i=0; i<*size; i++){     //reads the data from the file and store it in the array
        fscanf(file, "%d", (array+i));
    }

    return array;

}

/*This function takes and array pointer, size of the array, 
double pointer to store the address of the query integer, and an integer that the user trying to find.
It will go through the array to find the query integer and set the pointer to the address of the integer found*/
int firstAddressOf(int *array, int size, int **result, int element)
{
    int i;
    int isFound=1;      //isFound variable will check whether the element is found or not. 1 for NotFound, 0 for Found
    for(i=0; i<size; i++){          //seeking for the element
        if(element == array[i]){    
            *result=(array+i);
            isFound=0;
        }
    }

    if(isFound==1){
        return 1;
    }

    return 0;

}

/*This function takes an array pointer and frees the allocated memeory*/
void freeArray(int *array)
{
    free(array);
}


