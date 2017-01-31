/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:32:05 by jebossue          #+#    #+#             */
/*   Updated: 2017/01/31 17:43:36 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

t_arg	*ft_check_param(const char * restrict format, t_arg *param)
{
	char	*next_param;

	if ((next_param = ft_strchr(format, '%')) == NULL)
		return (NULL);
//	if (++(*next_param) == '%')
		//do it
	ft_check_flags(next_param, param);
	ft_check_width(next_param, param);
	ft_check_precision(next_param, param);
	ft_check_length(next_param, param);
	ft_check_specifier(next_param, param);
	param->next = ft_ckeck_param(next_param, param);
	return (param);
}

int		ft_printf(const char * restrict format, ...)
{
	va_list ap;
	size_t	ln;
	t_arg	*param;

	if ((param = ft_check_param(format, param)) == NULL)
	{
		ln = ft_strlen(format);
		ft_putstr(format);
	}
	va_start(ap, format);
	ln = ft_check_arg(format, &ap, 0);
	va_end(ap);
	return(ln);
}
