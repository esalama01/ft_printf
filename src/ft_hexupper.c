/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsalama <elsalama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 14:47:50 by elsalama          #+#    #+#             */
/*   Updated: 2026/11/26 18:27:40 by elsalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	calc_size(unsigned long n)
{
	int	size;

	size = 0;
	while (n > 0)
	{
		size++;
		n /= 16;
	}
	return (size);
}

static char	*zero_handler(void)
{
	char	*str;

	str = malloc(2);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char	*ft_hexoa(unsigned long n)
{
	int		size;
	int		l;
	char	*str;
	char	*base;

	base = "0123456789ABCDEF";
	if (n == 0)
		return (zero_handler());
	size = calc_size(n);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	l = size;
	while (l-- > 0 && n > 0)
	{
		str[l] = base[n % 16];
		n /= 16;
	}
	str[size] = '\0';
	return (str);
}

int	ft_hexupper(unsigned long nb)
{
	char	*str;
	int		count;

	str = ft_hexoa(nb);
	if (!str)
		return (-1);
	count = ft_putstr(str);
	free(str);
	return (count);
}
