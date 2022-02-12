/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_unsigned.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 19:01:45 by ocapers           #+#    #+#             */
/*   Updated: 2021/12/31 19:01:48 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_len_unsigned(unsigned int n)
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

char	*ft_utoa(unsigned int n)
{
	int		i;
	char	*res;
	int		sign;

	i = check_len_unsigned(n);
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

int	print_unsigned(unsigned int n)
{
	char	*message;
	int		len;

	len = 0;
	if (n < 0)
	{
		len += write (1, "-", 1);
		n *= -1;
	}
	message = ft_utoa(n);
	ft_putstr(message);
	len = ft_strlen(message);
	free (message);
	return (len);
}
