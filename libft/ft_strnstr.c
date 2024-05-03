/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:17:17 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/03/07 00:11:25 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *b, const char *l, size_t n)
{
	size_t	i;
	size_t	j;
	char	*big;

	big = (char *)b;
	i = 0;
	if (l[0] == '\0')
		return (big);
	if (n == 0)
		return (0);
	while (big[i] != '\0' && i < n)
	{
		j = 0;
		while (big[i + j] == l[j] && i + j < n)
		{
			if (l[j + 1] == '\0')
				return (big + i);
			j++;
		}
		i++;
	}
	return (0);
}
