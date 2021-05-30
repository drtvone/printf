/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturnip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 20:27:53 by rturnip           #+#    #+#             */
/*   Updated: 2021/02/08 23:06:38 by rturnip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_PRINTF_H
# define MY_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef	struct		s_flags
{
	int				prec;
	int				widt;
	int				minus;
	int				dot;
	int				star;
	int				zero;
	char			type;
}					t_flags;

int					ft_printf(const char *line, ...);
int					make_result(va_list list, const char *line);
int					print_flag(t_flags *flags, va_list list);
int					print_flag(t_flags *flags, va_list list);
int					parse_flag(t_flags *flag, const char *line,
va_list list, int i);
int					fill_width(va_list list, t_flags *flags,
const char *line, int i);
int					fill_prec(va_list list, t_flags *flags,
const char *line, int i);
void				ft_make_flag(t_flags *flag);
int					ft_atoi(const char *str);
int					printf_pointer(t_flags *flags, unsigned long long arg);
int					printf_char(t_flags *flags, int c);
int					printf_string(t_flags *flags, const char *arg);
int					my_printf_hex(t_flags *flags, unsigned int a);
int					printf_uns(t_flags *flags, unsigned int a);
int					printf_int(t_flags *flags, int a);
char				*printf_itoa_uns(unsigned int n);
char				*ft_strdup(const char *s1);
char				*itoa_hex(unsigned long long a);
void				letters_size(char *s);
int					ft_str_check(const char *s, int c);
int					ft_strlen(const char *str);
int					ft_isdigit(int c);
void				ft_putchar(char c);
int					ft_check_length(int a);
char				*ft_itoa(int n);
int					printf_int_two_plus(t_flags *flags, char *res);
int					printf_int_one_plus(t_flags *flags, char *res);
int					help_int_one(t_flags *flags, char *res);
int					help_int_two(t_flags *flags, char *res);
int					help_int_three(t_flags *flags, char *res);
int					help_int_four(t_flags *flags, char *res);
int					help_int_five_minus(t_flags *flags, int b,
char *res, int a);
int					printf_int_one(t_flags *flags, char *res);
int					printf_int_two(t_flags *flags, char *res);
void				help_fill_flags(t_flags *flags);
void				help_funcs(t_flags *flag);
int					help_funcs_two(t_flags *flags, char *res);

#endif
