#include "objPosArrayList.h"

#include "objPosArrayList.h"
#include <iostream>

// Default constructor for objPosArrayList.
// Initializes an empty array list with a fixed maximum capacity.
objPosArrayList::objPosArrayList()
{
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;
    aList = new objPos[ARRAY_MAX_CAP];
}

// Destructor for objPosArrayList.
// Cleans up dynamically allocated memory to prevent memory leaks.
objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

// Returns the current size of the array list
int objPosArrayList::getSize() const
{
    return listSize;
}

// Inserts an objPos object at the head (beginning) of the array list
// Shifts all elements to the right to make space for the new object
void objPosArrayList::insertHead(objPos thisPos)
{
    if (listSize >= arrayCapacity){
        return;
    }

    for(int i = listSize; i > 0; i--){
        aList[i] = aList[i - 1];
    }
    aList[0] = thisPos;
    listSize++; 
}

// Inserts an objPos object at the tail (end) of the array list.
void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize >= arrayCapacity) {
        return;
    }

    aList[listSize] = thisPos; // Inserts the new object at the tail of the list.
    listSize++; // Increments the size of the list.
}

// Removes the head (first) element from the array list
// Shifts all subsequent elements to the left to fill the gap
void objPosArrayList::removeHead()
{
    if(listSize == 0) {
        return;
    }

    for(int i = 0; i < listSize - 1; i++){
        aList[i] = aList[i + 1];
    }

    listSize--;
}

// Removes the tail (last) element from the array list 
void objPosArrayList::removeTail()
{
    if(listSize == 0) {
        return;
    }

    listSize--;   
}

// Returns the head (first) element of the array list
objPos objPosArrayList::getHeadElement() const
{
        return aList[0];
}

// Returns the tail (last) element of the array list
objPos objPosArrayList::getTailElement() const
{
        return aList[listSize - 1];
}

// Returns the element at a specific index in the array list.
objPos objPosArrayList::getElement(int index) const
{
    if(index >=0 || index < listSize){ // Ensures the index is within bounds.
        return aList[index];
    }
    
}