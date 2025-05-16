/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akutludo <akutludo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:47:17 by akutludo          #+#    #+#             */
/*   Updated: 2025/05/16 16:47:19 by akutludo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*tok_strdup(const char *s)
{
	size_t	i = 0;
	while (s[i])
		++i;
	char *dup = malloc(i + 1);
	if (!dup)
		return (NULL);
	for (size_t j = 0; j < i; j++)
		dup[j] = s[j];
	dup[i] = '\0';
	return (dup);
}

t_token	*tok_new(char *text, t_toktype type, int quoted)
{
	t_token	*node;

	node = malloc(sizeof(t_token));
	if (!node)
		return (NULL);
	node->text = tok_strdup(text);
	if (!node->text)
		return (free(node), NULL);
	node->type = type;
	node->quoted = quoted;
	node->next = NULL;
	return (node);
}

void	tok_add_back(t_token **lst, t_token *new_token)
{
	t_token	*tmp;

	if (!lst || !new_token)
		return ;
	if (!*lst)
	{
		*lst = new_token;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_token;
}

void	tok_clear(t_token **lst)
{
	t_token	*tmp;

	while (lst && *lst)
	{
		tmp = (*lst)->next;
		free((*lst)->text);
		free(*lst);
		*lst = tmp;
	}
}
