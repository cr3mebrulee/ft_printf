// Beware circular includes
#ifndef FT_HEADER_INCLUDED
#define FT_HEADER_INCLUDED

/*
 * Implementation in ft_character.c
 * */
void ft_character(int character, int *length);


/*
 * Implementation in ft_char_length.c
 * */
void ft_char_length(char character, int *length);


/*
 * Implementation in ft_hexadecimal.c
 * */
void ft_hexadecimal(unsigned int decimal, int *length, char format);


/*
 * Implementation in ft_number.c
 * */
 void ft_number(int number, int *len);


/*
 * Implementation in ft_pointer.c
 * */
void ft_pointer(unsigned long ptr, int *length);


/*
 * Implementation in ft_printf.c
 * */
int ft_printf(const char *str, ...);


/*
 * Implementation in ft_string.c
 * */
void ft_string(char *args, int *length);


/*
 * Implementation in ft_unsigned.c
 * */
void ft_unsigned_int(unsigned int number, int *length);
 
#endif
