/***********************************************************************
 	@author Mike Ames
 	@version Fall 2017
***********************************************************************/
#include "file_utils.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

/***********************************************************************
 	Dynamically allocates memory equal to the size of the input file
 	plus one byte (for the terminating null-character). Opens the input
 	file and reads the text into the allocated memory. Calls the reverse
 	function, and returns the the size of the input file.
    @param filename the file from which to read.
    @param buffer a pointer to a pointer to the address where we will
           allocate data.
    @return size the size of the input file in bytes.
***********************************************************************/
int read_file( char* filename, char **buffer ) {

    int size = get_file_size(filename);
    char line[SIZE];

    //Based on code used in my final project for CIS 361.
    //Original code provided by professor Vijay Bhuse.
    FILE* f = fopen(filename, "r");
    
    if (f == NULL)
        handle_error(FILE_NOT_FOUND);

//When the test file ended with a blank line, I would get the 
//Following error when running the program:
// Error in `./a': double free or corruption (out): 0x00000000024e23e0
//Assuming that there was a problem somewhere with extra invisible
//control characters I added an additional bytes to the buffer and
//this resolved the issue.    
    *buffer = (char*) malloc(sizeof(char) * size + 10);

   if (buffer == NULL)
        handle_error(MEM_ALLOCATION);

    while(!feof(f)) {
         fgets(line, SIZE, f);
         strncat(*buffer, line, size - strlen(line) - 1);
         //size of destination buffer - size of destination line - 1
    }
    
    if ( (fclose(f)) != 0)
        handle_error(FILE_CLOSE_IN);

    return size;
}

/***********************************************************************
 	Creates or opens a file to write the buffer to. On the success of
 	this operation the file is written to and closed. 
    @param filename the file to write to.
    @param buffer a pointer to the string to write to file.
    @return 0 on success.
***********************************************************************/
int write_file( char* filename, char *buffer, int size){

    FILE* f = fopen(filename, "w");
    
    if(f == NULL)
        handle_error(FILE_CREATION);
    if( (fputs(buffer, f)) == EOF)
        handle_error(FILE_WRITE);

    if ( (fclose(f)) != 0)
        handle_error(FILE_CLOSE_OUT);

    return 0;
}

/***********************************************************************
 	Creates a stat struct, populates it with data about the input file
 	and returns the file's size.
    @param filename the input file
    @return size the file's size in bytes.
***********************************************************************/
int get_file_size(char* filename) {
    struct stat st;
    if ( stat( filename, &st ) == -1 )
        handle_error(FILE_NOT_FOUND);
    int size = st.st_size;
    
    return size;
}

/***********************************************************************
 	Reverses the text of a string.
    @param string the string to reverse.
***********************************************************************/
void reverse(char* string) {
/*based on code from:
https://www.daniweb.com/programming/software-development
/threads/311002/strrev-equivalent-in-linux*/
    int first = 0;
    int last = strlen(string) - 1;
    char temp;

    while (first < last) {
        temp = string[first];
        string[first] = string[last];
        string[last] = temp;
        ++first;
        --last;
    }

    return;
}


/***********************************************************************
    Prints an error message to stderr and exits the program with '1'
    @param error_code a macro defined integer which indicates what type
    of error occurred.
***********************************************************************/
void handle_error(int error_code) {

    switch(error_code) {

        case 0 :
            fprintf( stderr, "%s",
                    "Usage: ./reverse [INPUT_FILENAME] "
                    "[OUTPUT_FILENAME]\n" );
            break;
        case 1 :
            fprintf( stderr, "No such file or directory\n" );
            break;
        case 2 :
            fprintf( stderr, "Memory allocation error.\n" );
            break;
        case 3 :
            fprintf( stderr, "Error creating or opening file.\n" );
            break;
        case 4 :
            fprintf( stderr, "Error writing to file.\n" );
            break;
        case 5 :
            fprintf( stderr, "Error closing the IN file.\n" );
            break;
        case 6 :
            fprintf( stderr, "Error closing the OUT file.\n" );
            break;
    }
    
    exit(1);
}
