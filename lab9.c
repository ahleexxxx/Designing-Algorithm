#include "lab9.h"


/*This function takes an array and a key element to search for the element in the array.
After checking whether the array is sorted in descending order, the function processes to binary search. 
The function returns the index of the element in the array on success. 
If the array is not sorted, or the element cannot be found, the function will return -1.*/
int descendingBinarySearch(int *array, int element)
{
    if(!isSortedDescending(array)){
        printf("**the array is not in descending order**\n");
        return -1;
    }

    int minIndex=0;
    int maxIndex=getSize(array)-1;
    int middleIndex;

    while(minIndex <= maxIndex){
        middleIndex = (minIndex+maxIndex)/2;
        
        if(element == array[middleIndex]){
            return middleIndex;
        }
        else if(element > array[middleIndex]){
            maxIndex=middleIndex-1;
        }
        else{
            minIndex=middleIndex+1;
        }
    }

    printf("**cannot find the element from the array**\n");
    return -1;


}

/*This function takes an array, 
and checks if the array is sorted in descending order. 
It will return 1 if the array is sorted or 0 if it's not sorted.*/
int isSortedDescending(int *array)
{
    int maxIndex=getSize(array)-1;
    for(int i=0; i<maxIndex; i++){
        if(array[i]<array[i+1]){
            return 0;
        }
    }

    return 1;

}