/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:48:22 by taretiuk          #+#    #+#             */
/*   Updated: 2024/01/07 17:17:09 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_char_length(char character, int *length)
{
	write(1, &character, 1);
	(*length)++;
}

void    ft_hexadecimal(unsigned int decimal, int *length, char format)
{
    char reversedhex[100];
    int remain;
    int i;
    i = 0;

    while (decimal > 0)
    {
        remain = decimal % 16;
            if (remain < 10)
            {
                reversedhex[i] = '0' + remain;
            }
            else
            {
                if (format == 'x')
                    reversedhex[i] = 'a' + (remain - 10);
                else
                    reversedhex[i] = 'A' + (remain - 10);
            }
            decimal = decimal / 16;
            i++;
    *length = i;
    }
    while (i--)
    {
        ft_char_length(reversedhex[i], length);
    } 
}
/*
int main()
{
    unsigned int decimal = -7011247;
    int length = 0;
    ft_hexadecimal(decimal, &length, 'X');
    return (0);
}
*/