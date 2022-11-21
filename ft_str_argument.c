/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_argument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwagner <aiwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:52:12 by aiwagner          #+#    #+#             */
/*   Updated: 2022/11/17 19:45:36 by aiwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_str_argument(char * str)
{
    int i;
    if (!str)
    {
        ft_putstr_fd("(null)", 1);
        return (6);
    }
    i = ft_strlen(str);
    ft_putstr_fd(str, 1);
    return (i);
}