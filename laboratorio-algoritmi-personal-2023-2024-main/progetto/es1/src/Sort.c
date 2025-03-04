#include "Sort.h"
#include <string.h>
#include <stdlib.h>

/// @brief Merges two subarrays into a sorted array.
/// @param left Pointer to the left subarray.
/// @param right Pointer to the right subarray.
/// @param size Size of each element in the array.
/// @param compar Pointer to the comparison function used to compare two elements.
/// @param result Pointer to the output array where the merged result is stored.
static void merge(void *left, size_t left_size, void *right, size_t right_size, size_t size, int (*compar)(const void*, const void*), void *result) {
    // Converting to `char*` allows byte-level pointer arithmetic, ensuring correct 
    // pointer movement based on the element size (`size`), which is necessary for generic data types.
    char *lptr = (char *)left;
    char *rptr = (char *)right;
    char *resptr = (char *)result;

    size_t i = 0, j = 0, k = 0;

    // Merge elements from left and right subarrays until one is exhausted
    while (i < left_size && j < right_size) {
        if (compar(lptr + i * size, rptr + j * size) <= 0) {
            memcpy(resptr + k * size, lptr + i * size, size);
            i++;
        } else {
            memcpy(resptr + k * size, rptr + j * size, size);
            j++;
        }
        k++;
    }

    // Copy any remaining elements from the left subarray
    while (i < left_size) {
        memcpy(resptr + k * size, lptr + i * size, size);
        i++;
        k++;
    }

    // Copy any remaining elements from the right subarray
    while (j < right_size) {
        memcpy(resptr + k * size, rptr + j * size, size);
        j++;
        k++;
    }
}

/// @brief Recursively applies the Merge Sort algorithm.
/// @param base Pointer to the first element of the array.
/// @param nitems Number of elements in the array.
/// @param size Size of each element in bytes.
/// @param compar Pointer to the comparison function used to compare two elements.
void merge_sort(void *base, size_t nitems, size_t size, int (*compar)(const void*, const void*)) {
    if (nitems < 2) return; // Base case: arrays of size 1 

    size_t mid = nitems / 2;

    char *left = malloc(mid * size);
    char *right = malloc((nitems - mid) * size);

    // Copy left and right halves into separate arrays
    memcpy(left, base, mid * size);
    memcpy(right, (char *)base + mid * size, (nitems - mid) * size);

    // Recursively sort the two halves
    merge_sort(left, mid, size, compar);
    merge_sort(right, nitems - mid, size, compar);

    // Merge the sorted halves back into the original array
    merge(left, mid, right, nitems - mid, size, compar, base);

    // Free temporary arrays
    free(left);
    free(right);
}

/// @brief Partitions the array for Quick Sort.
/// @param base Pointer to the first element of the array.
/// @param low Index of the first element in the partition.
/// @param high Index of the last element in the partition.
/// @param size Size of each element in bytes.
/// @param compar Pointer to the comparison function used to compare two elements.
/// @return The index of the pivot after partitioning.
static size_t partition(void *base, size_t low, size_t high, size_t size, int (*compar)(const void*, const void*)) {
    // Converting to `char*` allows byte-level pointer arithmetic
    char *arr = (char *)base;
    char *pivot = arr + high * size;
    size_t i = low;

    // Iterate over the array, swapping elements to arrange them around the pivot
    for (size_t j = low; j < high; j++) {
        if (compar(arr + j * size, pivot) < 0) {
            if (i != j) {
                char tmp[size];
                memcpy(tmp, arr + i * size, size);
                memcpy(arr + i * size, arr + j * size, size);
                memcpy(arr + j * size, tmp, size);
            }
            i++;
        }
    }

    // Swap the pivot element to its correct position
    char tmp[size];
    memcpy(tmp, arr + i * size, size);
    memcpy(arr + i * size, pivot, size);
    memcpy(arr + high * size, tmp, size);

    return i;
}

/// @brief Recursively applies the Quick Sort algorithm.
/// @param base Pointer to the first element of the array.
/// @param low Index of the first element in the current partition.
/// @param high Index of the last element in the current partition.
/// @param size Size of each element in bytes.
/// @param compar Pointer to the comparison function used to compare two elements.
static void quick_sort_recursive(void *base, size_t low, size_t high, size_t size, int (*compar)(const void*, const void*)) {
    if (low < high) {
        // Partition the array and get the pivot index
        size_t pivot_index = partition(base, low, high, size, compar);

        // Recursively sort elements before and after the pivot
        if (pivot_index > 0) {
        quick_sort_recursive(base, low, pivot_index - 1, size, compar);
        quick_sort_recursive(base, pivot_index + 1, high, size, compar);
        }
    }
}

/// @brief Sorts an array using the Quick Sort algorithm.
/// @param base Pointer to the first element of the array.
/// @param nitems Number of elements in the array.
/// @param size Size of each element in bytes.
/// @param compar Pointer to the comparison function used to compare two elements.
void quick_sort(void *base, size_t nitems, size_t size, int (*compar)(const void*, const void*)) {
    if (nitems > 0) {
        quick_sort_recursive(base, 0, nitems - 1, size, compar);
    }
}


