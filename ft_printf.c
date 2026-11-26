/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsalama <elsalama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 22:32:24 by elsalama          #+#    #+#             */
/*   Updated: 2026/11/26 16:27:17 by elsalama         ###   ########.fr       */
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
            if (str[i + 1] && str[i + 1] == '%')
            {
                ft_putchar('%');
                i++;
            }
            if (str[i + 1] && str[i + 1] == 's')
            {
                ft_putstr(va_arg(list, char *));
                i++;
            }
            if (str[i + 1] && str[i + 1] == 'x')
            {
                ft_hex(va_arg(list, int));
                i++;
            }
            if (str[i + 1] && str[i + 1] == 'X')
            {
                ft_hexupper(va_arg(list, int));
                i++;
            }
            if (str[i + 1] && (str[i + 1] == 'd' || str[i + 1] == 'i'))
            {
                ft_putnbr(va_arg(list, int));
                i++;
            }
            if (str[i + 1] && str[i + 1] == 'u')
            {
                ft_uputnbr(va_arg(list, int));
                i++;
            }
            if (str[i + 1] && str[i + 1] == 'p')
            {
                ft_void(va_arg(list, void *));
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