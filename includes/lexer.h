/* ************************************************************************** */
/*                                   lexer.h                                  */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../includes/minishell.h"

/* ------------------- LEXER durum makinesi sabitleri ---------------------- */
typedef enum e_lex_state
{
	S_DEFAULT = 0,   /* dışarıdayız, boşluk/operatör ayırıcı */
	S_IN_SQ,         /* 'tek tırnak' içindeyiz */
	S_IN_DQ,         /* "çift tırnak" içindeyiz */
	S_ESC            /* '\' kaçıştan sonraki tek karakter */
}	t_lex_state;

/* ------------------- Kullanıma açık fonksiyonlar ------------------------- */
t_token	*lexer(char *line);        /* giriş satırını token listesine çevirir   */
void	str_append(char **buf, char c); /* dinamik buffer’a 1 karakter ekler   */

#endif /* LEXER_H */
