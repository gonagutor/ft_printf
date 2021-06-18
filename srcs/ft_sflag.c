/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:33:08 by gaguado-          #+#    #+#             */
/*   Updated: 2021/06/10 13:34:14 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_spadding(t_flags flg, char *str)
{
	int	ret;
	int	len;

	len = (int)ft_strlen(str);
	ret = 0;
	if (flg.minus_mod && flg.flagqtt_mod > 0)
		flg.flagqtt_mod *= -1;
	if (flg.dot_mod && flg.prec_mod > -1)
	{
		if (len < flg.prec_mod)
			ret += ft_pcr(' ', flg.flagqtt_mod - len);
		else
			ret += ft_pcr(' ', flg.flagqtt_mod - flg.prec_mod);
		ret += ft_putstr_upton(str, flg.prec_mod);
	}
	else
	{
		if (flg.zero_mod)
			ret += ft_pcr('0', flg.flagqtt_mod - len);
		else
			ret += ft_pcr(' ', flg.flagqtt_mod - len);
		ret += ft_putstr_upton(str, len);
	}
	ret += ft_pcr(' ', (-1 * flg.flagqtt_mod) - ret);
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
