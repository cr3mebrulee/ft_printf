/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:51:36 by taretiuk          #+#    #+#             */
/*   Updated: 2024/01/09 17:58:56 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_char_length(char character, int *length)
{
	write(1, &character, 1);
	(*length)++;
}

void    ft_hexadecimal(unsigned long decimal, int *length, char format)
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

void    ft_pointer(unsigned long ptr, int *length)
{
    if (0 == ptr)
    {
      write(1, "(nil)", 5);
      length += 5;
    }
    else
    {
      write(1, "0x", 2);
      length += 2;
      ft_hexadecimal(ptr, length, 'x');
    }
}

int main()
{
    int a = 9;
    int length = 0;
    int *p = &a;
    ft_pointer((unsigned long)p, &length);
    return (0);
}
