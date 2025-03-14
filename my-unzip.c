////////////////////////////////////////////////////////////////////
// FILE WRITTEN BY JUUSO KÄYHKÖ (493675)                          //
//                                                                //
// AI TOOLS WERE USED FOR ALGORHITM STRUCTURE GENERATION,         //
// BUT NOT FOR WRITING THE ACTUALY CODE.                          //
// FILE: my-unzip.c                                               //
////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // CHECK FOR NECESSARY ARGUMENTS
    if (argc < 2) {
        fprintf(stderr, "my-unzip: file1 [file2 ...]\n");
        exit(1);
    }

    // LOOP EACH FILE
    for (size_t i = 0; i < argc - 1; i++) {
        // OPEN FILE IN BINARY MODE (rb)
        FILE *file = fopen(argv[i+1], "rb");
        if (!file) {
            fprintf(stderr, "my-unzip: cannot open file\n");
            exit(1);
        }

        unsigned int count;
        char ch;

        // READ 4 BYTES (COUNT) AND 1 BYTE (CHARACTER) AT A TIME
        while (fread(&count, sizeof(unsigned int), 1, file) == 1 && fread(&ch, sizeof(char), 1, file) == 1) {
            // PRINT CHARACTER 'count' TIMES
            for (unsigned int j = 0; j < count; j++) {
                putchar(ch);
            }
        }

        fclose(file);
    }

    return 0;
}
