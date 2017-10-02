/***********************************************************************
 	@author Mike Ames
 	@version Fall 2017
***********************************************************************/

#include "file_utils.h"
#include <stdlib.h>

/***********************************************************************
  Main driver for the reverse program. Assures that the correct
  number of arguments has been provided.
  @params Input_filename the file to read from
  @params Output_filename the file to write to
  @return 0 on success.
***********************************************************************/
int main(int argc, char **argv) {
   
   char* buffer;
   int input_file_size;

   if (argc != 3)
        handle_error(INVALID_ARGUMENTS);

   input_file_size = read_file(argv[1], &buffer);

   reverse(buffer);

   write_file(argv[2], buffer, input_file_size);

   free(buffer);
    
   return 0;
}