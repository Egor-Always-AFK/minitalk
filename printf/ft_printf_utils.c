/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 19:02:15 by ocapers           #+#    #+#             */
/*   Updated: 2021/12/31 19:02:15 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		len;
	char	*message;

	len = 0;
	message = ft_itoa(n);
	len = ft_putstr(message);
	free (message);
	return (len);
}

int	ft_putstr(char *c)
{
	int	i;

	i = 0;
	if (c == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
	return (i);
}

void	print_lowcase_hex(unsigned int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n >= 16)
	{
		print_lowcase_hex(n / 16);
		print_lowcase_hex(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'a');
	}
}

void	print_upcase_hex(unsigned int n)
{
	if (n < 0)
	{
		write (1, "-", 1);
		n *= -1;
	}
	if (n >= 16)
	{
		print_upcase_hex(n / 16);
		print_upcase_hex(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'A');
	}
}

int	choise_case_hex(unsigned int n, char arg)
{
	if (arg == 'X')
		print_upcase_hex(n);
	else
		print_lowcase_hex(n);
	return (ptr_len(n));
}
