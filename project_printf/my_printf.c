/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 20:15:34 by rturnip           #+#    #+#             */
/*   Updated: 2021/02/09 00:26:15 by rturnip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

int		print_flag(t_flags *flags, va_list list)
{
	if (!flags)
		return (0);
	if ((*flags).type == 'c')
		return (printf_char(flags, va_arg(list, int)));
	if ((*flags).type == '%')
		return (printf_char(flags, '%'));
	if ((*flags).type == 's')
		return (printf_string(flags, va_arg(list, char *)));
	if ((*flags).type == 'u')
		return (printf_uns(flags, va_arg(list, unsigned int)));
	if ((*flags).type == 'x' || (*flags).type == 'X')
		return (my_printf_hex(flags, va_arg(list, unsigned int)));
	if ((*flags).type == 'd' || (*flags).type == 'i')
		return (printf_int(flags, va_arg(list, int)));
	if ((*flags).type == 'p')
		return (printf_pointer(flags, va_arg(list, unsigned long long)));
	return (0);
}

int		make_result(va_list list, const char *line)
{
	int			i;
	int			result;
	t_flags		flags;

	i = 0;
	result = 0;
	while (line[i])
	{
		if ((line[i] == '%'))
		{
			i = parse_flag(&flags, line, list, i);
			result += print_flag(&flags, list);
		}
		else
			result += write(1, &line[i], 1);
		i++;
	}
	return (result);
}

int		ft_printf(const char *line, ...)
{
	va_list	list;
	int		result;

	va_start(list, line);
	result = make_result(list, line);
	va_end(list);
	return (result);
}
