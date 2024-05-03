/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:35:08 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/03/10 13:05:49 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!str1 && !str2)
		return (0);
	while (i < n)
	{
		if (((unsigned char *)str1)[i] > ((unsigned char *)str2)[i])
			return (1);
		else if (((unsigned char *)str1)[i] < ((unsigned char *)str2)[i])
			return (-1);
		else
			i++;
	}
	return (0);
}
