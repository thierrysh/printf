nclude "main.h"
#include "stdlib.h"

/****************** PRINT POINTER ******************/
/**
   * display_pointer_value - Prints the value of a pointer variable
    * @args: Listed of arguments
     * @out_buffer: Buffer array to handle print
      * @flags_calcs: Calculates active flags
       * @width_field: Get width
        * @prec: Precision specification
	 * @size_spec: Size specifier
	  * Return: Number of characters printed.
	   */
int display_pointer_value(va_list args, char out_buffer[],
				int flags_calcs, int width_field, int prec,
						int size_spec)
{
		char add_char = 0, pad_char = ' ';
			int buf_idx = BUFF_SIZE - 2, len = 2, pad_start = 1; /* len=2, for '0x' */
				unsigned long addr_num;
					char mapping[] = "0123456789abcdef";
						void *addr = va_arg(args, void *);

							UNUSED(width_field);
								UNUSED(size_spec);

									if (addr == NULL)
												return (write(1, "NULL", 4));

										out_buffer[BUFF_SIZE - 1] = '\0';
											UNUSED(prec);
												addr_num = (unsigned long)addr;

													while (addr_num > 0)
															{
																		out_buffer[buf_idx--] = mapping[addr_num % 16];
																				addr_num /= 16;
																						len++;
																							}

														if ((flags_calcs & F_ZERO) && !(flags_calcs & F_MINUS))
																	pad_char = '0';

															if (flags_calcs & F_PLUS)
																		add_char = '+', len++;
																else if (flags_calcs & F_SPACE)
																			add_char = ' ', len++;

																	buf_idx++;
																		return (write_custom_pointer(out_buffer, buf_idx, len,
																									width_field, flags_calcs, pad_char,
																													add_char, pad_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
   * print_unprintable_ascii - Prints ASCII codes in hexadecimal of
    *                           non-printable characters
     * @args: Listed of arguments
      * @out_buffer: Buffer array to handle print
       * @flags_calcs: Calculates active flags
        * @width_field: Get width
	 * @prec: Precision specification
	  * @size_spec: Size specifier
	   * Return: Number of characters printed
	    */
int print_unprintable_ascii(va_list args, char out_buffer[],
				int flags_calcs, int width_field, int prec,
						int size_spec)
{
		int i = 0, offset = 0;
			char *in_str = va_arg(args, char *);

				UNUSED(flags_calcs);
					UNUSED(width_field);
						UNUSED(prec);
							UNUSED(size_spec);

								if (in_str == NULL)
											return (write(1, "(null)", 6));

									while (in_str[i] != '\0')
											{
														if (check_printable(in_str[i]))
																		out_buffer[i + offset] = in_str[i];
																else
																				offset += append_hex_code(in_str[i], out_buffer, i + offset);
																		i++;
																			}

										out_buffer[i + offset] = '\0';
											return (write(1, out_buffer, i + offset));
}

/************************* PRINT REVERSE *************************/
/**
   * display_reversed_str - Prints a string in reverse.
    * @args: Listed of arguments
     * @out_buffer: Buffer array to handle print
      * @flags_calcs: Calculates active flags
       * @width_field: Get width
        * @prec: Precision specification
	 * @size_spec: Size specifier
	  * Return: Number of characters printed
	   */
int display_reversed_str(va_list args, char out_buffer[],
				int flags_calcs, int width_field, int prec,
						int size_spec)
{
		char *in_str;
			int i, count = 0;

				UNUSED(out_buffer);
					UNUSED(flags_calcs);
						UNUSED(width_field);
							UNUSED(size_spec);

								in_str = va_arg(args, char *);

									if (in_str == NULL)
											{
														UNUSED(prec);
																in_str = ")Null(";
																	}

										for (i = 0; in_str[i]; i++)
													;

											for (i = i - 1; i >= 0; i--)
													{
																char ch = in_str[i];

																		write(1, &ch, 1);
																				count++;
																					}

												return (count);
}

/************************* PRINT A STRING IN ROT13 *************************/
/**
   * display_rot13_encoded_str - Print a string in ROT13 encoding.
    * @args: Listed of arguments
     * @out_buffer: Buffer array to handle print
      * @flags_calcs: Calculates active flags
       * @width_field: Get width
        * @prec: Precision specification
	 * @size_spec: Size specifier
	  * Return: Number of characters printed
	   */
int display_rot13_encoded_str(va_list args, char out_buffer[],
				int flags_calcs, int width_field, int prec,
						int size_spec)
{
		char encoded_ch;
			char *in_str;
				unsigned int i, j;
					int count = 0;
						char in_alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
							char out_alphabet[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

								in_str = va_arg(args, char *);
									UNUSED(out_buffer);
										UNUSED(flags_calcs);
											UNUSED(width_field);
												UNUSED(prec);
													UNUSED(size_spec);

														if (in_str == NULL)
																	in_str = "(AHYY)";

															for (i = 0; in_str[i]; i++)
																	{
																				for (j = 0; in_alphabet[j]; j++)
																							{
																											if (in_alphabet[j] == in_str[i])
																															{
																																				encoded_ch = out_alphabet[j];
																																								write(1, &encoded_ch, 1);
																																												count++;
																																																break;
																																																			}
																													}

																						if (!in_alphabet[j])
																									{
																													encoded_ch = in_str[i];
																																write(1, &encoded_ch, 1);
																																			count++;
																																					}
																							}

																return (count);
}


