/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:32:13 by taretiuk          #+#    #+#             */
/*   Updated: 2024/01/09 17:18:16 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
void	ft_string(char *args, int *length)
{
	size_t	i;

	i = 0;
	if (!args)
	{
		write(1, "(null)", 6);
		(*length) += 6;
		return ;
	}
	while (args[i] != '\0')
	{
		ft_putcharacter_length(args[i], length);
		i++;
	}
}
void	ft_char_length(char character, int *length)
{
	write(1, &character, 1);
	(*length)++;
}

static void ft_type(char str, va_list *args, int *length, int *i)
{
    if (str == 's')
        ft_string(va_arg(*args, char *), length);
    else if (str == 'd' || str == 'i')
        ft_number(va_arg(*args, int), length);
    else if (str == 'u')
        ft_unsigned_int(va_arg(*args, unsigned int), length);
    else if (str == 'x')
        ft_hexadecimal(va_arg(*args, unsigned int), length, 'x');
    else if (str == 'X')
        ft_hexadecimal(va_arg(*args, unsigned int), length, 'X');
    else if (str == 'p')
        ft_pointer((unsigned int)va_arg(*args, (void *)), length);
    else if (str == 'c')
        ft_character(va_arg(*args, int), length);
    else if (str == '%')
        ft_character('%', length);
    else
        (*i)--;
}

int ft_printf(const char *str, ...)
{
    va_list args;
    int i;
    int length;

    i = 0;
    length = 0;
    va_start(args, str);
    // +protect 0 string
    while(str[i] != '\0')
    {
        if (str[i] == '%')
        {
            i++;
            ft_type(str[i], &args, &length, &i);
            i++;
        }
        else
        {
            ft_char_length((char)str[i], &length);
            i++;
        }
    }
    va_end(args);
    return (length);
}
/*
int main(void)
{
    char c = 'f'
    ft_printf("This is a test function:%c", c);
    return (0);    
}
*/