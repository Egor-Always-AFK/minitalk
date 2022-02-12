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
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);

int		check_arg(va_list arguments, const char arg);

int		print_percent(void);

int		print_unsigned(unsigned int n);

void	print_lowcase_hex(unsigned int n);

void	print_upcase_hex(unsigned int n);

int		print_ptr(unsigned long long n);

int		ft_putnbr(int n);

int		ft_putchar(char c);

int		ft_putstr(char *c);

int		ptr_len(unsigned long long n);

int		choise_case_hex(unsigned int n, char arg);

int		put_ptr(unsigned long long n);

char	*ft_utoa(unsigned int n);

int		check_len_unsigned(unsigned int n);

#endif