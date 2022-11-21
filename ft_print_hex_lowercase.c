/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_lowercase.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwagner <aiwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:37:28 by aiwagner          #+#    #+#             */
/*   Updated: 2022/11/17 20:01:42 by aiwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strmapi_real(char const *s, int (*f)(int))
{
	size_t	i;
	char	*result;

	i = 0;
	if (!s)
		return (NULL);
	result = (char *)malloc(ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[i] = (*f)(s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

static int	ft_eval_char_size(unsigned long n)
{
	int	i;

	i = 1;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static char	*ft_strrev(char *str)
{
	int		len;
	int		i;
	char	tmp;

	len = 0;
	i = 0;
	len = ft_strlen(str);
	len -= 1;
	while (i < len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	return (str);
}

int	ft_print_hex_lowercase(unsigned long n, int upper)
{
	char	*res;
	int		rem;
	char	ch;
	int		j;

	if(n == 0)
		return(ft_str_argument("0"));
	res = malloc(ft_eval_char_size(n) + 1);
	j = 0;
	rem = 0;
	while (n != 0)
	{
		rem = n % 16;
		if (rem < 10)
			ch = rem + 48;
		else
			ch = rem + 55;
		res[j++] = ch;
		n = n / 16;
	}
	res[j] = '\0';
	res = ft_strrev(res);
	if (upper != 1)
		res = ft_strmapi_real(res, &ft_tolower);
	ft_putstr_fd(res, 1);
	return (ft_strlen(res));
}
