/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:22:07 by gaguado-          #+#    #+#             */
/*   Updated: 2021/05/05 19:06:26 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new_list)
{
	if (alst == NULL)
		return ;
	new_list->next = *alst;
	*alst = new_list;
}
