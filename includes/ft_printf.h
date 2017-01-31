/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 19:32:43 by afourcad          #+#    #+#             */
/*   Updated: 2017/01/30 16:47:13 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
#include "libft.h"

# define ERROR 0
# define GOOD 1
# define NO 0

typedef enum	e_specifier
{
	none,
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
	t_specifier		spec;
	struct s_arg	*next;
}				t_arg;

#endif
