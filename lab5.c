#include "lab5.h"

//this function creates an array of user given sizes
void * createArray(size_t elementSize, int numElements)
{
    void* array=malloc(numElements*elementSize+sizeof(int));  //malloc
    if(array==NULL){        //error handling
        printf("memory allocation Error\n");
        return NULL;
    }
    ((int*)array)[0]=numElements;
    array=(void*)((int*)array+1);
    return array;
}

//function find the size of the car array
int getSize(void *array)
{
    return *((int*)array-1);

}


//this function gets the vin of the car
int getVin(Car *car)
{  
    return car->vin;
}

//this function finds the miles of car 
float getMilesDriven(Car *car)
{
    return car->milesDriven;
}

//this function finds the number of accidents from the car
int getNumberOfAccidents(Car *car)
{
    return car->numberOfAccidents;
}


//this functions add miles for the car
void updateMilesDriven(Car *car, float milesToAdd)//single sturct
{
    (car->milesDriven)=(car->milesDriven)+milesToAdd;
}

//this funcion increments the number of accidents by 1 
void incrementNumberOfAccidents(Car *car)   //single car struct
{
    (car->numberOfAccidents)++;
}


//this function finds the car by vin
Car * getCarByVIN(Car *array, int VIN)
{
    for(int i=0; i<getSize(array); i++){
        if(VIN==getVin(&array[i])){
            return &array[i];
        }
    }
    return NULL;
}

//this functions finds the car with least Accidents
Car * getWithLeastAccidents(Car *array) 
{
    Car* least=&array[0];//
    for(int i=1; i<getSize(array); i++){//
        if((array[i].numberOfAccidents)<(least->numberOfAccidents)){    //value compare
            least=&array[i];
        }
    }
    return least;
}

//this function prints the car struct arrays
void printCars(Car *array)
{
    for(int i=0; i<getSize(array); i++){
        printf("Car array element %d: %d %.3lf %d\n", i, array[i].vin, array[i].milesDriven, array[i].numberOfAccidents);
    }
}

//this functions frees the array
void freeArray(void *array)
{
    free((int*)array-1);
}