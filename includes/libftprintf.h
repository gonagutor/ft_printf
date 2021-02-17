/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:17:20 by gaguado-          #+#    #+#             */
/*   Updated: 2021/02/17 14:26:06 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_flags
{
	int		zero_mod;
	int		flagqtt_mod;
	int		dot_mod;
	int		asterisk_mod;
	int		long_mod;
	char	flag;
}				t_flags;

int				ft_cflag(t_flags flg, va_list args);
int				ft_print_char_repeatedly(char toprint, int times);
int				ft_flag_detection(t_flags flg, va_list args);
char			ft_base(int i);
void			ft_putnubrbase(unsigned long x, int may, int base);
int				ft_printf(const char *str, ...);

#endif