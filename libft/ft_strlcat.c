/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:18:36 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/03/09 13:44:38 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	len_src;
	size_t	len_dest;

	if (!dest || !src)
		return (0);
	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	if (n <= len_dest)
		return (len_src + n);
	else
	{
		dest = dest + len_dest;
		ft_strlcpy(dest, src, n - len_dest);
		return (len_src + len_dest);
	}
}
