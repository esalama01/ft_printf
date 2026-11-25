/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsalama <elsalama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 07:51:41 by elsalama          #+#    #+#             */
/*   Updated: 2026/11/25 14:27:01 by elsalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_printf(const char *str, ...);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int nbr);
void	ft_hex(int nb);

#endif