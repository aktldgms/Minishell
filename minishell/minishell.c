/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akutludo <akutludo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:49:45 by akutludo          #+#    #+#             */
/*   Updated: 2025/05/11 16:40:55 by akutludo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <readline/readline.h>

int main (int argc, char **argv, char **env)
{
    printf("\n---------- THIS IS MY SHELL ----------\n\n");
    printf("this is argc: %d\n", argc);
    printf("this is argv: ");
    int i = -1;
    while (argv[++i])
    {
        if (argv[i + 1])
            printf("%s, ", argv[i]);
        else
            printf("%s\n", argv[i]);
    }
    i = -1;
    while(!ft_strnstr(env[++i], "PATH=", 5))
        ;
    printf("this is env: ");
    printf("%s\n", env[i] + 5);
    printf("\n--------------------------------------\n\n");
    i = -1;
    while(!ft_strnstr(env[++i], "USER=", 5))
        ;
    char *username = ft_strdup(env[i] + 5);
    char *line;
    while(1)
    {
        printf("%s", username);
        line = readline("@minishell$ ");
        if (!ft_strncmp(line, "exit", ft_strlen(line)))
            break;
        free(line);
    }
    free(username);
    free(line);
    return (0);
}