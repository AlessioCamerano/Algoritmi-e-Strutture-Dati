#include "Sort.h"
#include "Record.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Structure representing a record.
///     Each record contains an integer ID, a string (field1), an integer (field2),
///     and a floating point value (field3).
typedef struct {
    int id;
    char field1[100];
    int field2;
    float field3;
} Record;

/// @brief Comparison function to sort records based on `field1`.
/// @param a Pointer to the first record.
/// @param b Pointer to the second record.
/// @return A negative value if the first record's `field1` is smaller,
///         zero if they are equal, or a positive value if it is larger.
static int comp_field1(const void *a, const void *b) {
    return strcmp(((Record*)a)->field1, ((Record*)b)->field1);
}

/// @brief Comparison function to sort records based on `field2`.
/// @param a Pointer to the first record.
/// @param b Pointer to the second record.
/// @return A negative value if the first record's `field2` is smaller,
///         zero if they are equal, or a positive value if it is larger.
static int comp_field2(const void *a, const void *b) {
    return ((Record*)a)->field2 - ((Record*)b)->field2;
}

/// @brief Comparison function to sort records based on `field3`.
/// @param a Pointer to the first record.
/// @param b Pointer to the second record.
/// @return A negative value if the first record's `field3` is smaller,
///         zero if they are equal, or a positive value if it is larger.
static int comp_field3(const void *a, const void *b) {
    if (((Record*)a)->field3 < ((Record*)b)->field3) return -1;
    if (((Record*)a)->field3 > ((Record*)b)->field3) return 1;
    return 0;
}

void sort_records(FILE *infile, FILE *outfile, size_t field, size_t algo) {
    // Allocate a dynamic array for up to 20 million records
    Record *records = malloc(20000000 * sizeof(Record));
    size_t count = 0;

    // Read records from the input file until EOF, storing them in the 'records' array
    while (fscanf(infile, "%d,%[^,],%d,%f\n", &records[count].id, records[count].field1, &records[count].field2, &records[count].field3) != EOF) {
        count++;
    }

    // Select the appropriate comparison function based on the sorting field
    int (*compar)(const void*, const void*);
    switch (field) {
        case 1: compar = comp_field1; break;
        case 2: compar = comp_field2; break;
        case 3: compar = comp_field3; break; 
        default: return; // Invalid field
    }

    // Perform sorting using the selected algorithm
    if (algo == 1) {
        merge_sort(records, count, sizeof(Record), compar); 
    } else {
        quick_sort(records, count, sizeof(Record), compar); 
    }

    // Write the sorted records to the output file in CSV format
    for (size_t i = 0; i < count; i++) {
        fprintf(outfile, "%d,%s,%d,%f\n", records[i].id, records[i].field1, records[i].field2, records[i].field3);
    }

    // Free the memory allocated for the array of records
    free(records);
}