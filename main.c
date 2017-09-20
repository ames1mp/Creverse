/***********************************************************************
 	@author Mike Ames
 	@version Fall 2017
***********************************************************************/

#include "file_utils.h"

int main(int argc, char **argv) {
   
   char* buffer;
   int input_file_size;

   if (argc != 3)
        handle_error(INVALID_ARGUMENTS);

   input_file_size = read_file(argv[1], &buffer);

   write_file(argv[2], buffer, input_file_size);

   free(buffer);
    
   return 0;
}


