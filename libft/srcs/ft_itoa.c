/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 14:10:52 by gaguado-          #+#    #+#             */
/*   Updated: 2021/05/10 13:04:01 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_charcounter(int n)
{
	int	ret;

	ret = 0;
	if (n / 10 > 0)
		ret += ft_charcounter(n / 10) + 1;
	if (ret == 0 && n == 0)
		return (0);
	else
		return (ret);
}

char	*ft_itoa(int n)
{
	int		neg;
	size_t	len;
	char	*tab;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = (n < 0);
	if (neg)
		n *= -1;
	len = ft_charcounter(n);
	tab = (char *)malloc(len + neg + 1);
	if (!tab)
		return (NULL);
	tab[len + neg] = '\0';
	while (len > 0)
	{
		tab[--len + neg] = n % 10 + 48;
		n /= 10;
	}
	if (neg)
		tab[0] = '-';
	return (tab);
}
