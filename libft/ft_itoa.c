/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 21:14:32 by eshor             #+#    #+#             */
/*   Updated: 2019/09/25 21:22:42 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nbr_len(int n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char		*check_excep(int n)
{
	char *result;

	if (n == 0)
		result = ft_strdup("0");
	else
		result = (ft_strdup("-2147483648"));
	return (result);
}

char			*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		sign;

	sign = 1;
	len = nbr_len(n);
	if (n == 0 || n == -2147483648)
		return (check_excep(n));
	if (n < 0)
	{
		n = n * -1;
		sign = -1;
	}
	if (!(result = ft_strnew(len)))
		return (NULL);
	if (sign == -1)
		result[0] = '-';
	while (n > 0)
	{
		result[--len] = (char)(n % 10 + '0');
		n = n / 10;
	}
	return (result);
}
