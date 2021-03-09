/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:34:52 by gaguado-          #+#    #+#             */
/*   Updated: 2021/03/09 16:28:51 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_xflag(t_flags flg, va_list args, int mayus)
{
	int				ret;
	unsigned long	num;
	int				zeros;
	int				spaces;

	ret = 0;
	if (flg.asterisk_mod)
		flg.prec_mod = va_arg(args, int);
	num = (unsigned long)va_arg(args, void*);
	spaces = (int)(num != 0 || flg.dot_mod == 0);
	zeros = ft_abs(flg.prec_mod) - ft_ncbase(num, 16) - spaces;
	if (ft_abs(flg.prec_mod) <= ft_ncbase(num, 16) && flg.dot_mod)
		spaces = flg.flagqtt_mod - ft_abs(flg.prec_mod) - spaces;
	else
		spaces = flg.flagqtt_mod - ft_abs(ft_abs(flg.prec_mod) - ft_ncbase(num, 16)) - spaces;
	ret += zeros + ((spaces < 0) ? -spaces - (flg.flagqtt_mod * -1) : spaces);
	ft_print_char_repeatedly((flg.zero_mod && !flg.dot_mod) ? '0' : ' ', spaces);
	if (flg.dot_mod)
		ft_print_char_repeatedly('0', zeros);
	if (num != 0 || flg.dot_mod == 0)
		ret += ft_putnubrbase(num, mayus, 16);
	if (ft_abs(flg.prec_mod) <= ft_ncbase(num, 16) && flg.dot_mod)
		spaces = (flg.flagqtt_mod * -1) - ft_abs(flg.prec_mod) - (num != 0 || flg.dot_mod == 0);
	else
		spaces = (flg.flagqtt_mod * -1) - ft_abs(ft_abs(flg.prec_mod) - ft_ncbase(num, 16)) - (num != 0 || flg.dot_mod == 0);
	ft_print_char_repeatedly(' ', spaces);
	ret += (-1 * flg.flagqtt_mod) - ft_ncbase(num, 16);
	return (ret);
}
