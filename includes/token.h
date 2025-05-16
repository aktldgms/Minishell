/* ************************************************************************** */
/*                                    token.h                                 */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

/* ------ token tipleri ---------------------------------------------------- */
typedef enum e_toktype
{
	T_WORD,         /* normal kelime                                */
	T_PIPE,         /* |                                             */
	T_REDIR_IN,     /* <                                             */
	T_REDIR_OUT,    /* >                                             */
	T_APPEND,       /* >>                                            */
	T_HEREDOC       /* <<                                            */
}				t_toktype;

/* `quoted` alanı:
**  0 = değil
**  1 = çift tırnak içinde geldi ("...")
**  2 = tek  tırnak içinde geldi ('...')
*/
typedef struct s_token
{
	char			*text;      /* ham içerik (malloc’lı) */
	t_toktype		type;
	int				quoted;
	struct s_token	*next;
}				t_token;

/* --------- API ----------------------------------------------------------- */
t_token	*tok_new(char *text, t_toktype type, int quoted);
void	tok_add_back(t_token **lst, t_token *new_token);
void	tok_clear(t_token **lst);           /* bütün listeyi free’ler */

#endif
