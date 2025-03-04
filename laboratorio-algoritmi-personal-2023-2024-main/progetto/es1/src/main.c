#include "Record.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 4) {
        //Correct usage format
        fprintf(stderr, "Usage: %s <input_file> <field> <algorithm>\n", argv[0]);
        return EXIT_FAILURE;
    }
    //Open the input file reading
    FILE *infile = fopen(argv[1], "r");
    if (!infile) {
        perror("Failed to open input file");
        return EXIT_FAILURE;
    }

    char *sorted= "/mnt/c/users/camer/laboratorio-algoritmi-personal-2023-2024/progetto/es1/data/sorted.csv";

    //Open the output file writing
    FILE *outfile = fopen(sorted, "w");
    if (!outfile) {
        perror("Failed to open output file");
        fclose(infile);
        return EXIT_FAILURE;
    }

    //Convert the third and the fourth argument to a size_t
    int field = atoi(argv[2]);
    if (field < 1 || field > 3) {
        fprintf(stderr, "Error: Field must be 1, 2, or 3\n");
        fclose(infile);
        fclose(outfile);
        return EXIT_FAILURE;
    }
    
    int algo = atoi(argv[3]);
    if (algo < 1 || algo > 2) {
        fprintf(stderr, "Error: Algorithm must be 1 (MergeSort) or 2 (QuickSort)\n");
        fclose(infile);
        fclose(outfile);
        return EXIT_FAILURE;
    }

    //time
    time_t start= time(NULL);
    sort_records(infile, outfile, (size_t)field, (size_t)algo);
    time_t end= time(NULL);

    time_t execution_time= end - start;
    printf("Sorted in %ld minutes and %ld seconds\n" , execution_time / 60 , execution_time % 60);


    //Close both files after sorting is done
    fclose(infile);
    fclose(outfile);

    return EXIT_SUCCESS;
}
