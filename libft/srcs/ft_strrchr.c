/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 01:36:03 by gaguado-          #+#    #+#             */
/*   Updated: 2020/10/04 17:11:12 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *ptr;

	ptr = (char*)'\0';
	while (*str != '\0')
	{
		if (*str == (char)c)
			ptr = (char*)str;
		str++;
	}
	return (c == 0) ? (char*)str : ptr;
}
