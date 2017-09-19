

#include "file_utils.h"



int main(int argc, char **argv)
{
   char* text;
   char** buffer;
   int input_file_size;

   if (argc != 2)
        handle_error(INVALID_ARGUMENTS);

   input_file_size = get_file_size(argv[1]);

   text = (char*) malloc(input_file_size + 1);

   if (text == NULL)
        handle_error(MEM_ALLOCATION);

   buffer = &text;

   read_file(argv[1], buffer);

   free(text);

    return 0;
}


