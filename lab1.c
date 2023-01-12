#include "lab1.h"

// REQUIRED FUNCTION IMPLEMENTATIONS

/*
avgOdd:
this function takes an integer array, the size of an array, 
and a result pointer in order to store the result of the function.
The function will find odd numbers and find the average of them and store in in the result pointer.
The function will return 0 when error occurs, or the number of elements averaged 
*/

int avgOdd(int *array, int size, float *result)
{
    int sum=0;      //sum variable: store the sum of the elements which are odd
    int count=0;    //count variable: counts the number of elements which are odd


    //The following adds and counts the odd number when an odd number is encountered in the array;  
    for(int i=0; i<size; i++){      
        if(array[i]%2 !=0){
            sum+=array[i];
            count++;
        }
    }

    if(count==0){       //if error occurs(e.g., no odd numbers in array), the function returns 0
        return 0;
    }

    *result=(float)sum/count;       //The average value of odd numbers is stored in result pointer

    return count;       //The function returns the number of elements averaged
}