/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akutludo <akutludo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:54:49 by akutludo          #+#    #+#             */
/*   Updated: 2024/10/22 16:23:57 by akutludo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;

	counter = 0;
	if (dstsize > 0)
	{
		while ((counter < (dstsize - 1)) && (src[counter] != '\0'))
		{
			dst[counter] = src[counter];
			counter++;
		}
		dst[counter] = '\0';
	}
	return (ft_strlen(src));
}
