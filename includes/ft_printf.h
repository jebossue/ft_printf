/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:01:05 by jebossue          #+#    #+#             */
/*   Updated: 2017/02/14 17:33:29 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

# define ERROR 0
# define GOOD 1
# define NO 0

typedef enum	e_specifier
{
	no,
	s,
	S,
	p,
	d,
	D,
	i,
	o,
	O,
	u,
	U,
	x,
	X,
	C,
	percent
}				t_specifier;

typedef union	u_type
{
	int						my_int;
	unsigned int			my_uint;
	int	*					my_ptr_int;
	short int				sh_int;
	unsigned short int		sh_uint;
	short int *				sh_ptr_int;
	long int				l_int;
	unsigned long int		l_uint;
	long int *				l_ptr_int;
	long long int			ll_int;
	unsigned long long int	ll_uint;
}				t_type;

typedef enum	e_length
{
	none,
	h,
	hh,
	l,
	ll,
	j,
	z
}				t_length;

typedef	enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef struct	s_arg
{
	t_bool			param_good;
	t_bool			sharp;
	t_bool			null;
	t_bool			minus;
	t_bool			plus;
	t_bool			space;
	t_bool			is_width;
	int				width;
	t_bool			is_pre;
	int				precision;
	t_length		len;
	t_bool			is_spec;
	t_specifier		spec;
	char			specifier;
	struct s_arg	*next;
	t_type			type;
}				t_arg;

int		ft_printf(const char * restrict format, ...);
int		ft_check_flags(char **str, t_arg *param);
int		ft_check_width(char **str, t_arg *param);
int		ft_check_precision(char **str, t_arg *param);
int		ft_check_length(char **str, t_arg *param);
int		ft_convert_size(const char *format, va_list *ap, t_arg *param);
int		ft_find_specifier(char **str, t_arg *param);

#endif
