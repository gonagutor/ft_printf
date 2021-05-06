/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 21:41:29 by gaguado-          #+#    #+#             */
/*   Updated: 2021/05/05 19:05:49 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*string1;
	char	*string2;
	int		i;

	string1 = (char *)s1;
	string2 = (char *)s2;
	i = 0;
	while (string1 != NULL && string2 != NULL && i < (int)n - 1)
	{
		if (*string1 != *string2)
			break ;
		string1++;
		string2++;
		i++;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)string1 - *(unsigned char *)string2);
}
