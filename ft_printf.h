/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsalama <elsalama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 07:51:41 by elsalama          #+#    #+#             */
/*   Updated: 2026/11/26 16:55:05 by elsalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_printf(const char *str, ...);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int nbr);
void	ft_hex(unsigned long nb);
void	ft_hexupper(unsigned long nb);
void	ft_uputnbr(unsigned int nb);
void	ft_void(void *ptr);

#endif