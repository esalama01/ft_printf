/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsalama <elsalama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 12:12:16 by elsalama          #+#    #+#             */
/*   Updated: 2026/11/26 16:54:57 by elsalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_void(void *ptr)
{
	unsigned long	i;

	if (!ptr)
	{
		ft_putstr("(nil)");
		return ;
	}
	i = (unsigned long)ptr;
	ft_putstr("0x");
	ft_hex(i);
}