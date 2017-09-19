#include "file_utils.h"

int read_file( char* filename, char **buffer ) {

    //Based on code used in my final project for CIS 361
    //Original code provided by professor Dr. Vijay Bhuse
    FILE* f = fopen(filename, "r");
    char *search_ptr;
    if (f == NULL)
        handle_error(FILE_NOT_FOUND);

    while(!feof(f)) {
         fgets(buffer, SIZE, f);

    }

    printf("%s", buffer);
    return 0;
}


int write_file( char* filename, char *buffer, int size){

}

int get_file_size(char* filename) {
    struct stat st;
    if ( stat( filename, &st ) == -1 )
        handle_error(FILE_NOT_FOUND);
    int size = st.st_size;
    return size;
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
                    "[OUTPUT_FILENAME]" );
            break;
        case 1 :
            fprintf( stderr, "No such file or directory\n" );
            break;
        case 2 :
            fprintf( stderr, "Memory allocation error.\n" );
            break;

    }
    exit(1);
}
