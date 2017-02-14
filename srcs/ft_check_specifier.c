/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:00:36 by jebossue          #+#    #+#             */
/*   Updated: 2017/02/13 17:00:38 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_find_specifier_2(char **str, t_arg *param)
{
	if (**str == 'O' || **str == 'u' || **str == 'U' || **str == 'x'
			|| **str == 'X' || **str == 'C' || **str == '%')
	{
		if (**str == 'O')
			param->spec = O;
		else if (**str == 'u')
			param->spec = u;	
		else if (**str == 'U')
			param->spec = U;
		else if (**str == 'x')
			param->spec = x;
		else if (**str == 'X')
			param->spec = X;
		else if (**str == 'C')
			param->spec = C;
		else if (**str == '%')
			param->spec = percent;
		param->specifier = **str;
	}
}

int		ft_find_specifier(char **str, t_arg *param)
{
	if (**str == 's' || **str == 'S' || **str == 'p' || **str == 'd'
			|| **str == 'D' || **str == 'i' || **str == 'o')
	{
		if (**str == 's')
			param->spec = s;
		else if (**str == 'S')
			param->spec = S;
		else if (**str == 'p')
			param->spec = p;
		else if (**str == 'd')
			param->spec = d;
		else if (**str == 'D')
			param->spec = D;
		else if (**str == 'i')
			param->spec = i;
		else if (**str == 'o')
			param->spec = o;
		param->specifier = **str;
	}
	else
		ft_find_specifier_2(str, param);
	return (param->spec);
}

/*void	ft_find_specifier(char **str, t_arg *param)
{
	while (**str && (**str != 's' && **str != 'S' && **str != 'p'
				&& **str != 'd' && **str != 'D' && **str != 'i' && **str != 'o'
				&& **str != 'O' && **str != 'u' && **str != 'U' && **str != 'x'
				&& **str != 'X' && **str != 'C' && **str != '%'))
		++(*str);
	param->specifier = **str;
	ft_check_specifier(str, param);
}*/
