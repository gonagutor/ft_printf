/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:25:22 by gaguado-          #+#    #+#             */
/*   Updated: 2021/01/26 17:10:39 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

/*
** This functions takes 2 strings and creates a new one that contains
** The string *strto* up to *from* + the rest of the string starting
** from *upto* + the string *strfrom*
*/
char	*ft_insert_on_position(int from, int upto, const char* strto, char* strfrom)
{
	char *ret;

	ret = malloc(ft_strlen((char*)strto) - (upto + 1 - from) + ft_strlen(strfrom));
	ft_strlcpy(ret, strto, from + 1);
	ft_strlcat(ret, strfrom, ft_strlen(strfrom) + ft_strlen(ret) + 1);
	ft_strlcat(ret, &strto[upto + 1], ft_strlen(ret) + ft_strlen((char *)&strto[upto]) + 1);
	return (ret);
}

void	ft_puthex(unsigned long x)
{
	int		num;
	char	hex[17];

	hex[17] = "0123456789abcdef";
	// THIS HAS NOT BEEN TESTED TODO: TEST THIS
	ft_putchar_fd(hex[x % 16], 1);
	if (x / 10 > 0)
		ft_puthex(x / 10);
}

int		ft_printf(const char *str, ...)
{
	va_list argptr;
	int		i;

	va_start(argptr, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 's')
				ft_putstr_fd(va_arg(argptr, char*), 1);
			if (str[i + 1] == 'd')
				ft_putnbr_fd(va_arg(argptr, int), 1);
			if (str[i + 1] == 'c')
				ft_putchar_fd(va_arg(argptr, int), 1);
			if (str[i + 1] == '%')
				ft_putchar_fd('%', 1);
			if (str[i + 1] == 'p')
				ft_puthex((unsigned long)va_arg(argptr, void*));
			i += 2;
			continue;
		}
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (0);
}
