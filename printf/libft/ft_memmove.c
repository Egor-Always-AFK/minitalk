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

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*trash_dst;
	char	*trash_src;

	if ((dst == NULL) && (src == NULL))
		return (0);
	trash_dst = (char *)dst;
	trash_src = (char *)src;
	if (trash_dst < trash_src)
		while (len--)
			*trash_dst++ = *trash_src++;
	else
	{
		trash_dst += len;
		trash_src += len;
		while (len--)
			*--trash_dst = *--trash_src;
	}
	return (dst);
}
