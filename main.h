#ifndef MAIN_H

#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "macros_and_structs.h"
#include "helper_functions.h"


int _printf(const char *format, ...);

int print_args(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int accuracy, int size);

int char_display(va_list types, char buffer[],
		int flags, int width, int precision, int size);

int string_display(va_list types, char buffer[],
		int flags, int width, int precision, int size);

int percent_display(va_list types, char buffer[],
		int flags, int width, int precision, int size);

int integer_display(va_list types, char buffer[],
		int flags, int width, int precision, int size);

int binary_display(va_list types, char buffer[],
		int flags, int width, int precision, int size);

int unsigned_echo(va_list types, char buff[],
		int f, int w, int p, int s);

int octal_echo(va_list types, char buff[],
		int f, int w, int p, int s);

int hexadecimal_echo(va_list types, char buff[],
		int f, int w, int p, int s);

int hexa_echo(va_list types, char buff[],
		int f, int w, int p, int s);

int echo_hexa_lower(va_list types, char map_to[], char buff[],
		int f, char flag_ch, int w, int p, int s);


int print_unprintable_ascii(va_list args, char out_buffer[],
		                            int flags_calcs, int width_field, int prec,
					                                int size_spec);


int display_pointer_value(va_list args, char out_buffer[], int flags_calcs, 
				int width_field, int prec, int size_spec);

int count_flags(const char *format, int *i);
int custom_width(const char *format, int *index, va_list arg_list);

int accuracy(const char *format, int *index, va_list arg_list);

int calculate_argument_size(const char *format, int *currentIndex);

int display_reversed_str(va_list args, char out_buffer[],
		                         int flags_calcs, int width_field, int prec,
					                          int size_spec);

int display_rot13_encoded_str(va_list args, char out_buffer[],
		                              int flags_calcs, int width_field, int prec,
					                                    int size_spec);

int custom_char_write(char c, char buffer[],
		                      int flags, int width, int acc, int size);

int write_custom_number(int is_negative, int ind, char buffer[],
		                        int flags, int width, int acc, int size);

int write_num_custom(int ind, char buffer[],
		                     int flags, int width, int acc,
				                          int length, char padd, char extra_c);

int write_unsigned(int is_negative, int ind,
		                   char buffer[], int flags, int width, int acc, int size);

int write_custom_pointer(char buffer[], int ind, int length,
		                         int width, int flags, char padd,
					                          char extra_c, int padd_start);

#endif /* MAIN_H */

