/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:32:54 by gaguado-          #+#    #+#             */
/*   Updated: 2021/03/03 14:19:23 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_pflag(t_flags flg, va_list args)
{
	int				ret;
	unsigned long	num;

	ret = 0;
	if (flg.asterisk_mod)
		flg.prec_mod = va_arg(args, int);
	num = (unsigned long)va_arg(args, void*);
	ft_print_char_repeatedly(' ', flg.flagqtt_mod - ft_ncbase(num, 16) - 3);
	ft_putstr_fd("0x", 1);
	ret += 2;
	ret += ft_putnubrbase(num, 0, 16) - 1;
	ft_print_char_repeatedly(' ', (-1 * flg.flagqtt_mod) - ret - 2);
	if (flg.flagqtt_mod > ret)
		ret += flg.flagqtt_mod - ret;
	if (flg.flagqtt_mod < ret)
		ret += -1 * flg.flagqtt_mod + ret;
	return (ret);
}
