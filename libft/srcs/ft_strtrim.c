/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:50:59 by gaguado-          #+#    #+#             */
/*   Updated: 2021/05/05 19:05:49 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

int	charisset(char cmp, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (cmp == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		i;
	int		end;

	i = 0;
	end = ft_strlen((char *)s1) - 1;
	while (s1[i] && charisset(s1[i], set))
		i++;
	if (i != (int)ft_strlen((char *)s1))
		while (s1[end] && charisset(s1[end], set))
			end--;
	ret = malloc(end - i + 2);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1 + i, end - i + 2);
	return (ret);
}
