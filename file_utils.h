/***********************************************************************
 	@author Mike Ames
 	@version Fall 2017
***********************************************************************/
#ifndef FILE_UTILS
#define FILE_UTILS

#define SIZE 2048
#define INVALID_ARGUMENTS 0
#define FILE_NOT_FOUND 1
#define MEM_ALLOCATION 2
#define FILE_CREATION 3
#define FILE_WRITE 4
#define FILE_CLOSE_IN 5
#define FILE_CLOSE_OUT 6

int read_file( char* filename, char **buffer );
int write_file( char* filename, char *buffer, int size);

int get_file_size(char* filename);
void handle_error(int error_code);
void reverse(char* string);

#endif // FILE_UTILS
