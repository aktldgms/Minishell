/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akutludo <akutludo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:47:27 by akutludo          #+#    #+#             */
/*   Updated: 2025/05/16 16:47:29 by akutludo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void flush_buf(t_token **lst, char **buf, int quoted)
{
	if (*buf && **buf)
	{
		tok_add_back(lst, tok_new(*buf, T_WORD, quoted));
	}
	free(*buf);
	*buf = NULL;
}

void	str_append(char **buf, char c)
{
	char	*new;
	size_t	len;

	if (!buf)
		return ;
	if (!*buf)
	{
		*buf = malloc(2);
		if (!*buf)
			return ;
		(*buf)[0] = c;
		(*buf)[1] = '\0';
		return ;
	}
	len = strlen(*buf);
	new = malloc(len + 2);
	if (!new)
		return ;
	memcpy(new, *buf, len);
	new[len] = c;
	new[len + 1] = '\0';
	free(*buf);
	*buf = new;
}

static t_token	*lex_word(char *line)
{
	size_t	i = 0;
	int		state = S_DEFAULT;
	char	*buf = NULL;
	t_token	*list = NULL;

	while (line[i])
	{
		char c = line[i];
		if (state == S_ESC)
		{ str_append(&buf, c); state = S_DEFAULT; }
		else if (c == '\\' && state != S_IN_SQ)
			state = S_ESC;
		else if (c == '\'' && state == S_DEFAULT)
			state = S_IN_SQ;
		else if (c == '\'' && state == S_IN_SQ)
			state = S_DEFAULT;
		else if (c == '"'  && state == S_DEFAULT)
			state = S_IN_DQ;
		else if (c == '"'  && state == S_IN_DQ)
			state = S_DEFAULT;
		else if ((c == ' ' || c == '\t') && state == S_DEFAULT)
			flush_buf(&list, &buf, 0);
		else if ((c == '|' || c == '<' || c == '>') && state == S_DEFAULT)
		{
			flush_buf(&list, &buf, 0);
			if ((c == '>' && line[i+1] == '>') || (c == '<' && line[i+1] == '<'))
			{
				tok_add_back(&list, tok_new(c == '>' ? ">>" : "<<",
								c == '>' ? T_APPEND : T_HEREDOC, 0));
				i++;
			}
			else
				tok_add_back(&list, tok_new((c=='|')?"|":(c=='>')?">":"<",
								c=='|'?T_PIPE:(c=='>'?T_REDIR_OUT:T_REDIR_IN), 0));
		}
		else
			str_append(&buf, c);
		i++;
	}
	if (state == S_IN_SQ || state == S_IN_DQ || state == S_ESC)
		return (tok_clear(&list), NULL);
	flush_buf(&list, &buf, 0);
	return (list);
}

t_token	*lexer(char *line)
{
	if (!line)
		return (NULL);
	return (lex_word(line));
}
