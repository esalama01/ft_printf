/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsalama <elsalama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 22:32:24 by elsalama          #+#    #+#             */
/*   Updated: 2026/11/28 15:56:10 by elsalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char spec, va_list *list)
{
	if (spec == 'c')
		return (ft_putchar(va_arg(*list, int)));
	else if (spec == 's')
		return (ft_putstr(va_arg(*list, char *)));
	else if (spec == 'p')
		return (ft_void(va_arg(*list, void *)));
	else if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(*list, int)));
	else if (spec == 'u')
		return (ft_uputnbr(va_arg(*list, unsigned int)));
	else if (spec == 'x')
		return (ft_hex(va_arg(*list, unsigned int)));
	else if (spec == 'X')
		return (ft_hexupper(va_arg(*list, unsigned int)));
	else if (spec == '%')
		return (ft_putchar('%'));
	return (0);
}

static int	ft_parse(const char *str, va_list *list)
{
	int	i;
	int	count;
	int	ret;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!str[i + 1])
				return (-1);
			ret = ft_format(str[i + 1], list);
			i++;
		}
		else
			ret = ft_putchar(str[i]);
		if (ret == -1)
			return (-1);
		count += ret;
		i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		count;

	if (!str)
		return (-1);
	va_start(list, str);
	count = ft_parse(str, &list);
	va_end(list);
	return (count);
}
