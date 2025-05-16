/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akutludo <akutludo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:48:12 by akutludo          #+#    #+#             */
/*   Updated: 2025/05/16 16:48:39 by akutludo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../includes/minishell.h"

typedef enum e_lex_state
{
	S_DEFAULT = 0,   /* dışarıdayız, boşluk/operatör ayırıcı */
	S_IN_SQ,         /* 'tek tırnak' içindeyiz */
	S_IN_DQ,         /* "çift tırnak" içindeyiz */
	S_ESC            /* '\' kaçıştan sonraki tek karakter */
}	t_lex_state;

t_token	*lexer(char *line);
void	str_append(char **buf, char c);

#endif /* LEXER_H */
