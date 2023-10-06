#ifndef ITERATOR_H
#define ITERATOR_H

/// @brief An iterator for iterating over the contents of a string / (file)
typedef struct Iterator Iterator;

/// @brief creates a new iterator from the given text
/// @param text the text to iterate over
/// @return returns a new iterator
Iterator* IteratorNew(void* data, int length);

/// @brief destroys the given iterator (MUST BE CALLED TO FREE THE ITERATOR)
/// @param iter the iterator to destroy
void IteratorDestroy(Iterator* iter);

/// @brief gets the current char without changing the index
/// @param iter the iterator
/// @return returns the char at the iters current index
void* IteratorGetCurrent(Iterator* iter);

/// @brief gets the next char in the iterator and increments the index
/// @param iter the iterator
/// @return returns the next char in the iterator
void* IteratorGetNext(Iterator* iter);

/// @brief gets the next char in the iterator without incrementing the index
/// @param iter the iterator
/// @return returns the next char in the iterator
void* IteratorPeekNext(Iterator* iter);

/// @brief decrements the iterator index
/// @param iter the iterator
void IteratorBack(Iterator* iter);

/// @brief gets the current index of the iterator
/// @param iter the iterator
/// @return returns the current index of the iterator
int IteratorGetIndex(Iterator* iter);

/// @brief checks if the iterator is done iterating
/// @param iter the iterator
/// @return returns 1 if the iterator is done iterating, 0 otherwise
int IteratorIsDone(Iterator* iter);

#define NewIteratorType(type) \
    typedef struct Iterator Iterator_##type; \
    Iterator_##type* Iterator_##type##_New(type* data, size_t length) { \
        return (Iterator_##type*)IteratorNew(data, (int)length); \
    } \
    void Iterator_##type##_Destroy(Iterator_##type* iter) { \
        IteratorDestroy(iter); \
    } \
    type Iterator_##type##_GetNext(Iterator_##type* iter) { \
        return *(type*)IteratorGetNext(iter); \
    } \
    type Iterator_##type##_PeekNext(Iterator_##type* iter) { \
        return *(type*)IteratorPeekNext(iter); \
    } \
    type Iterator_##type##_GetCurrent(Iterator_##type* iter) { \
        return *(type*)IteratorGetCurrent(iter); \
    } \
    void Iterator_##type##_Back(Iterator_##type* iter) { \
        IteratorBack(iter); \
    }

#endif // ITERATOR_H