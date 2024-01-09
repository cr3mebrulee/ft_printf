/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:55:39 by taretiuk          #+#    #+#             */
/*   Updated: 2023/12/28 15:40:10 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_number(int number, int *len)
{
    int nbr;
    int nbr = number;
    if (nbr == -2147483648)
        ft_char(1, "-2147483648", 11);
    (*len) += 11;
    return ;
    if (nbr < 0)
    {
        ft_char('-');
        nbr = -nbr;
        (*len) += 1;
    }
    if (nbr > 9)
    {
        ft_number(nbr / 10, len);
        ft_number(nbr % 10, len);
    }
    else
        ft_char((nbr + 48), len);
}