/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_pointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwagner <aiwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:49:38 by aiwagner          #+#    #+#             */
/*   Updated: 2022/11/17 19:33:09 by aiwagner         ###   ########.fr       */
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

static int	ft_eval_char_size(unsigned long long n)
{
	int	i;

	i = 0;
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

int	ft_print_hex_pointer(unsigned long long n)
{
	char	*res;
	int		rem;
	char	ch;
	int		j;

	res = malloc(ft_eval_char_size(n) + 1);
	if (!res || n == 0)
		return (ft_str_argument("(nil)"));
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
	res = ft_strmapi_real(res, &ft_tolower);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(res, 1);
	return (2 + ft_strlen(res));
}
