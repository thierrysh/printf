/**
 * truct fmt - Struct op
  * @fmt: The format.
   * @fn: The function associated.
    */

    struct fmt

{

	char fmt;

	int (*fn)(va_list, char[], int, int, int, int);

};




/**
   * typedef struct fmt fmt_t - Struct op
    *
     * @fmt: The format.
      * @fm_t: The function associated.
       */

typedef struct fmt fmt_t;


