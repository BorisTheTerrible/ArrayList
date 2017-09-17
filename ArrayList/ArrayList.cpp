#include <iostream>
#include <cstring>

#include "ArrayList.hpp"

#define NULLPTR 0

template <typename T>
ArrayList<T>::ArrayList(int arraySize, int arrayIncrement)
:
currentSize(0), increment(arrayIncrement), totalSize(arraySize)
{
    //This is okay, current size is set to zero, so even if memory allocation throws it's fine
    //Also, object will not point to anything if it throws anyways
    array = new T[arraySize];
}

//+Throwing is not bad, make sure IF something throws, everything doesn't explode

template <typename T>
ArrayList<T>::ArrayList(const ArrayList & copyList)
:
currentSize(0), increment(copyList.increment), totalSize(copyList.totalSize), array(NULLPTR)
{
    array = new T[totalSize];
    memcpy(array, copyList.array, sizeof(T) * copyList.currentSize);
    
    //this is down here in case memory allocation throws.
    currentSize = copyList.currentSize;
}

template <typename T>
ArrayList<T>::~ArrayList()
{
    delete array;
}

template <typename T>
void ArrayList<T>::checkArray(int elementsToAdd)
{
    if(array == NULLPTR)
    {
        array = new T[totalSize];
    }
    
    if(currentSize + elementsToAdd > totalSize)
    {
        T * oldArray = array;
        
        array = new T[totalSize + increment];
        std::cout << "Increasing size from:" << totalSize << " to: " << totalSize + increment << std::endl;
        totalSize += increment;
        
        memcpy(array, oldArray, sizeof(T) * currentSize);
    }
}

template <typename T>
void ArrayList<T>::addToEnd(T value)
{
    checkArray(1);
    
    array[currentSize] = value;
    currentSize++;
}

template <typename T>
void ArrayList<T>::insert(T value, int index)
{
    checkArray(1);
    
    //Only runs if it isn't trying to place an element last place in the array + 1
    //If it is, go ahead and put it in the index
    if(index < currentSize)
    {
        for(int i = currentSize - 1; i >= index; i--)
        {
            array[i + 1] = array[i];
        }
    }
    
    array[index] = value;
    currentSize++;
}

template <typename T>
void ArrayList<T>::removeAt(int index)
{
    if(index < currentSize - 1)
    {
        for(int i = index; i <= currentSize - 1; i++)
        {
            array[i] = array[i + 1];
        }
    }
    
    currentSize--;
}

template <typename T>
void ArrayList<T>::removeAll(T value)
{
    for(int i = 0; i < currentSize; i++)
    {
        if(array[i] == value)
        {
            removeAt(i);
            
            //Goes back one, in case a value we wanted to remove was placed in the removed location
            i--;
        }
    }
}

template <typename T>
int ArrayList<T>::getSize()
{
    return currentSize;
}

template <typename T>
void ArrayList<T>::printArray()
{
    for(int i = 0; i < currentSize; i++)
    {
        std::cout << "Index: " << i << " Value: " << array[i] << std::endl;
    }
}