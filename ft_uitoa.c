/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwagner <aiwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:56:31 by aiwagner          #+#    #+#             */
/*   Updated: 2022/11/17 19:42:03 by aiwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*putnbr_string(char *res, unsigned int n, int counter,
		unsigned long int x)
{
	int					i;
	unsigned long int	nb;

	i = 0;
	nb = n;
	while (counter > 0)
	{
		if (counter > 1)
			res[i] = nb / x + '0';
		else
			res[i] = nb % 10 + '0';
		i++;
		nb = nb % x;
		x = x / 10;
		counter--;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_uitoa(unsigned int n)
{
	char				*result;
	int					counter;
	unsigned long int	x;

	if (n == 0)
		return ("0");
	x = 1;
	counter = 1;
	while (n / (x * 10) != 0)
	{
		x = x * 10;
		counter++;
	}
	result = malloc(counter + 1);
	if (result == NULL)
		return (NULL);
	result = putnbr_string(result, n, counter, x);
	return (result);
}
