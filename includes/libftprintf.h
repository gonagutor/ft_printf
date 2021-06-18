/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:17:20 by gaguado-          #+#    #+#             */
/*   Updated: 2021/06/10 13:34:14 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_flags
{
	int		zero_mod;
	int		flagqtt_mod;
	int		dot_mod;
	int		asterisk_mod;
	int		long_mod;
	int		prec_mod;
	int		minus_mod;
	char	flag;
}				t_flags;

int				ft_pcr(char toprint, int times);
int				ft_flag_detection(t_flags flg, va_list args);
char			ft_base(int i);
int				ft_putnubrbase(unsigned long x, int may, int base);
int				ft_ncbase(unsigned long x, int base);
int				ft_ncsigned(long x);
int				ft_putstr_upton(const char *str, int upto);
int				ft_putnubrbase(unsigned long x, int may, int base);
long			ft_abs(long x);
int				ft_sflag(t_flags flg, va_list args);
int				ft_cflag(t_flags flg, va_list args);
int				ft_pflag(t_flags flg, va_list args);
int				ft_dflag(t_flags flg, va_list args);
int				ft_xflag(t_flags flg, va_list args, int mayus, int base);
int				ft_pctflag(t_flags flg);
int				ft_printf(const char *str, ...);

#endif
