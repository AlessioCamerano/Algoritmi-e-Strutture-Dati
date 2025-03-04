#include "edit_distance.h"
#include <stdio.h>
#include <string.h>
#include <limits.h> //INT_MAX
#include <stdlib.h> //malloc

int **memo_table(int len1, int len2){
    //creating memo
    int **memo= (int **)malloc((unsigned int)(len1 + 1) * sizeof(int *));
    for(int i= 0; i <= len1; i++){
        memo[i]= (int *)malloc((unsigned int)(len2 + 1) * sizeof(int));
        for(int j= 0; j <=len2; j++){
            memo[i][j]= -1; //not computed yet
        }
    }
    return memo;
}

int edit_distance_dy(const char *s1, const char *s2, int **memo){
    int len1= (int)strlen(s1);
    int len2= (int)strlen(s2);

    //base cases
    if (len1== 0) return len2;
    if (len2== 0) return len1;

    //if already computed, return it
    if(memo[len1][len2] != -1) return memo[len1][len2];

    //if the first character matches, no op is required
    int no_op= INT_MAX;
    if (s1[0]==s2[0]) no_op= edit_distance_dy(s1 + 1, s2 + 1, memo);

    // Calculate the edit distance for deletion and insertion cases
    int del = 1 + edit_distance_dy(s1, s2 + 1, memo);      // Deletion from s2
    int ins = 1 + edit_distance_dy(s1 + 1, s2, memo);      // Insertion into s1

    //save the minimum value into memo
    memo[len1][len2] = (no_op < del) ? (no_op < ins ? no_op : ins) : (del < ins ? del : ins);

    return memo[len1][len2];
}

int edit_distance(const char *s1, const char *s2){
    // Base case: if the first string is empty, we need to insert all characters of s2
    if (*s1 =='\0'){
        return (int)strlen(s2);
    }

    // Base case: if the second string is empty, we need to insert all characters of s1
    if (*s2 == '\0') {
        return (int)strlen(s1);
    }

    int no_op= INT_MAX;
    
    // If the first characters of both strings match, no operation is required
    if(*s1 == *s2){
        no_op= edit_distance(s1 + 1, s2 + 1);
    }

    int canc= 1 + edit_distance(s1, s2 + 1); //Deletion from s2
    int ins= 1 + edit_distance(s1 + 1, s2); //insertion into s1

    //Return the minimum
    if (no_op <= canc && no_op <= ins){
        return no_op;
    } else if(canc <= ins){
        return canc;
    } else {
        return ins;
    }
}
