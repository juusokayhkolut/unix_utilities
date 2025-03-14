////////////////////////////////////////////////////////////////////
// FILE WRITTEN BY JUUSO KÄYHKÖ (493675)                          //
//                                                                //
// AI TOOLS WERE USED FOR ALGORHITM STRUCTURE GENERATION,         //
// BUT NOT FOR WRITING THE ACTUALY CODE.                          //
// FILE: my-grep.c                                                 //
////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // ONLY RUNS IF AT LEAST ONE INPUT FILE WAS GIVEN
    if (argc >= 2) {
        // LOOP EACH GIVEN FILE
        for (size_t i = 1; i < argc; i++) {
            // OPEN FILE
            FILE *file = fopen(argv[i], "r");
            if (!file) {
                fprintf(stderr, "my-cat: cannot open file.\n");

                // CONTINUES TO LOOP UNTIL THE END OF THE LIST OR EXITS 1
                if (i < argc) {
                    continue;
                } else {
                    exit(1);
                }
            }

            // PRINT LINES
            int line;
            while ((line = fgetc(file)) != EOF) {
                fprintf(stdout, "%c", line);
            }

            // CLOSE FILE
            fclose(file);
        }
    }

    return 0;
}
