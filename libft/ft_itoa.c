/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:18:58 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/03/10 15:54:21 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	int_len(int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char	*edge_cases(char *str, int n)
{
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (n == -2147483648)
	{
		free (str);
		return (ft_strdup("-2147483648"));
	}
	return (0);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	i;

	i = int_len(n);
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (0);
	if (n == 0 || n == -2147483648)
		return (edge_cases(str, n));
	str[i] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		i--;
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
