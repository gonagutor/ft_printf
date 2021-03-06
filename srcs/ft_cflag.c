/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:09:46 by gaguado-          #+#    #+#             */
/*   Updated: 2021/06/10 13:34:14 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_cflag(t_flags flg, va_list args)
{
	ft_pcr(' ', flg.flagqtt_mod - 1);
	ft_putchar_fd((char)va_arg(args, int), 1);
	ft_pcr(' ', (-1 * flg.flagqtt_mod) - 1);
	if (!flg.flagqtt_mod && !flg.zero_mod)
		return (1);
	if (flg.flagqtt_mod < 0)
		return (flg.flagqtt_mod * -1);
	else
		return (flg.flagqtt_mod);
}
