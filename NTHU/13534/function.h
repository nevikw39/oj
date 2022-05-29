#ifndef FUNCTION_H_
#define FUNCTION_H_
#include <cstdlib>
#include <stddef.h>

// TODO: Implement the sorting algorithm
template < class T >
void mySort(T arr[], int l, int r);


// TODO: Implement the function to read input, process data, and output answers.
void solve();




// The codes below prevent you from using built-in sorting function and from importing C++ containers.
// Nothing needs to be implemented below.
// Do not modify the codes below.

void qsort(void* , std::size_t , std::size_t , void*);

template <class RandomAccessIterator>
void sort (RandomAccessIterator , RandomAccessIterator );

template <class RandomAccessIterator, class Compare>
void sort (RandomAccessIterator , RandomAccessIterator , Compare );

#endif
#ifndef vector
#define vector
#endif
#ifndef list
#define list
#endif
#ifndef forward_list
#define forward_list
#endif
#ifndef deque
#define deque
#endif
#ifndef array
#define array
#endif
#ifndef set
#define set
#endif
#ifndef multiset
#define multiset
#endif
#ifndef map
#define map
#endif
#ifndef multimap
#define multimap
#endif
#ifndef unordered_set
#define unordered_set
#endif
#ifndef unordered_multiset
#define unordered_multiset
#endif
#ifndef unordered_map
#define unordered_map
#endif
#ifndef unordered_multimap
#define unordered_multimap
#endif
#ifndef bitset
#define bitset
#endif
#ifndef valarray
#define valarray
#endif
#ifndef stack
#define stack
#endif
#ifndef queue
#define queue
#endif
#ifndef priority_queue
#define priority_queue
#endif
