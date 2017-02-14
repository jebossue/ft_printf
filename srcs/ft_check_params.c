/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:33:00 by afourcad          #+#    #+#             */
/*   Updated: 2017/02/13 16:55:51 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_check_flags(char **str, t_arg *param)
{
	param->param_good = FALSE;
	while (**str == '#' || **str == '0' || **str == '-' || **str == '+' ||
			**str == ' ')
	{
		if (**str == '#')
			param->sharp = TRUE;
		else if (**str == '0')
			param->null = TRUE;
		else if (**str == '-')
			param->minus = TRUE;
		else if (**str == '+')
			param->plus = TRUE;
		else if (**str == ' ')
			param->space = TRUE;
		++(*str);
		param->param_good = TRUE;
	}
	return (param->param_good);
}

int	ft_check_width(char **str, t_arg *param)
{
	if (ft_isdigit(**str) == GOOD)
	{
		param->is_width = TRUE;
		param->width = ft_atoi(*str);
		while (ft_isdigit(**str) == GOOD)
			++(*str);
		printf("param->width = %d\n", param->width);
	}
	else
		param->is_width = FALSE;
	return (param->is_width);
}

int	ft_check_precision(char **str, t_arg *param)
{
	if (**str == '.' && ft_isdigit(*(*str + 1)) == 1)
	{
		++(*str);
		param->precision = ft_atoi(*str);
		while (ft_isdigit(**str) == 1)
			++(*str);
		param->is_pre = TRUE;
		printf("param->precision = %d\n", param->precision);
	}
	else
		param->is_pre = FALSE;
	return (param->is_pre);
}

int	ft_check_length(char **str, t_arg *param)
{
	if (**str == 'h' && *(*str + 1) == 'h')
	{
		param->len = hh;
		(*str) += 2;
	}
	else if (**str == 'l' && *(*str + 1) == 'l')
	{
		param->len = ll;
		(*str) += 2;
	}
	else if (**str == 'h' || **str == 'l' || **str == 'j' || **str == 'z')
	{
		if (**str == 'h')
			param->len = h;
		else if (**str == 'l')
			param->len = l;
		else if (**str == 'j')
			param->len = j;
		else if (**str == 'z')
			param->len = z;
		++(*str);
	}
	else
		param->len = none;
	return (param->len);
}
