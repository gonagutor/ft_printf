/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 02:16:08 by gaguado-          #+#    #+#             */
/*   Updated: 2021/05/05 19:05:49 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	srcsize;

	srcsize = 0;
	if (dst == NULL && src == NULL)
		return (0);
	if (dstsize > 0)
	{
		while (srcsize < (int)dstsize - 1 && *src != '\0')
		{
			*dst = *src;
			dst++;
			src++;
			srcsize++;
		}
		*dst = '\0';
	}
	while (*src != '\0')
	{
		src++;
		srcsize++;
	}
	return (srcsize);
}
