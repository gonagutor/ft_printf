/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:33:08 by gaguado-          #+#    #+#             */
/*   Updated: 2021/03/01 12:26:42 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_sflag(t_flags flg, va_list args)
{
	int		ret;
	char	*str;

	ret = 0;
	if (flg.asterisk_mod)
		flg.prec_mod = va_arg(args, int);
	str = va_arg(args, char*);
	if (str == NULL)
		str = "(null)\0";
	if (flg.dot_mod && flg.prec_mod > -1)
	{
		if ((int)ft_strlen(str) < flg.prec_mod)
			ft_print_char_repeatedly(' ', flg.flagqtt_mod - ft_strlen(str));
		else
			ft_print_char_repeatedly(' ', flg.flagqtt_mod - flg.prec_mod);
		ret += ft_putstr_upton(str, flg.prec_mod);
	}
	else
	{
		ft_print_char_repeatedly(' ', flg.flagqtt_mod - ft_strlen(str));
		ret += ft_putstr_upton(str, ft_strlen(str));
	}
	ft_print_char_repeatedly(' ', (-1 * flg.flagqtt_mod) - ret);
	return (ret + flg.flagqtt_mod);
}
