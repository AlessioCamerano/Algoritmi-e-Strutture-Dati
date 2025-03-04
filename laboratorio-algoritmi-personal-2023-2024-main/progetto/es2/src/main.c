#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "edit_distance.h"

#define MAX_LEN 50

/// @brief  Function to remove punctuation from a word
/// @param word The word to clean
void clean_word(char *word) {
    char cleaned[MAX_LEN] = "";
    int j = 0;

    for (int i = 0; word[i] != '\0'; i++) {
        // Add only alphabetic characters to the cleaned word
        if (isalpha(word[i])) {
            cleaned[j++] = (char)tolower(word[i]);
        }
    }
    cleaned[j] = '\0'; // Null-terminate the cleaned string

    // Copy cleaned string back to the original word
    strcpy(word, cleaned);
}

/// @brief  Function to read a dictionary and a text file, then suggest corrections for each word in the text file
///         by finding the closest word in the dictionary based on edit distance.
/// @param dic_path path of the dictionary file
/// @param text_path path of the text file
void check(const char *dic_path, const char *text_path, int alg) {
    char **dic = NULL;  // Dynamic array to store the dictionary words
    char text[MAX_LEN]; // Buffer to store each word read from the text file
    char word[MAX_LEN]; // Buffer for each word read in the dictionary

    // Open files
    FILE *dic_file = fopen(dic_path, "r");
    FILE *text_file = fopen(text_path, "r");

    if (!dic_file || !text_file) {
        printf("Error opening files.\n");
        return;
    }

    size_t dic_count = 0;         // Counter of dictionary words loaded
    size_t dic_capacity = 1000;   // Starting capacity for dictionary
    dic = malloc(dic_capacity * sizeof(char *));
    if (!dic) {
        printf("Memory allocation failed.\n");
        return;
    }

    // Read the dictionary file line by line
    while (fgets(word, MAX_LEN, dic_file)) {
        word[strcspn(word, "\n")] = 0;  // Remove "\n"

        if (dic_count >= dic_capacity) {
            dic_capacity *= 2;
            dic = realloc(dic, dic_capacity * sizeof(char *));
            if (!dic) {
                printf("Memory reallocation failed.\n");
                return;
            }
        }

        dic[dic_count] = strdup(word); // Copy the word into the dictionary
        if (!dic[dic_count]) {          // Check for strdup failure
            printf("Memory allocation for word failed.\n");
            return;
        }
        dic_count++;
    }

    // Read each word from the text file and find the closest match in the dictionary
    while (fscanf(text_file, "%49s", text) == 1) { // Read words from the text file
        int min = MAX_LEN;                 // Minimum edit distance value, initialized to a large value
        char best[MAX_LEN] = "";           // Store the best match found in the dictionary
        int dist = -1;
        
        clean_word(text);   //Removes nonAhlpa char

        for (size_t i = 0; i < dic_count || dist == 0; i++) {
            // Choose the right algorithm
            if (alg == 1) {
                dist = edit_distance(text, dic[i]);
            } else {
                dist = edit_distance_dy(text, dic[i], memo_table((int)strlen(text), (int)strlen(dic[i])));
            }

            // Update the match if a closer one is found
            if (dist < min) {
                min = dist;
                strcpy(best, dic[i]);
            }
        }

        // Print the word from the text and its closest match from the dictionary
        printf("Word: %s, Suggestion: %s (distance: %d)\n", text, best, min);
    }

    // Free memory allocated for the dictionary
    for (size_t i = 0; i < dic_count; i++) {
        free(dic[i]);
    }
    free(dic);

    // Close both files
    fclose(dic_file);
    fclose(text_file);
}

int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc < 4) {
        printf("Usage: %s <dictionary> <file to correct> <algorithm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int alg = atoi(argv[3]);
    if (alg < 1 || alg > 2) {
        fprintf(stderr, "Error: Algorithm must be 1 (base version) or 2 (dynamic version)\n");
        return EXIT_FAILURE;
    }

    // Run the word correction and time
    time_t start = time(NULL);
    check(argv[1], argv[2], alg);
    time_t end = time(NULL);

    time_t execution_time = end - start;
    printf("Checked and resolved in %ld minutes and %ld seconds.\n", execution_time / 60, execution_time % 60);
    return EXIT_SUCCESS;
}
