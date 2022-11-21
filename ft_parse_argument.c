/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwagner <aiwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:20:38 by aiwagner          #+#    #+#             */
/*   Updated: 2022/11/17 19:56:09 by aiwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_argument(va_list ptr, char c)
{
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(ptr, int), 1);
		return (1);
	}
	else if (c == 's')
		return (ft_str_argument(va_arg(ptr, char *)));
	else if (c == 'i' || c == 'd')
		return (ft_str_argument(ft_itoa(va_arg(ptr, int))));
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	else if (c == 'u')
		return (ft_str_argument(ft_uitoa(va_arg(ptr, unsigned int))));
	else if (c == 'x')
		return (ft_print_hex_lowercase(va_arg(ptr, unsigned int), 0));
	else if (c == 'X')
		return (ft_print_hex_lowercase(va_arg(ptr, unsigned int), 1));
	else if (c == 'p')
		return (ft_print_hex_pointer(va_arg(ptr, unsigned long long)));
	return (0);
}
