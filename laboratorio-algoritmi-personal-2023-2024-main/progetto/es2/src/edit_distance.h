#ifndef EDIT_DISTANCE_H
#define EDIT_DISTANCE_H

/// @param Function Recursive version of edit distance.
///                 It calculates the minimum edit distance between two strings using only
///                 insertion and deletion operations.
int edit_distance(const char *s1, const char *s2);

/// @param Function Dynamic programming version of edit distance.
///                 It calculates the minimum edit distance between two strings using dynamic
///                 programming with memorization to store intermediate results.
int edit_distance_dy(const char *s1, const char *s, int **memo);

///@brief Creates the memo table. Each cell memo[i][j] in the matrix represents 
///       the minimum transformation cost between the first i characters of s1 and the first j characters of s2.
int **memo_table(int len1, int len2);

#endif // EDIT_DISTANCE_H