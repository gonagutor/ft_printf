/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:32:54 by gaguado-          #+#    #+#             */
/*   Updated: 2021/03/18 20:44:32 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_pflag(t_flags flg, va_list args)
{
	int				ret;
	unsigned long	num;
	void*			ptr;

	ret = 0;
	if ((flg.asterisk_mod && ((!flg.dot_mod || flg.prec_mod)
		|| flg.asterisk_mod >= 2)))
		flg.flagqtt_mod = va_arg(args, int);
	if ((flg.asterisk_mod && flg.prec_mod == 0 && flg.dot_mod) ||
		flg.asterisk_mod >= 2)
		flg.prec_mod = va_arg(args, int);
	ptr = va_arg(args, void*);
	num = (unsigned long)ptr;
	ret += ft_print_char_repeatedly(' ', flg.flagqtt_mod - ft_ncbase(num, 16)
		- 2 - (ptr || !flg.dot_mod));
	ft_putstr_fd("0x", 1);
	ret += 2;
	ret += ft_print_char_repeatedly('0', ft_abs(flg.prec_mod)
		- ft_ncbase(num, 16) - (ptr || !flg.dot_mod));
	if (ptr || !flg.dot_mod) {
		ft_putnubrbase(num, 0, 16);
		ret += ft_ncbase(num, 16) + 1;
	}
	ret += ft_print_char_repeatedly(' ', (-1 * flg.flagqtt_mod) - ret
		- 1 + (ptr || !flg.dot_mod));
	return (ret);
}
