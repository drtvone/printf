/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:26:25 by rturnip           #+#    #+#             */
/*   Updated: 2021/02/09 00:28:19 by rturnip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

int			help_int_five_minus(t_flags *flags, int b, char *res, int a)
{
	int i;

	i = 0;
	help_fill_flags(flags);
	res = ft_itoa(a);
	if (flags->prec <= ft_strlen(res) && flags->widt <= ft_strlen(res))
		i = help_funcs_two(flags, res);
	if ((*flags).prec > ft_strlen(res) && (*flags).widt <= (*flags).prec)
	{
		b = (*flags).prec - ft_strlen(res) + 1;
		ft_putchar('-');
		while ((*flags).prec-- > ft_strlen(res))
			ft_putchar('0');
		(*flags).widt = ft_strlen(res) - 1;
		(*flags).prec += 1;
		i = b + printf_string(flags, res);
	}
	if ((*flags).prec <= ft_strlen(res) && flags->widt > ft_strlen(res))
		i = printf_int_one(flags, res);
	if (flags->prec > ft_strlen(res) && flags->widt > flags->prec)
		i = printf_int_two(flags, res);
	free(res);
	return (i);
}

int			ft_str_check(const char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			ft_check_length(int a)
{
	int k;

	k = 0;
	if ((a < 10) && (a != 0))
		return (1);
	while (a > 9)
	{
		a = a / 10;
		k++;
	}
	return (k);
}
