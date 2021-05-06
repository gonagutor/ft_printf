/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 21:07:38 by gaguado-          #+#    #+#             */
/*   Updated: 2021/05/05 19:05:49 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char	*s1;
	char	*s2;

	s1 = (char *)str1;
	s2 = (char *)str2;
	if (str1 == NULL && str2 == NULL)
		return (str1);
	if (s1 > s2)
	{
		s1 = s1 + n - 1;
		s2 = s2 + n - 1;
		while (n > 0)
		{
			*s1 = *s2;
			s1--;
			s2--;
			n--;
		}
	}
	else
	{
		while (n-- > 0)
			*s1++ = *s2++;
	}
	return (str1);
}
