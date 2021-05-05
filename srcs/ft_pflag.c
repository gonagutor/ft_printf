/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:32:54 by gaguado-          #+#    #+#             */
/*   Updated: 2021/03/21 20:07:24 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_ppadding(t_flags flg, unsigned long num, void *ptr)
{
	int ret;

	ret = 0;
	ret += ft_print_char_repeatedly(' ', flg.flagqtt_mod - ft_ncbase(num, 16)
		- 2 - (ptr || !flg.dot_mod));
	ft_putstr_fd("0x", 1);
	ret += 2;
	ret += ft_print_char_repeatedly('0', ft_abs(flg.prec_mod)
		- ft_ncbase(num, 16) - (ptr || !flg.dot_mod));
	if (ptr || !flg.dot_mod)
	{
		ft_putnubrbase(num, 0, 16);
		ret += ft_ncbase(num, 16) + 1;
	}
	ret += ft_print_char_repeatedly(' ', (-1 * flg.flagqtt_mod) - ret
		- 1 + (ptr || !flg.dot_mod));
	return (ret);
}

int	ft_pflag(t_flags flg, va_list args)
{
	int				ret;
	unsigned long	num;
	void			*ptr;

	ret = 0;
	ptr = va_arg(args, void*);
	num = (unsigned long)ptr;
	ret += ft_ppadding(flg, num, ptr);
	return (ret);
}
