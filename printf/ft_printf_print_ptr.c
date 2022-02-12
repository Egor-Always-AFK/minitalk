/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_ptr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 19:00:17 by ocapers           #+#    #+#             */
/*   Updated: 2021/12/31 19:01:35 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_len(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

int	print_ptr(unsigned long long n)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n >= 16)
	{
		print_ptr(n / 16);
		print_ptr(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'a');
	}
	return (0);
}

int	put_ptr(unsigned long long n)
{
	int	len;

	len = ptr_len(n);
	print_ptr (n);
	return (len);
}
