/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:33:53 by gaguado-          #+#    #+#             */
/*   Updated: 2021/05/05 19:05:49 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n == 2147483647)
	{
		ft_putstr_fd("2147483647", fd);
		return ;
	}
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n * -1, fd);
		return ;
	}
	if (n > 0)
	{
		if (n / 10 != 0)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + 48, fd);
	}
}
