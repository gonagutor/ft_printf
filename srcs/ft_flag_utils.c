/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:27:23 by gaguado-          #+#    #+#             */
/*   Updated: 2021/02/17 14:28:54 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int			ft_print_char_repeatedly(char toprint, int times)
{
	int i;

	i = 0;
	while (i++ < times)
		ft_putchar_fd(toprint, 1);
	return (0);
}
