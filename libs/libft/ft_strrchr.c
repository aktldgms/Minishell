/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akutludo <akutludo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:17:32 by akutludo          #+#    #+#             */
/*   Updated: 2024/10/14 16:11:32 by akutludo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	counter;

	counter = 0;
	while (*s != '\0')
	{
		counter++;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	s--;
	while (counter != 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
		counter--;
	}
	return (NULL);
}
