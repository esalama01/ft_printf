/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsalama <elsalama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 22:32:24 by elsalama          #+#    #+#             */
/*   Updated: 2026/11/25 12:06:05 by elsalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    va_list list;
    int     i;

    i = 0;
    va_start(list, str);
    while (str[i])
    {
        if (str[i] == '%')
        {
            if (str[i + 1] && str[i + 1] == 'c')
            {
                ft_putchar(va_arg(list, int));
                i++;
            }
            if (str[i + 1] && str[i + 1] == 's')
            {
                ft_putstr(va_arg(list, char *));
                i++;
            }
        }
        else
        {
            ft_putchar(str[i]);
        }
        i++;
    }
    va_end(list);
    return (1);
}