#include "file_utils.h"
#include <string.h>
#include <ctype.h>

int read_file( char* filename, char **buffer ) {

    int size = get_file_size(filename);
    //Based on code used in my final project for CIS 361
    //Original code provided by professor Dr. Vijay Bhuse
    FILE* f = fopen(filename, "r");
    char line[SIZE];
    if (f == NULL)
        handle_error(FILE_NOT_FOUND);

    *buffer = malloc(size + 1);

   if (buffer == NULL)
        handle_error(MEM_ALLOCATION);

    while(!feof(f)) {
         fgets(line, SIZE, f);
         strcat(*buffer, line);

    }
    
    printf("%s\n", *buffer);
    reverse(*buffer);
    printf("%s\n", *buffer);
    
    fclose(f);

    return size;
}


int write_file( char* filename, char *buffer, int size){

    FILE* f = fopen(filename, "w");
    
    if(f == NULL)
        handle_error(FILE_CREATION);
    if( (fputs(buffer, f)) == EOF)
        handle_error(FILE_WRITE);

    fclose(f);

    return 0;
}

int get_file_size(char* filename) {
    struct stat st;
    if ( stat( filename, &st ) == -1 )
        handle_error(FILE_NOT_FOUND);
    int size = st.st_size;
    return size;
}

void reverse(char* string) {
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

    }
    exit(1);
}
