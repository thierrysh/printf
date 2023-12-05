#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
   * unsigned_echo - echoes an unsigned number
    * @types: List a of arguments
     * @buff: Buffer array to handle print
      * @f: Calculates active flags
       * @w: get width
        * @p: Precision specification
	 * @s: Size specifier
	  * Return: Number of chars printed.
	   */
int unsigned_echo(va_list types, char buff[],
		int f, int w, int p, int s)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	num = convert_size_to_unsigned(num, s);
	if (num == 0)
		buff[i--] = '0';
	buff[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsigned(0, i, buff, f, w, p, s));
}

/**
   * octal_echo - echos an unsigned number in octal notation
    * @types: Lista of arguments
     * @buff: Buffer array to handle print
      * @f: Calculates active flags
       * @w: get width
        * @p: Precision specification
	 * @s: Size specifier
	  * Return: Number of chars printed
	   */
int octal_echo(va_list types, char buff[],
		int f, int w, int p, int s)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;
	UNUSED(w);
	num = convert_size_to_unsigned(num, s);
	if (num == 0)
		buff[i--] = '0';
	buff[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buff[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (f & F_HASH && init_num != 0)
		buff[i--] = '0';
	i++;
	return (write_unsigned(0, i, buff, f, w, p, s));
}

/**
   * hexadecimal_echo - echoes an unsigned number in hexadecimal notation
    * @types: Lista of arguments
     * @buff: Buffer array to handle print
      * @f: Calculates active flags
       * @w: get width
        * @p: Precision specification
	 * @s: Size specifier
	  * Return: Number of chars printed
	   */
int hexadecimal_echo(va_list types, char buff[],
		int f, int w, int p, int s)
{
	return (echo_hexa_lower(types, "0123456789abcdef", buff,
				f, 'x', w, p, s));
}

/**
   * hexa_echo - displays an unsigned number in upper hexadecimal notation
    * @types: Lista of arguments
     * @buff: Buffer array to handle print
      * @f: Calculates active flags
       * @w: get width
        * @p: Precision specification
	 * @s: Size specifier
	  * Return: Number of chars printed
	   */
int hexa_echo(va_list types, char buff[],
		int f, int w, int p, int s)
{
	return (echo_hexa_lower(types, "0123456789ABCDEF", buff,
				f, 'X', w, p, s));
}

/**
   * echo_hexa_lower - displays a hexadecimal number in lower or upper
    * @types: Lista of arguments
     * @map_to: Array of values to map the number to
      * @buff: Buffer array to handle print
       * @f: Calculates active flags
        * @flag_ch: Calculates active flags
	 * @w: get width
	  * @p: Precision specification
	   * @s: Size specifier
	    * @s: Size specification
	     * Return: Number of chars printed
	      */
int echo_hexa_lower(va_list types, char map_to[], char buff[],
		int f, char flag_ch, int w, int p, int s)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;
	UNUSED(w);
	num = convert_size_to_unsigned(num, s);
	if (num == 0)
		buff[i--] = '0';
	buff[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buff[i--] = map_to[num % 16];
		num /= 16;
	}
	if (f & F_HASH && init_num != 0)
	{
		buff[i--] = flag_ch;
		buff[i--] = '0';
	}
	i++;
	return (write_unsigned(0, i, buff, f, w, p, s));
}


