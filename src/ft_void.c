/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsalama <elsalama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 12:12:16 by elsalama          #+#    #+#             */
/*   Updated: 2026/11/26 18:23:49 by elsalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_void(void *ptr)
{
	unsigned long	i;
	int				count;
	int				ret;

	count = 0;
	if (!ptr)
	{
		count = ft_putstr("(nil)");
		return (count);
	}
	count += ft_putstr("0x");
	if (count == -1)
		return (count);
	i = (unsigned long)ptr;
	ret = ft_hex(i);
	if (ret == -1)
		return (ret);
	return (count + ret);
}
