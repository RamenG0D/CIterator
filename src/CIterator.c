#include "CIterator.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Iterator {
    void* data;
    int index;
} Iterator;

// used to create a new iterator
Iterator* IteratorNew(void* data) {
    Iterator* iter = malloc(sizeof(Iterator));
    iter->data = data; // set the data to iterate over
    iter->index = 0; // start at the beginning of the data arry
    return iter;
}

// must be called to free the iterator and its text buffer
void IteratorDestroy(Iterator* iter) {
    free(iter->data);
    free(iter);
}

// Gets next char and increments index
void* IteratorGetNext(Iterator* iter) {
    if(iter->index > (int)strlen(iter->data) || iter->index < 0) {
        printf("ERROR: Iterator index is greater than the length of the text, cant get next char\n");
        exit(1);
    }

    void* tmp = &iter->data[iter->index]; 
    
    iter->index++;

    return tmp;
}

// Gets next char without incrementing index
void* IteratorPeekNext(Iterator* iter) {
    if(iter->index >= (int)strlen(iter->data) || iter->index < 0) {
        printf("ERROR: Iterator index is greater than the length of the text, cant peek any further\n");
        exit(1);
    }
    return &iter->data[iter->index + 1];
}

// Just gets the char at the current iter index
void* IteratorGetCurrent(Iterator* iter) {
    if(iter->index >= (int)strlen(iter->data) || iter->index < 0) {
        printf("ERROR: Iterator index is greater than the length of the text, cant get current char\n");
        exit(1);
    }
    return &iter->data[iter->index];
}

void IteratorBack(Iterator* iter) {
    if(iter->index > 0) iter->index--;
    else {
        printf("ERROR: Iterator index is already at 0, cant go back any further\n");
        exit(1);
    }
}
