/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akutludo <akutludo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:40:20 by akutludo          #+#    #+#             */
/*   Updated: 2024/10/22 21:35:41 by akutludo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result_list;
	t_list	*new_node;
	void	*content;

	if (!lst || !f)
		return (NULL);
	result_list = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			if (content)
				del(content);
			ft_lstclear(&result_list, del);
			return (NULL);
		}
		ft_lstadd_back(&result_list, new_node);
		lst = lst->next;
	}
	return (result_list);
}
