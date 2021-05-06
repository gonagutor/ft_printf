/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:17:15 by gaguado-          #+#    #+#             */
/*   Updated: 2021/05/05 19:06:29 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_list)
{
	t_list	*list;

	if (!lst)
		return ;
	list = *lst;
	if (!list)
		*lst = new_list;
	else
	{
		list = ft_lstlast(*lst);
		list->next = new_list;
	}
}
