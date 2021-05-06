/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 20:48:55 by gaguado-          #+#    #+#             */
/*   Updated: 2021/05/05 19:05:49 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	int		i;

	i = -1;
	ret = malloc(len + 1);
	if (ft_strlen((char *)s) <= start)
		return (ret);
	if (ret != NULL)
	{
		while (++i < (int)len && s[i + start] != '\0')
			ret[i] = s[i + start];
		ret[len] = '\0';
	}
	return (ret);
}
