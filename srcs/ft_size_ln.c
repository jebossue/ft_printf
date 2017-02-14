/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_ln.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:41:12 by afourcad          #+#    #+#             */
/*   Updated: 2017/02/14 17:33:32 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_size(const char *format, va_list *ap, t_arg *param)
{
	int	ln;
	//param->type = ft_type(param); declaration variable qui va receuillir la valeur de va_arg 
	//param->type = va_arg(ap, ft_type_va)fonction defninissant le type du parametre a envoyer a va_arg
	ln = 1;
	if (param->specifier == 's' && param->len != 'l')
		ln = ft_strlen(param->type);
	if (param->specifier == 's' && param->len == 'l' || param->specifier == 'S')
		//DO THE UNICODE
	else if (param->specifier == 'c')
		ln++;
	else if (param->specifier == 'd' || param->specifier == 'D'
			|| param->specifier == 'u' || param->specifier == 'U'
			|| param->specifier == 'i')
		ln = ft_int_length(param->type);
	else if (param->specifier == 'x' || param->specifier == 'X')
		//DO THE CONVERTION
	else if (param->specifier == '
	else if (param->specifier == '
	//poOC
	return (ln);
}
