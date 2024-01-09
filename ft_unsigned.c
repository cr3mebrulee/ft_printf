/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:18:04 by taretiuk          #+#    #+#             */
/*   Updated: 2024/01/05 16:08:32 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void	ft_char_length(char character, int *length)
{
	write(1, &character, 1);
	(*length)++;
}

void    ft_unsigned_int(unsigned int number, int *length)
{
    if (number > 9)
    {
        ft_unsigned_int(number / 10, length);
        ft_unsigned_int(number % 10, length);
    }
    else
        ft_char_length((number + 48), length);
}
/*
int main()
{
    int length = 0;
    ft_unsigned_int(23.2, &length);
    return (0);
}
*/