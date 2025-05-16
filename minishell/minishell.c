/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akutludo <akutludo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:49:45 by akutludo          #+#    #+#             */
/*   Updated: 2025/05/16 16:50:29 by akutludo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

#define CLR_WORD   "\033[0;32m"
#define CLR_OP     "\033[0;33m"
#define CLR_RESET  "\033[0m"

static const char *tok_name(t_toktype t)
{
	if (t == T_WORD)       return "WORD";
	if (t == T_PIPE)       return "PIPE";
	if (t == T_REDIR_IN)   return "RD_IN";
	if (t == T_REDIR_OUT)  return "RD_OUT";
	if (t == T_APPEND)     return "APPEND";
	if (t == T_HEREDOC)    return "HEREDOC";
	return "UNK";
}

static void	print_tokens(t_token *lst)
{
	while (lst)
	{
		const char *clr = (lst->type == T_WORD) ? CLR_WORD : CLR_OP;
		printf("%s%-8s%s : \"%s\"\n",
			   clr, tok_name(lst->type), CLR_RESET, lst->text);
		lst = lst->next;
	}
}

int	main(void)
{
	char	*line;
	t_token	*tokens;

	while (1)
	{
		line = readline("minishell> ");
		if (!line)
		{
			printf("exit\n");
			break;
		}
		if (*line)
			add_history(line);

		tokens = lexer(line);
		if (!tokens)
			fprintf(stderr, "lexer error (quote/escape?)\n");
		else
			print_tokens(tokens);

		tok_clear(&tokens);
		free(line);
	}
	return (0);
}
