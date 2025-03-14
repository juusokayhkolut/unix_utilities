# Documentation for unix utilities

## Files
- `my-cat.c`: Includes logic for reading files and prints it content
- `my-grep.c`: Includes logic for finding a word in files and prints matching lines
- `my-zip`: Includes logic for zipping stdin or files contents using 4-byte integer in binary
- `my-unzip`: Includes logic for unzipping 4-byte integer binary that was zipping using `my-zip`

### my-cat.c
- `main`
    - Checks for appropriate arguments
    - Opens input files and prints to console
    - Gives error if input file cannot be opened

### my-grep.c
- `main`
    - Checks for appropriate arguments
    - If no file was given:
        - Prompts user to write in the console (stdin) with dynamic memory allocation
        - Prints all matching content from stdin to console
    - Search term was checked for line using strstr, which finds a substring (needle) inside a string (haystack).
    - If file(s) were given:
        - Loops through all files and prints matching lines
    - Closes and frees memory

### my-zip.c
- `main`
    - Checks for appropriate arguments
    - Loops each file given and compresses using a 4-byte integer in binary format:
        - Works my looping over each character and checking:
            - If previous character was the same, add to count
            - If different than previous character, write count and previous character to stdout and reset count and change previous character to current.
    - Last character is printed outside to make sure nothing is left behind.

### my-unzip.c
- `main`
    - Very similar to `my-zip.c` but files are read in binary and logic inside loop is slightly different.
    - Checks for appropriate arguments
    - Loops each file given and uncompresses using fread(). No need for manual uncompression here.

## Running the programs
### my-cat.c
To translate the program, use
```gcc my-cat.c -o my-cat -Wall -Werror```
Then, run:
```./my-cat <files>```

### my-grep.c
To translate the program, use
```gcc my-grep.c -o my-grep -Wall -Werror```
Then, run:
```./my-grep <searchterm> [files]```

### my-zip.c
To translate the program, use
```gcc my-zip.c -o my-zip -Wall -Werror```
Then, run:
```./my-zip <files>```
Optionally, use a redirection operator `>` to redirect output:
```./my-zip <files> > output.z```

### my-unzip.c
To translate the program, use
```gcc my-unzip.c -o my-unzip -Wall -Werror```
Then, run:
```./my-unzip <files>```
Optionally, use a redirection operator `>` to redirect output:
```./my-unzip <files> > output.txt```