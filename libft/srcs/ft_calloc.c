/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 19:43:22 by gaguado-          #+#    #+#             */
/*   Updated: 2021/05/05 19:07:12 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	int		i;

	i = -1;
	ret = malloc(count * size);
	if (ret == NULL)
		return ((void *) '\0');
	while (++i < ((int)size * (int)count))
		((char *)ret)[i] = '\0';
	return (ret);
}
