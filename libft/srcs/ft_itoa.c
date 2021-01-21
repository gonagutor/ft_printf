/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 14:10:52 by gaguado-          #+#    #+#             */
/*   Updated: 2020/10/04 19:33:01 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	power(int n, int p)
{
	int		i;
	long	ret;

	ret = 1;
	i = 0;
	while (p > i)
	{
		ret *= n;
		i++;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		i;
	int		z;
	long	temp;
	int		neg;

	i = 1;
	z = -1;
	neg = (n < 0) ? -1 : 1;
	temp = (-2147483647 - 1 == n) ? 2147483648 : n * neg;
	while (temp / power(10, i) > 0)
		++i;
	ret = malloc((neg == -1) ? i + 2 : i + 1);
	if (ret == NULL)
		return (NULL);
	if (neg == -1)
		ret[++z] = '-';
	while (--i + 1 > 0)
	{
		ret[++z] = temp / power(10, i) + 48;
		temp = temp % power(10, i);
	}
	ret[z + 1] = '\0';
	return (ret);
}
