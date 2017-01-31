/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:31:52 by jebossue          #+#    #+#             */
/*   Updated: 2017/01/31 18:24:43 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void	ft_check_specifier_2(char **str, t_arg *param)
{
	if (**str == 'O' || **str == 'u' || **str == 'U' || **str == 'x'
			|| **str == 'X' || **str == 'C' || **str == '%')
	{
		if (**str == 'O')
			param->len = O;
		else if (**str == 'u')
			param->len = u;	
		else if (**str == 'U')
			param->len = U;
		else if (**str == 'x')
			param->len = x;
		else if (**str == 'X')
			param->len = X;
		else if (**str == 'C')
			param->len = c;
		else if (**str == '%')
			param->len = percent;
		++(*str);
	}
	else
		param->len = none;
}

void	ft_check_specifier(char **str, t_arg *param)
{
	if (**str == 's' || **str == 'S' || **str == 'p' || **str == 'd'
			|| **str == 'D' || **str == 'i' || **str == 'o')
	{
		if (**str == 's')
			param->len = s;
		else if (**str == 'S')
			param->len = S;
		else if (**str == 'p')
			param->len = p;
		else if (**str == 'd')
			param->len = d;
		else if (**str == 'D')
			param->len = D;
		else if (**str == 'i')
			param->len = i;
		else if (**str == 'o')
			param->len = o;
		++(*str);
	}
	else
		ft_check_specifier_2(str, param);
}
