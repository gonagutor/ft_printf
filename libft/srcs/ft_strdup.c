/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 20:01:49 by gaguado-          #+#    #+#             */
/*   Updated: 2021/05/05 19:05:49 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(char *s1)
{
	char	*ret;
	int		s1size;
	int		i;

	i = 0;
	s1size = ft_strlen(s1) + 1;
	ret = (char *)malloc(s1size);
	if (ret != NULL)
	{
		while (i < s1size)
		{
			ret[i] = s1[i];
			i++;
		}
	}
	return (ret);
}
