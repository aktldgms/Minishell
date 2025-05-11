/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akutludo <akutludo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:34:29 by akutludo          #+#    #+#             */
/*   Updated: 2024/10/22 20:43:51 by akutludo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;

	result = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (result)
	{
		ft_strlcpy(result, s1, ft_strlen(s1) + 1);
		return (result);
	}
	return (NULL);
}
