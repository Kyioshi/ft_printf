/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwagner <aiwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:50:56 by aiwagner          #+#    #+#             */
/*   Updated: 2022/11/17 19:59:01 by aiwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int	ft_parse_argument(va_list ptr, char c);
char	*ft_uitoa(unsigned int n);
int ft_print_hex_lowercase(unsigned long n, int upper);
int ft_print_hex_pointer(unsigned long long n);
int ft_str_argument(char *);
#endif
