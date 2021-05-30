/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:25:04 by rturnip           #+#    #+#             */
/*   Updated: 2021/02/09 00:29:06 by rturnip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

static unsigned int	ft_count_hex(unsigned long long a)
{
	unsigned int k;

	k = 1;
	while ((a = a / 16))
		k++;
	return (k);
}

static void			ft_rev(char *itoa)
{
	size_t	i;
	size_t	len;
	char	one;

	i = 0;
	len = ft_strlen(itoa) - 1;
	while (i < len)
	{
		one = itoa[i];
		itoa[i] = itoa[len];
		itoa[len] = one;
		i++;
		len--;
	}
}

void				letters_size(char *s)
{
	int	k;

	k = 0;
	while (s[k])
	{
		if (s[k] >= 65 && s[k] <= 90)
			s[k] = s[k] + 32;
		k++;
	}
}

char				*itoa_hex(unsigned long long a)
{
	int				i;
	unsigned	int	count;
	char			*hex;
	char			*symb;

	i = 0;
	if (a == 0)
		return (ft_strdup("0"));
	if (a < 0)
		return (ft_strdup(""));
	count = ft_count_hex(a);
	if (!(hex = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	hex[count] = '\0';
	symb = "0123456789ABCDEF";
	while (a > 0)
	{
		hex[i++] = symb[a % 16];
		a = a / 16;
	}
	ft_rev(hex);
	return (hex);
}

int					my_printf_hex(t_flags *flags, unsigned int a)
{
	int		i;
	char	*res;
	int		len;

	len = 0;
	i = 0;
	res = itoa_hex((unsigned long long)a);
	if (flags->prec == 0 && res[0] == '0')
		res = ft_strdup("");
	if (flags->type == 'x')
		letters_size(res);
	if (flags->widt < flags->prec)
		(*flags).widt = flags->prec;
	if ((*flags).minus == 1 || (*flags).prec > -1)
		(*flags).zero = 0;
	if (flags->prec <= ft_strlen(res) && flags->widt <= ft_strlen(res))
		i = help_int_four(flags, res);
	else if ((*flags).prec > ft_strlen(res) && (*flags).widt <= (*flags).prec)
		i = help_int_four(flags, res);
	else if ((*flags).prec <= ft_strlen(res) && flags->widt > ft_strlen(res))
		i = printf_int_one_plus(flags, res);
	else if (flags->prec > ft_strlen(res) && flags->widt > flags->prec)
		i = printf_int_two_plus(flags, res);
	free(res);
	return (i);
}
