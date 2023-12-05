#include "main.h"

/************************* WRITE HANDLE *************************/

int custom_char_write(char c, char buffer[],
				int flags, int width, int acc, int size)
{
	int i = 0;
	char padd = ' ';
		UNUSED(acc);
		UNUSED(size);
			if (flags & F_ZERO)
				padd = '0';

				buffer[i++] = c;
				buffer[i] = '\0';

					if (width > 1)
											{
					buffer[BUFF_SIZE - 1] = '\0';
					for (i = 0; i < width - 1; i++)
																						buffer[BUFF_SIZE - i - 2] = padd;

																						if (flags & F_MINUS)
																						return (write(1, &buffer[0], 1) +
																						write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
																				else
																						return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
																					write(1, &buffer[0], 1));
																					}
					return (write(1, &buffer[0], 1));
}

/************************* WRITE NUMBER *************************/

int write_custom_number(int is_negative, int ind, char buffer[],
				int flags, int width, int acc, int size)
{
		int length = BUFF_SIZE - ind - 1;
			char padd = ' ', extra_ch = 0;

				UNUSED(size);

					if ((flags & F_ZERO) && !(flags & F_MINUS))
								padd = '0';

						if (is_negative)
									extra_ch = '-';
							else if (flags & F_PLUS)
										extra_ch = '+';
								else if (flags & F_SPACE)
											extra_ch = ' ';
					return (write_num_custom(ind, buffer, flags, width, acc,
					length, padd, extra_ch));
}

int write_num_custom(int ind, char buffer[],
				int flags, int width, int acc,
						int length, char padd, char extra_c)
{
		int i, padd_start = 1;

			if (acc == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
						return (0);

				if (acc == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
						{
									buffer[ind] = padd = ' ';
										}

					if (acc > 0 && acc < length)
								padd = ' ';

						while (acc > length)
								{
							buffer[--ind] = '0';
								length++;
														}

							if (extra_c != 0)
									length++;

							if (width > length)
										{
							for (i = 1; i < width - length + 1; i++)
									buffer[i] = padd;
									buffer[i] = '\0';

																	if (flags & F_MINUS && padd == ' ')
																				{
																								if (extra_c)
																										buffer[--ind] = extra_c;																									return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
																													}
																			else if (!(flags & F_MINUS) && padd == ' ')
																																									if (extra_c)
																										buffer[--ind] = extra_c;
																								return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
																															}
																					else if (!(flags & F_MINUS) && padd == '0')
																								{
																								if (extra_c)
																								buffer[--padd_start] = extra_c;
																								return (write(1, &buffer[padd_start], i - padd_start) +
																																						write(1, &buffer[ind], length - (1 - padd_start)));
																																	}
																						}

									if (extra_c)
												buffer[--ind] = extra_c;
									return (write(1, &buffer[ind], length));
}

int write_unsigned(int is_negative, int ind,
				char buffer[], int flags, int width, int acc, int size)
{
		int length = BUFF_SIZE - ind - 1, i = 0;
			char padd = ' ';

				UNUSED(is_negative);
					UNUSED(size);

						if (acc == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
									return (0);

							if (acc > 0 && acc < length)
										padd = ' ';

								if ((flags & F_ZERO) && !(flags & F_MINUS))
											padd = '0';

									if (width > length)
											{
														for (i = 0; i < width - length; i++)
																		buffer[i] = padd;
																buffer[i] = '\0';

																		if (flags & F_MINUS)
																					{
																							return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
																										}
																				else
																							{
																							return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
																													}
																					}
						return (write(1, &buffer[ind], length));
}

int write_custom_pointer(char buffer[], int ind, int length,
				int width, int flags, char padd,
						char extra_c, int padd_start)
{
		int i;
			UNUSED(padd_start);

				if (width > length)
						{
									for (i = 3; i < width - length + 3; i++)
													buffer[i] = padd;
											buffer[i] = '\0';

													if (flags & F_MINUS)
																{
																				buffer[--ind] = 'x';
																							buffer[--ind] = '0';
																										if (extra_c)
																															buffer[--ind] = extra_c;
																													return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
																															}
															else
																		{
																						buffer[--ind] = 'x';
																						buffer[--ind] = '0';
																					if (extra_c)
																								buffer[--ind] = extra_c;
																								return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
																																	}
																}

					buffer[--ind] = 'x';
						buffer[--ind] = '0';
							if (extra_c)
								buffer[--ind] = extra_c;
							return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}

