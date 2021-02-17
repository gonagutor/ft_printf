/*
** This functions takes 2 strings and creates a new one that contains
** The string *strto* up to *from* + the rest of the string starting
** from *upto* + the string *strfrom*
** 
** char	*ft_insert_on_position(int from, int upto, const char* strto, char* strfrom)
** {
** 	char *ret;
** 
** 	ret = malloc(ft_strlen((char*)strto) - (upto + 1 - from) + ft_strlen(strfrom));
** 	ft_strlcpy(ret, strto, from + 1);
** 	ft_strlcat(ret, strfrom, ft_strlen(strfrom) + ft_strlen(ret) + 1);
** 	ft_strlcat(ret, &strto[upto + 1], ft_strlen(ret) + ft_strlen((char *)&strto[upto]) + 1);
** 	return (ret);
** }
*/

/*
	i = 0;
	helper = 0;
	spaces = 0;
	ret = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			flags = ft_read_flags(&str[i + 1]);
			va_copy(argcpy, argptr);
			spaces = ft_atoi(&str[i + 1]);
			ret += spaces;
			while (ft_isdigit(str[i + 1]))
				i++;
			if (str[i + 1] == 's')
			{
				va_copy(argcpy, argptr);
				if (va_arg(argcpy, int) == 0)
					ft_putstr_fd("(null)", 1);
				ft_print_char_repeatedly(' ', spaces);
				ft_putstr_fd(va_arg(argptr, char*), 1);
				ft_print_char_repeatedly(' ', -1 * spaces);
				ret += ft_strlen(va_arg(argcpy, char*));
			}
			if (str[i + 1] == 'd')
			{
				ft_print_char_repeatedly(' ', spaces);
				helper = va_arg(argptr, int);
				ft_putnbr_fd(helper, 1);
				ft_print_char_repeatedly(' ', -1 * spaces);
			}
			if (str[i + 1] == 'c')
			{
				ft_print_char_repeatedly(' ', spaces);
				ft_putchar_fd(va_arg(argptr, int), 1);
				ft_print_char_repeatedly(' ', -1 * spaces);
				ret++;
			}
			if (str[i + 1] == '%')
			{
				ft_print_char_repeatedly(' ', spaces);
				ft_putchar_fd('%', 1);
				ft_print_char_repeatedly(' ', -1 * spaces);
				ret++;
			}
			if (str[i + 1] == 'p')
			{
				ft_putstr_fd("0x", 1);
				ft_print_char_repeatedly(' ', spaces);
				ft_putnubrbase((unsigned long)va_arg(argptr, void*), 0, 16);
				ft_print_char_repeatedly(' ', -1 * spaces);
				ret += 10;
			}
			if (str[i + 1] == 'x')
				ft_putnubrbase(va_arg(argptr, unsigned int), 0, 16);
			if (str[i + 1] == 'X')
				ft_putnubrbase(va_arg(argptr, unsigned int), 1, 16);
			if (str[i + 1] == 'u')
				ft_putnubrbase(va_arg(argptr, unsigned int), 0, 10);
			if (str[i + 1] == 'i')
				ft_putnbr_fd(va_arg(argptr, int), 1);
			i += 2;
			continue;
		}
		ret++;
		ft_putchar_fd(str[i], 1);
		i++;
	}*/