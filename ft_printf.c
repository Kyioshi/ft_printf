/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwagner <aiwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:59:09 by aiwagner          #+#    #+#             */
/*   Updated: 2022/11/17 19:21:18 by aiwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		result;
	int		i;
	int		parsed_char;
	va_list	ptr;

	if (!str)
		return (0);
	i = 0;
	result = 0;
	parsed_char = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			parsed_char += ft_parse_argument(ptr, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			result++;
		}
		i++;
	}
	result += parsed_char;
	va_end(ptr);
	return (result);
}
