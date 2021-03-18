/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:32:54 by gaguado-          #+#    #+#             */
/*   Updated: 2021/03/18 04:01:48 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_pflag(t_flags flg, va_list args)
{
	int				ret;
	unsigned long	num;
	void*			ptr;

	ret = 0;
	if (flg.asterisk_mod)
		flg.prec_mod = va_arg(args, int);
	ptr = va_arg(args, void*);
	num = (unsigned long)ptr;
	ret += ft_print_char_repeatedly(' ', flg.flagqtt_mod - ft_ncbase(num, 16) - 3);
	ft_putstr_fd("0x", 1);
	ret += 2;
	if (ptr && flg.dot_mod)
		ft_putnubrbase(num, 0, 16);
	ret += ft_ncbase(num, 16) - (ptr && flg.dot_mod);
	ret += ft_print_char_repeatedly(' ', (-1 * flg.flagqtt_mod) - ret - 2);
	return (ret + (num != 0 || !ptr));
}
