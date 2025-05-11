/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akutludo <akutludo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 22:11:29 by akutludo          #+#    #+#             */
/*   Updated: 2024/10/19 22:24:01 by akutludo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	int		size;
	t_list	*ptr;

	ptr = *lst;
	size = ft_lstsize(*lst);
	while (size--)
	{
		ptr = *lst;
		del((*lst)->content);
		*lst = (*lst)->next;
		free(ptr);
	}
	*lst = NULL;
}
