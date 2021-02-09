/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:25:22 by gaguado-          #+#    #+#             */
/*   Updated: 2021/02/03 14:34:19 by gaguado-         ###   ########.fr       */
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

char	ft_base(int i)
{
	if (i > 9)
		return (i - 10 + 97);
	return (i + 48);
}

void	ft_putnubrbase(unsigned long x, int may, int base)
{
	if (x / base > 0)
		ft_putnubrbase(x / base, may, base);
	ft_putchar_fd((may) ? ft_toupper(ft_base(x % base)) : ft_base(x % base), 1);
}

int		ft_print_char_repeatedly(char toprint, int times)
{
	int i;

	i = 0;
	while (i++ < times)
		ft_putchar_fd(toprint, 1);
	return (0);
}

int		ft_printf(const char *str, ...)
{
	va_list argptr;
	va_list argcpy;
	int		i;
	int		ret;

	va_start(argptr, str);
	i = 0;
	ret = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			va_copy(argcpy, argptr);
			ft_print_char_repeatedly(' ', ft_atoi(&str[i + 1]) - 1);
			ret += ft_atoi(&str[i + 1]) - 1;
			while (ft_isdigit(str[i + 1]))
				i++;
			if (str[i + 1] == 's')
			{
				ft_putstr_fd(va_arg(argptr, char*), 1);
				ret += ft_strlen(va_arg(argcpy, char*));
			}
			if (str[i + 1] == 'd' || str[i + 1] == 'd')
				ft_putnbr_fd(va_arg(argptr, int), 1);
			if (str[i + 1] == 'c') {
				ft_putchar_fd(va_arg(argptr, int), 1);
				ret++;
			}
			if (str[i + 1] == '%')
			{
				ft_putchar_fd('%', 1);
			}
			if (str[i + 1] == 'p')
			{
				ft_putstr_fd("0x", 1);
				ft_putnubrbase((unsigned long)va_arg(argptr, void*), 0, 16);
			}
			if (str[i + 1] == 'x')
				ft_putnubrbase(va_arg(argptr, unsigned int), 0, 16);
			if (str[i + 1] == 'X')
				ft_putnubrbase(va_arg(argptr, unsigned int), 1, 16);
			if (str[i + 1] == 'u')
				ft_putnubrbase(va_arg(argptr, unsigned int), 0, 10);
			if (str[i + 1] == 'i')
				ft_putnbr_fd(va_arg(argptr, int), 1);
			i += 2;
			continue;
		}
		ret++;
		ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(argcpy);
	va_end(argptr);
	return (ret);
}
