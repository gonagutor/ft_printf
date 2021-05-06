/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 21:23:55 by gaguado-          #+#    #+#             */
/*   Updated: 2021/05/05 19:06:20 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*temp;
	int		listlen;
	int		i;

	if (lst == NULL)
		return ;
	i = 0;
	listlen = ft_lstsize(*lst);
	cur = (*lst)->next;
	while (i < listlen - 1)
	{
		temp = cur->next;
		ft_lstdelone(cur, del);
		i++;
		cur = temp;
	}
	ft_lstdelone(*lst, del);
	*lst = NULL;
}
