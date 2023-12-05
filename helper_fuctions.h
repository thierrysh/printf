fndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include "macros_and_structs.h"

int check_printable(char);
int append_hex_code(char ascii_code, char buffer[], int idx);
int is_digit_char(char ch);
long int convert_size_to_number(long int num, int size);
long int convert_size_to_unsigned(unsigned long int num, int size);

#endif /* HELPER_FUNCTIONS_H TASK INITIAL*/


