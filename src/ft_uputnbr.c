/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsalama <elsalama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 15:03:25 by elsalama          #+#    #+#             */
/*   Updated: 2026/11/26 18:35:29 by elsalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_uputnbr(unsigned int nb)
{
	int		count;
	int		ret;

	count = 0;
	if (nb >= 10)
	{
		ret = ft_uputnbr(nb / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putchar((nb % 10) + '0');
	if (ret == -1)
		return (-1);
	return (count + ret);
}
