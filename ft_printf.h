/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anspirga <anspirga@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/14 15:03:12 by anspirga      #+#    #+#                 */
/*   Updated: 2021/01/30 17:08:34 by anspirga      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct		s_output
{
	int				counter;
	int				error;
}					t_output;

typedef struct		s_format
{
	char			flag;
	int				width;
	char			padding;
	char			side;
	char			precision;
	int				precision_size;
	char			negative;
	int				ptr;
	t_output		output;
}					t_format;

typedef struct		s_argument
{
	char			set;
	int				base;
	char			specifier;
}					t_argument;

int					ft_printf(const char *str, ...);

void				print_char(char c, t_format *format);
void				print_str(const char *str, t_format *format);
void				print_padding_till_n(char c, t_format *format, int n);
void				print_str_till_n(const char *str, t_format *format, int n);
void				print_str_til_precision(const char *str, t_format *format);

int					ft_strlen(const char *str);
int					ft_atoi(const char *str);
int					get_digit_length(int num);
int					replace_star(t_format *format, va_list args);

void				find_specifier(va_list args, char c, t_format *format);

void				handle_flag0_case(t_format *format, int padding_size,
														int zeros, char *array);
void				print_if_right(t_format *format, int padding_size,
													int zeros, char *array);
void				print_if_left(t_format *format, int padding_size,
											int zeros, char *array);

void				print_iduxxp(va_list ap, t_format *format, t_argument *arg);

void				c_print(va_list args, t_format *format);

void				s_print(va_list args, t_format *format);

void				ft_my_itoa(size_t positive, t_argument *argument,
															char *array);

#endif
