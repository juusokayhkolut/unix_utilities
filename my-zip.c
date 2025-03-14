////////////////////////////////////////////////////////////////////
// FILE WRITTEN BY JUUSO KÄYHKÖ (493675)                          //
//                                                                //
// AI TOOLS WERE USED FOR ALGORHITM STRUCTURE GENERATION,         //
// BUT NOT FOR WRITING THE ACTUALY CODE.                          //
// FILE: my-zip.c                                                 //
////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // CHECK FOR NECESSARY ARGUMENTS
    if (argc < 2) {
        fprintf(stderr, "my-zip: file1 [file2 ...]\n");
        exit(1);
    }

    // LOOP EACH FILE
    for (size_t i = 0; i < argc - 1; i++) {
        int currentChar, prevChar = EOF;
        unsigned int count = 0;

        // OPEN FILE
        FILE *file = fopen(argv[i+1], "r");
        if (!file) {
            fprintf(stderr, "my-zup: cannot open file\n");
            exit(1);
        }

        // LOOP OVER EACH CHARACTER
        while ((currentChar = fgetc(file)) != EOF) {
            // IF CHARACTER IS THE SAME AS PREVIOUS, ADD TO COUNT
            if (currentChar == prevChar) {
                count++;
            } /* ELSE, WRITE TO TERMINAL AND START COUNTRING NEW CHARACTER */ else {
                if (count > 0) {
                    fwrite(&count, sizeof(unsigned ), 1, stdout);
                    fwrite(&prevChar, sizeof(char), 1, stdout);
                }
                count = 1;
                prevChar = currentChar;
            }
        }

        // WRITE LAST CHARACTER
        if (count > 0) {
            fwrite(&count, sizeof(unsigned int), 1, stdout);
            fwrite(&prevChar, sizeof(char), 1, stdout);
        }
    }
    

    return 0;
}
