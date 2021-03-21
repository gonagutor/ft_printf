/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:25:22 by gaguado-          #+#    #+#             */
/*   Updated: 2021/03/21 20:28:08 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

t_flags			ft_flagchecks(const char *str, t_flags flag, va_list args, int i)
{
	int helper;

	helper = 0;
	if (str[i] == '-')
	{
		flag.minus_mod = 1;
		flag.zero_mod = 0;
	}
	if (str[i] == '0' && str[i - 1] != '.' && str[i - 1] != '0')
		flag.zero_mod = (flag.minus_mod) ? 0 : 1;
	if (str[i] == '.')
	{
		flag.dot_mod = 1;
		flag.prec_mod = ft_atoi(&str[i + 1]);
	}
	if (str[i] == '*')
	{
		flag.asterisk_mod += 1;
		if (!flag.dot_mod)
		{
			helper = va_arg(args, int);
			flag.flagqtt_mod = ((flag.minus_mod && helper > 0) ? -1 : 1) * helper;
		}
		else
			flag.prec_mod = va_arg(args, int);
	}
	return (flag);
}

static t_flags	ft_read_flags(const char *str, va_list args)
{
	t_flags next_flag;
	int		i;

	i = 0;
	ft_bzero(&next_flag, sizeof(t_flags));
	while (str[i] == '0')
	{
		next_flag.zero_mod = (next_flag.minus_mod) ? 0 : 1;
		i++;
	}
	next_flag.flagqtt_mod = ft_atoi(&str[i]);
	while (!ft_isalpha(str[i]) && str[i] != '\0' && str[i] != '%')
		next_flag = ft_flagchecks(str, next_flag, args, i++);
	if (str[i] || (str[i] == 'l' && str[i + 1]))
	{
		next_flag.long_mod = (str[i] == 'l') ? 1 : 0;
		next_flag.flag = str[i + next_flag.long_mod];
	}
	return (next_flag);
}

int				ft_flag_detection(t_flags flg, va_list args)
{
	if (flg.flag == 'c')
		return (ft_cflag(flg, args));
	if (flg.flag == 's')
		return (ft_sflag(flg, args));
	if (flg.flag == 'p')
		return (ft_pflag(flg, args));
	if (flg.flag == 'd')
		return (ft_dflag(flg, args));
	if (flg.flag == 'i')
		return (ft_dflag(flg, args));
	if (flg.flag == 'u')
		return (ft_xflag(flg, args, 1, 10));
	if (flg.flag == 'x')
		return (ft_xflag(flg, args, 0, 16));
	if (flg.flag == 'X')
		return (ft_xflag(flg, args, 1, 16));
	if (flg.flag == '%')
		return (ft_pctflag(flg));
	return (0);
}

int				ft_printf(const char *str, ...)
{
	va_list argptr;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(argptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ret += ft_flag_detection(ft_read_flags(&str[i + 1], argptr), argptr);
			i++;
			while (!ft_isalpha(str[i]) && str[i] != '%' && str[i])
				i++;
			i += (str[i]) ? 1 : 0;
			continue;
		}
		ft_putchar_fd(str[i], 1);
		i++;
		ret++;
	}
	va_end(argptr);
	return (ret);
}
