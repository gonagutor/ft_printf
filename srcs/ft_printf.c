/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:25:22 by gaguado-          #+#    #+#             */
/*   Updated: 2021/02/17 14:28:28 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

static t_flags	ft_read_flags(const char *str)
{
	t_flags next_flag;
	int		i;

	i = 0;
	ft_bzero(&next_flag, sizeof(t_flags));
	next_flag.flagqtt_mod = ft_atoi(&str[i]);
	while (!ft_isalpha(str[i]) && str[i] != '\0')
	{
		if (str[i] == '0')
			next_flag.zero_mod = 1;
		else
		{
			while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
				i++;
			continue;
		}
		if (str[i] == '.')
			next_flag.dot_mod = 1;
		if (str[i] == '*')
			next_flag.asterisk_mod = 1;
		i++;
	}
	next_flag.long_mod = (str[i] == 'l') ? 1 : 0;
	next_flag.flag = str[(next_flag.long_mod) ? i + 1 : i];
	return (next_flag);
}

int				ft_flag_detection(t_flags flg, va_list args)
{
	if (flg.flag == 'c')
		return (ft_cflag(flg, args));
	if (flg.flag == 'p')
	{
		ft_print_char_repeatedly(' ', flg.flagqtt_mod);
		ft_putstr_fd("0x", 1);
		ft_putnubrbase((unsigned long)va_arg(args, void*), 0, 16);
		ft_print_char_repeatedly(' ', -1 * flg.flagqtt_mod);
	}
	return (0);
}

int				ft_printf(const char *str, ...)
{
	va_list argptr;
	int i;
	int ret;

	i = 0;
	ret = 0;
	va_start(argptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ret += ft_flag_detection(ft_read_flags(&str[i + 1]), argptr);
			while (!ft_isalpha(str[i]))
				i++;
			i++;
			continue;
		}
		ft_putchar_fd(str[i], 1);
		i++;
		ret++;
	}
	va_end(argptr);
	return (ret);
}
