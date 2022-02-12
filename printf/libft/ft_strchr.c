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

char	*ft_strchr(const char *s, int c)
{
	char	*trash_s;
	char	trash_c;

	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	trash_s = (char *)s;
	trash_c = (char)c;
	while (*trash_s)
	{
		if (*trash_s == trash_c)
			return ((char *)trash_s);
		trash_s++;
	}
	return (0);
}
