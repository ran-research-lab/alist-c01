// class AList:
// An declaration of the ADT List using array
// Code from the OpenDSA book

#ifndef CATCHEXAMPLE_ALIST_H
#define CATCHEXAMPLE_ALIST_H
#include "List.h"
#include <stdexcept>
#include <string>


class AList : public List {
    ListItemType* listArray;            // Array holding list elements
    static const int DEFAULT_SIZE = 10; // Default size
    int maxSize;                        // Maximum size of list
    int listSize;                       // Current # of list items
    int curr;                           // Position of current element

public:
    // Constructors
    // Create a new list object with maximum size "size"
    AList(int size = DEFAULT_SIZE) : listSize(0), curr(0) {
        maxSize = size;
        listArray = new ListItemType[size];         // Create listArray
    }

    ~AList();     // destructor to remove array

    // Reinitialize the list
    void clear();  // Simply reinitialize values

    // Insert "it" at current position
    bool insert(const ListItemType& it) ;

    // Append "it" to list
    bool append(const ListItemType& it);

    // Remove and return the current element
    ListItemType remove();

    void moveToStart();       // Set to front
    void moveToEnd();         // Set at end
    void prev();              // Move left
    void next();              // Move right
    int length() const;       // Return list size
    int currPos() const;      // Return current position

    // Set current list position to "pos"
    bool moveToPos(int pos);

    // Return true if current position is at end of the list
    bool isAtEnd() const;

    // Return the current element
    ListItemType getValue() const;

    // Check if the list is empty
    bool isEmpty() const;

    string to_string() const;
};


#endif //CATCHEXAMPLE_ALIST_H
