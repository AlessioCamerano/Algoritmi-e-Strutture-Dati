#ifndef RECORD_H
#define RECORD_H

#include <stdio.h>

/// @brief Sort the records contained in a CSV file.
///     This function reads the records from the `infile`, sorts them based on the specified field,
///     and uses the indicated algorithm to perform the sorting. The sorted records are written
///     to the `outfile`.
///
/// @param infile Pointer to the input file containing the records.
/// @param outfile Pointer to the output file where the sorted records will be saved.
/// @param field The field to use for sorting (1: field1, 2: field2, 3: field3).
/// @param algo The sorting algorithm to use (1: Merge Sort, 2: Quick Sort).
void sort_records(FILE *infile, FILE *outfile, size_t field, size_t algo);

#endif