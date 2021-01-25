/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:25:22 by gaguado-          #+#    #+#             */
/*   Updated: 2021/01/25 17:01:50 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

/*
** This functions takes 2 strings and creates a new one that contains
** The string *strto* up to *from* + the rest of the string starting
** from *upto* + the string *strfrom*
*/
char	*ft_insert_on_position(int from, int upto, const char* strto, char* strfrom)
{
	char *ret;

	ret = malloc(ft_strlen((char*)strto) - (upto + 1 - from) + ft_strlen(strfrom));
	ft_strlcpy(ret, strto, from);
	ft_strlcpy(ret, strfrom, ft_strlen(strfrom));
	ft_strlcpy(ret, strto + upto + 1, ft_strlen((char*)strto));
	return (ret);
}

int		ft_printf(const char *str, ...)
{
	va_list argptr;
	int		i;
	char	*ret;
	char	*temp;

	ret = NULL;
	va_start(argptr, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 's')
				ret = ft_insert_on_position(i, i + 1, str, va_arg(argptr, char*));
			// TODO: Check for every single case and it's sub cases
			i++;
			continue;
		}
		temp = malloc(i + 1);
		ft_strlcpy(temp, str, i);
		if (ret)
			free(ret);
		ret = temp;
		i++;
	}
	ret[i + 1] = '\0';
	ft_putstr_fd(ret, 1);
	free(ret);
	return (0);
}
