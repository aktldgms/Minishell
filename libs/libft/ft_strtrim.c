/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akutludo <akutludo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:20:55 by akutludo          #+#    #+#             */
/*   Updated: 2024/10/22 19:30:47 by akutludo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	char	*result;

	while (*s1 != '\0' && ft_strchr(set, *s1))
		s1++;
	s1_len = ft_strlen(s1);
	while (s1_len && s1[s1_len - 1] && ft_strchr(set, s1[s1_len - 1]))
		s1_len--;
	result = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, s1_len);
	result[s1_len] = '\0';
	return (result);
}
