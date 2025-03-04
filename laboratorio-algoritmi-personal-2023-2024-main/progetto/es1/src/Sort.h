#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/// @brief Sort the array pointed by "base" using the mergesort method
/// @param base the void pointer to the array to be sorted 
/// @param nElements number of elements in "base"
/// @param eSize size in bytes of each element of "base"
/// @param comp  pointer to a comparision function that determine the order of the elements.
///              The function returns a negative int if the first argument is less than the second,
///              returns a positive int if the first argument is greater than the second 
///              and returns zero if they are equals.
void merge_sort (void *base, size_t nElements, size_t eSize, int(*comp)(const void *, const void *));

/// @brief Sort the array pointed by "base" using the quicksort method
/// @param base the void pointer to the array to be sorted 
/// @param nElements number of elements in "base"
/// @param eSize size in bytes of each element of "base"
/// @param comp pointer to a comparision function that determine the order of the elements.
///              The function returns a negative int if the first argument is less than the second,
///              returns a positive int if the first argument is greater than the second 
///              and returns zero if they are equals.
void quick_sort(void* base, size_t nElements, size_t eSize, int(*comp)(const void *, const void *));

#endif
