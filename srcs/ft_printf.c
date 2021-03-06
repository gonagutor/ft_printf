/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:25:22 by gaguado-          #+#    #+#             */
/*   Updated: 2021/06/10 13:59:55 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

t_flags	ft_flagchecks(const char *str, t_flags flg, va_list rgs, int i)
{
	int	helper;

	helper = 0;
	if (str[i] == '-')
		flg.minus_mod = 1;
	if (str[i] == '0' && str[i - 1] != '.' && str[i - 1] != '0')
		flg.zero_mod = !flg.minus_mod;
	if (str[i] == '.')
	{
		flg.dot_mod = 1;
		flg.prec_mod = ft_atoi(&str[i + 1]);
	}
	if (str[i] == '*')
	{
		flg.asterisk_mod += 1;
		if (!flg.dot_mod)
		{
			flg.flagqtt_mod = va_arg(rgs, int);
			if (flg.minus_mod && flg.flagqtt_mod > 0)
				flg.flagqtt_mod *= -1;
		}
		else
			flg.prec_mod = va_arg(rgs, int);
	}
	return (flg);
}

static t_flags	ft_read_flags(const char *str, va_list args)
{
	t_flags	next_flag;
	int		i;

	i = 0;
	ft_bzero(&next_flag, sizeof(t_flags));
	while (str[i] == '0')
	{
		next_flag.zero_mod = !next_flag.minus_mod;
		i++;
	}
	next_flag.flagqtt_mod = ft_atoi(&str[i]);
	while (!ft_isalpha(str[i]) && str[i] != '\0' && str[i] != '%')
		next_flag = ft_flagchecks(str, next_flag, args, i++);
	if (str[i] || (str[i] == 'l' && str[i + 1]))
	{
		next_flag.long_mod = (str[i] == 'l');
		next_flag.flag = str[i + next_flag.long_mod];
	}
	return (next_flag);
}

int	ft_flag_detection(t_flags flg, va_list args)
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

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ret += ft_flag_detection(ft_read_flags(&str[i + 1], args), args);
			i++;
			while (!ft_isalpha(str[i]) && str[i] != '%' && str[i])
				i++;
			i += (str[i] != '\0');
			continue ;
		}
		ft_putchar_fd(str[i], 1);
		i++;
		ret++;
	}
	va_end(args);
	return (ret);
}
