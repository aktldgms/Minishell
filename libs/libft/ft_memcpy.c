/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akutludo <akutludo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:29:52 by akutludo          #+#    #+#             */
/*   Updated: 2024/10/22 16:21:49 by akutludo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr_d;
	unsigned char	*ptr_s;

	if (!dst && !src)
		return (NULL);
	ptr_d = (unsigned char *)dst;
	ptr_s = (unsigned char *)src;
	while (n--)
	{
		*ptr_d = *ptr_s;
		ptr_d++;
		ptr_s++;
	}
	return (dst);
}
