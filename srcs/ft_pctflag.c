/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pctflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:23:58 by gaguado-          #+#    #+#             */
/*   Updated: 2021/03/01 16:38:45 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_pctflag(t_flags flg)
{
	int		ret;

	ret = 1;
	ft_print_char_repeatedly(flg.zero_mod ? '0' : ' ', flg.flagqtt_mod - 1);
	ft_putchar_fd('%', 1);
	ft_print_char_repeatedly(' ', (flg.flagqtt_mod * -1) - 1);
	if (flg.flagqtt_mod > ret)
		ret += flg.flagqtt_mod - 1;
	if (flg.flagqtt_mod < ret)
		ret += -1 * flg.flagqtt_mod - 1;
	return (ret);
}
