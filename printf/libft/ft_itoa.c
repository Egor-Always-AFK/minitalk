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

static int	check_len_int(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*res;
	int		sign;

	i = check_len_int(n);
	sign = 1;
	res = malloc(sizeof(char) * i + 1 + (n < 0));
	if (res == NULL)
		return (NULL);
	ft_bzero(res, i + 2);
	if (n < 0)
	{
		res[0] = '-';
		sign *= -1;
		i += 1;
	}
	if (n == 0)
		res[0] = '0';
	while (n)
	{
		res[--i] = (n % 10) * sign + '0';
		n /= 10;
	}
	return (res);
}
