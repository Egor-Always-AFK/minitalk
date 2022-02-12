/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:13:45 by ocapers           #+#    #+#             */
/*   Updated: 2021/10/22 14:13:52 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;
	size_t	size_dst;
	size_t	size_src;

	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	i = size_dst;
	k = 0;
	if (dstsize < 1)
		return (size_src);
	while (src[k] && (i < dstsize - 1))
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	if (dstsize > i)
		dst[i] = '\0';
	if (size_dst >= dstsize)
		return (dstsize + size_src);
	else
		return (size_dst + size_src);
}
