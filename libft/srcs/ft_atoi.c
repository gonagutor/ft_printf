/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 19:08:25 by gaguado-          #+#    #+#             */
/*   Updated: 2021/06/18 18:50:36 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *str)
{
	int		rtn;
	int		neg;
	long	icheck;

	icheck = 0;
	rtn = 0;
	neg = 1;
	while (*str == '\n' || *str == '\t' || *str == '\r' || *str == '\v'
		|| *str == '\f' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		neg = !(*str++ == '+') * -1;
	while (*str > 47 && *str < 58)
	{
		icheck = neg * ((long)rtn * 10 + (long)*str - 48);
		if (icheck > 2147483648)
			return (-1);
		else if (icheck < -2147483648)
			return (0);
		rtn = rtn * 10 + *str - 48;
		str++;
	}
	return (rtn * neg);
}
