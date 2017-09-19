

#include "file_utils.h"



int main(int argc, char **argv)
{
   char* buffer = NULL;
   int input_file_size;

   if (argc != 3)
        handle_error(INVALID_ARGUMENTS);



   input_file_size = read_file(argv[1], &buffer);

   


//free(buffer);
    return 0;
}


