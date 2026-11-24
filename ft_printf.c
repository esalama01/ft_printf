/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsalama <elsalama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 22:32:24 by elsalama          #+#    #+#             */
/*   Updated: 2026/11/23 22:34:40 by elsalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

// Variadic function to print given arguments
void print(int n, ...) {
    va_list args;
    va_start(args, n);
	printf("%zu\n", args.gp_offset);  
    for (int i = 0; i < n; i++) 
        printf("%d ", va_arg(args, int));
    printf("\n");
    va_end(args);
}
int main() {
  
  	// Calling function print() with different number
  	// of arguments
    print(3, 1, 2, 3);
    print(5, 1, 2, 3, 4, 5);
  
    return 0;
}