// Implementation of the ADT List using array
// Code from the OpenDSA book

#include "AList.h"
#include <string>
using namespace std;



AList::~AList() { delete [] listArray; }

// Reinitialize the list
void AList::clear() { listSize = curr = 0; }

// Insert "it" at current position
bool AList::insert(const ListItemType& it) {
    if (listSize >= maxSize) return false;
    // Shift elements right to make room
    for (int i = listSize; i > curr; i--)
        listArray[i] = listArray[i-1];
    listArray[curr] = it;
    listSize++;
    return true;
}

// Append "it" to list
bool AList::append(const ListItemType& it) {
    if (listSize >= maxSize) return false;
    listArray[listSize++] = it;
    return true;
}

// Remove and return the current element
ListItemType AList::remove() {
    if ((curr < 0) || (curr >= listSize)) // No current element
        throw std::out_of_range("remove() in AList has current of " + std::to_string(curr) + " and size of "
                                + std::to_string(listSize) + " that is not a a valid element");
    ListItemType it = listArray[curr];     // Copy the element
    for(int i = curr; i < listSize-1; i++) // Shift them down
        listArray[i] = listArray[i+1];
    listSize--;                            // Decrement size
    return it;
}

void AList::moveToStart() { curr = 0; }       // Set to front
void AList::moveToEnd() { curr = listSize; }  // Set at end
void AList::prev() { if (curr != 0) curr--; } // Move left
void AList::next() { if (curr < listSize) curr++; } // Move right
int AList::length() const { return listSize; }       // Return list size
int AList::currPos() const { return curr; }          // Return current position

// Set current list position to "pos"
bool AList::moveToPos(int pos) {
    if ((pos < 0) || (pos > listSize)) return false;
    curr = pos;
    return true;
}

// Return true if current position is at end of the list
bool AList::isAtEnd() const { return curr == listSize; }

// Return the current element
ListItemType AList::getValue() const {
    if ((curr < 0) || (curr >= listSize)) // No current element
        throw std::out_of_range("getvalue() in AList has current of " + std::to_string(curr) +  + " and size of "
                                + std::to_string(listSize) + " that is not a a valid element");
    return listArray[curr];
}

// Check if the list is empty
bool AList::isEmpty() const { return listSize == 0; }

string AList::to_string() const {
    string res = "<";
    int i;
    for (i = 0; i < listSize; i++) {
        if ( i == curr) res += "|";
        res += std::to_string(listArray[i]);
        if (i != listSize -1 && curr != i + 1)  res += ",";
    }
    if ( i == curr) res += "|";
    res += ">";
    return res;

    return "";
}