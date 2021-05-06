/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 21:53:50 by gaguado-          #+#    #+#             */
/*   Updated: 2021/05/05 19:05:49 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	int		nlen;

	if (!*n)
		return ((char *)h);
	nlen = (int)ft_strlen((char *)n);
	while (*h)
	{
		if (*h == *n && !ft_strncmp((char *)h, (char *)n, nlen))
			return ((char *)h);
		h++;
		if (nlen >= (int)len--)
			break ;
	}
	return (NULL);
}
