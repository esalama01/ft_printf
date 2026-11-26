/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsalama <elsalama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 08:04:33 by elsalama          #+#    #+#             */
/*   Updated: 2026/11/26 18:36:43 by elsalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr(int nbr)
{
	long	nb;
	int		count;
	int		ret;

	nb = nbr;
	count = 0;
	if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		nb = -nb;
		count++;
	}
	if (nb >= 10)
	{
		ret = ft_putnbr(nb / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putchar((nb % 10) + '0');
	if (ret == -1)
		return (-1);
	return (count + ret);
}
