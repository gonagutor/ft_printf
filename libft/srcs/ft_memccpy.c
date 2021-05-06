/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:23:41 by gaguado-          #+#    #+#             */
/*   Updated: 2021/05/05 19:05:49 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memccpy(void *dest, const void *source, int c, size_t n)
{
	void	*ptr;

	ptr = ft_memchr(source, c, n);
	if (ptr == (void *) '\0')
	{
		ft_memcpy(dest, source, n);
		return ((void *) '\0');
	}
	ft_memcpy(dest, source, ptr - source + 1);
	return (dest + (ptr - source + 1));
}
