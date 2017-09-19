#ifndef FILE_UTILS
#define FILE_UTILS

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define SIZE 2048
#define INVALID_ARGUMENTS 0
#define FILE_NOT_FOUND 1
#define MEM_ALLOCATION 2

int read_file( char* filename, char **buffer );
int write_file( char* filename, char *buffer, int size);

int get_file_size(char* filename);
void handle_error(int error_code);
























#endif // FILE_UTILS
