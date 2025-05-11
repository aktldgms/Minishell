/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akutludo <akutludo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:35:14 by akutludo          #+#    #+#             */
/*   Updated: 2024/10/14 15:32:52 by akutludo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*string;
	size_t	i;
	size_t	str_len;
	size_t	max_len;

	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	max_len = str_len - start;
	if (len > max_len)
		len = max_len;
	string = malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		string[i] = s[start + i];
		i++;
	}
	string[i] = '\0';
	return (string);
}
