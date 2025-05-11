/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akutludo <akutludo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:28:43 by akutludo          #+#    #+#             */
/*   Updated: 2024/10/22 16:21:38 by akutludo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!src && !dst)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d > s)
	{
		d += len;
		s += len;
		while (len--)
			*(--d) = *(--s);
	}
	else
	{
		while (len--)
			*d++ = *s++;
	}
	return (dst);
}
