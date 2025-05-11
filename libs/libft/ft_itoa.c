/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akutludo <akutludo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:42:14 by akutludo          #+#    #+#             */
/*   Updated: 2024/10/22 20:41:29 by akutludo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit_calculate(int n)
{
	int	digit;

	if (n <= 0)
		digit = 1;
	else
		digit = 0;
	while (n != 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	int		digit;
	char	*result;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	digit = ft_digit_calculate(n);
	result = (char *)malloc(digit + 1);
	if (!result)
		return (NULL);
	result[digit] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		result[--digit] = (n % 10) + 48;
		n /= 10;
	}
	return (result);
}
