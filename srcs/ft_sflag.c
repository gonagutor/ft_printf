/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:33:08 by gaguado-          #+#    #+#             */
/*   Updated: 2021/05/05 18:24:12 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_spadding(t_flags flg, char *str)
{
	int	ret;

	ret = 0;
	if (flg.minus_mod && flg.flagqtt_mod > 0)
		flg.flagqtt_mod *= -1;
	if (flg.dot_mod && flg.prec_mod > -1)
	{
		if ((int)ft_strlen(str) < flg.prec_mod)
			ret += ft_print_char_repeatedly(' ', flg.flagqtt_mod
					- ft_strlen(str));
		else
			ret += ft_print_char_repeatedly(' ', flg.flagqtt_mod
					- flg.prec_mod);
		ret += ft_putstr_upton(str, flg.prec_mod);
	}
	else
	{
		if (flg.zero_mod)
			ret += ft_print_char_repeatedly('0',
					flg.flagqtt_mod - ft_strlen(str));
		else
			ret += ft_print_char_repeatedly(' ',
					flg.flagqtt_mod - ft_strlen(str));
		ret += ft_putstr_upton(str, ft_strlen(str));
	}
	ret += ft_print_char_repeatedly(' ', (-1 * flg.flagqtt_mod) - ret);
	return (ret);
}

int	ft_sflag(t_flags flg, va_list args)
{
	int		ret;
	char	*str;

	ret = 0;
	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)\0";
	ret += ft_spadding(flg, str);
	return (ret);
}
