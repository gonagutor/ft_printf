/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:15:44 by gaguado-          #+#    #+#             */
/*   Updated: 2021/05/05 19:05:49 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2));
	if (ret != NULL)
	{
		while (*s1 != '\0')
		{
			ret[i] = (char)*s1;
			i++;
			s1++;
		}
		while (*s2 != '\0')
		{
			ret[i] = (char)*s2;
			i++;
			s2++;
		}
		ret[i] = 0;
	}
	return (ret);
}
