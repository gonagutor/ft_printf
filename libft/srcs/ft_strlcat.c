/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 01:46:27 by gaguado-          #+#    #+#             */
/*   Updated: 2021/05/05 19:05:49 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int	i;
	int	z;
	int	y;

	z = 0;
	i = 0;
	y = 0;
	while (dst[i] != '\0' && i < (int)dstsize)
		i++;
	while (src[z] != '\0' && (z + i + 1) < (int)dstsize)
	{
		dst[i + z] = src[z];
		z++;
	}
	if (i < (int)dstsize)
		dst[i + z] = '\0';
	while (src[y] != '\0')
		y++;
	return (i + y);
}
