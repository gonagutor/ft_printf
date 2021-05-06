/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 10:14:55 by gaguado-          #+#    #+#             */
/*   Updated: 2021/05/05 19:06:14 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	find_words(char const *s, char c)
{
	int	i;
	int	x;

	i = -1;
	x = 0;
	while (s[++i])
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			x++;
	return (x);
}

char	*extract_word(const char *s1, char c, int *index)
{
	char	*dst;
	int		i;
	int		len;

	len = 0;
	while (s1[len] && s1[len] != c)
		len++;
	dst = (char *)malloc((len + 1) * sizeof(char));
	if (!dst)
		return (0);
	i = -1;
	while (++i < len)
		dst[i] = s1[i];
	dst[i] = '\0';
	(*index) += len - 1;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		z;
	char	**data_array;
	int		wcount;

	wcount = find_words(s, c);
	data_array = (char **)malloc((wcount + 1) * sizeof(char *));
	if (!data_array)
		return (0);
	z = 0;
	i = -1;
	while (s[++i])
		if ((i == 0 && s[i] != c) || (i != 0 && s[i] != c && s[i - 1] == c))
			data_array[z++] = extract_word(&s[i], c, &i);
	data_array[z] = 0;
	return (data_array);
}
