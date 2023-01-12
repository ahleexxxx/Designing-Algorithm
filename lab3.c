#include "lab3.h"

/*This function takes an integer indicating the size of the array that will be created.
It will create a centered array provided that the size is odd.
The resulting pointer will point to the central element.
Half of the indices will be negative and other half will be positive. 
If the array cannot be created, the function will return NULL.*/
int * createCenteredArray(int size)
{
    if(size%2==0){      //Error: when the size is even(return NULL)
        printf("the size is not available for creating the proper array in this program");
        return NULL;
    }

    int* array=(int*)malloc((size)*sizeof(int));    //creates the array dynamically with the given size
    if(array==NULL){    //Error: when memory allocation failed(return NULL)
        printf("memory allocation error occured");
        return NULL;
    }

    return (array+size/2);      //adjust the pointer to the center of the array

}


/*This function takes an int array pointer, the size of the array, and the integer representing the index.
It returns the value at the given index.
If the index is invalid for the array, it will return 1.*/
int getAtIndex(int *array, int size, int index)
{
    if((index>(size/2)) || (index<(size/-2))){   //checking the validity of the index given
        return 1;
    }

    return array[index];

}


/*This function takes an in array pointer and the size of the array.
This function will calculate the average of lower half of the array.
It will return the average of non-positive indices including zeroth element.*/
float averageLowerHalf(int *array, int size)
{
    float avg=0.0;
    int sum=0;

    for(int i=0; i>=(size/-2); i--){
        sum+=array[i];
    }

    avg=(float)sum/((size/2)+1);

    return avg;

}


/*This function takes an array pointer and the size of the array.
It will free the memory allocated originally in the createCenteredArray function*/
void freeCenteredArray(int *array, int size)
{
    free(array-(size/2));
}

