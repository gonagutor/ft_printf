/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pctflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:23:58 by gaguado-          #+#    #+#             */
/*   Updated: 2021/05/17 12:40:22 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_pctflag(t_flags flg)
{
	int		ret;

	ret = 1;
	if (flg.zero_mod)
		ret += ft_pcrepeatedly('0', flg.flagqtt_mod - 1);
	else
		ret += ft_pcrepeatedly(' ', flg.flagqtt_mod - 1);
	ft_putchar_fd('%', 1);
	ret += ft_pcrepeatedly(' ', (flg.flagqtt_mod * -1) - 1);
	return (ret);
}
