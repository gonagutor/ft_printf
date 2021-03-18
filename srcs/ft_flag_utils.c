/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:27:23 by gaguado-          #+#    #+#             */
/*   Updated: 2021/03/18 02:54:22 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int			ft_print_char_repeatedly(char toprint, int times)
{
	int i;

	i = 0;
	while (i++ < times)
		ft_putchar_fd(toprint, 1);
	return (i - 1);
}

int			ft_putstr_upton(const char *str, int upto)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (i < upto && str[i] != '\0')
		ft_putchar_fd(str[i++], 1);
	return (i);
}
