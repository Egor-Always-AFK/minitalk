/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:13:45 by ocapers           #+#    #+#             */
/*   Updated: 2021/12/18 18:26:10 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}