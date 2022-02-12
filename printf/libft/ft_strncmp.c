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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*trash_s1;
	unsigned char	*trash_s2;
	size_t			i;

	i = 0;
	trash_s1 = (unsigned char *)s1;
	trash_s2 = (unsigned char *)s2;
	while ((trash_s1 || trash_s2) && (i < n))
	{
		if (trash_s1[i] != trash_s2[i])
			return (trash_s1[i] - trash_s2[i]);
		if ((trash_s1[i] == '\0') && (trash_s2[i] == '\0'))
			return (0);
		i++;
	}
	return (0);
}
