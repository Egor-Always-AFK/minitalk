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

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size;
	size_t	idk;
	char	*dst;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	dst = malloc(sizeof(char) * (size + 1));
	if (dst == NULL)
		return (NULL);
	idk = 0;
	while (*(s + idk))
	{
		*(dst + idk) = (*f)(idk, *(s + idk));
		idk++;
	}
	*(dst + idk) = '\0';
	return (dst);
}
