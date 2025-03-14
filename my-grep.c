////////////////////////////////////////////////////////////////////
// FILE WRITTEN BY JUUSO KÄYHKÖ (493675)                          //
//                                                                //
// AI TOOLS WERE USED FOR ALGORHITM STRUCTURE GENERATION,         //
// BUT NOT FOR WRITING THE ACTUALY CODE.                          //
// FILE: my-grep.c                                                 //
////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // CHECKS IF BOTH ARGUMENTS EXIST
    if (argc < 2) {
        fprintf(stderr, "my-grep: searchterm [file ...]\n");
        exit(1);
    }

    // DEFAULT INPUT IS stdin
    FILE *input = stdin;
    char *line = NULL;

    // READ FROM TERMINAL IF NO INPUT FILE IS GIVEN
    if (argc == 2) {
        // STORES MATCHED LINES
        char *result = malloc(1);
        size_t result_len = 0;

        char *line = NULL;
        size_t len = 0;

        while (getline(&line, &len, stdin) != -1) {
            if (strstr(line, argv[1])) {
                size_t line_len = strlen(line);
                // ADD LINE IF NOT THE LAST LINE
                if (line_len > 0 && line[line_len - 1] != '\n') line_len++;

                // REALLOCATE FOR MORE MEMORY
                result = realloc(result, result_len + line_len + 1); // +1 for null-terminator

                // COPY LINE
                memcpy(result + result_len, line, line_len);
                result_len += line_len;

                // TERMINATE ON NULL
                result[result_len] = '\0';
            }
        }

        free(line);
        printf("\n");
        printf("%s", result);
    } else {
        // LOOP THROUGH ALL GIVEN FILES
        for (size_t i = 0; i < argc - 2; i++) {
            // OPEN FILE
            FILE *file = fopen(argv[i+2], "r");
            if (!file) {
                fprintf(stderr, "my-grep: cannot open file\n");
                exit(1);
            }

            // PRINT LINES THAT MATCH ARGUMENT
            size_t len = 0;
            while (getline(&line, &len, file) != -1) {
                if (strstr(line, argv[1])) {

                    // PRINT \n AT THE END END OF FILE
                    size_t length = strlen(line);
                    if (length > 0 && line[length - 1] == '\n') {
                        printf("%s", line);
                    } else {
                        printf("%s\n", line);
                    }
                }
            }
        }
    }

    // CLOSE FILE AND FREE MEMORY
    if (input != stdin) fclose(input);
    if (input != stdin) free(line);
    

    return 0;
}
