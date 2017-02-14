/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:00:45 by jebossue          #+#    #+#             */
/*   Updated: 2017/02/13 17:00:47 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	fct(t_arg *param)
{
	printf("---NEW STRUCT--\n\n");
	if (param->param_good == TRUE)
		printf("param->param_good = TRUE\n");
	if (param->sharp == TRUE)
		printf("param->sharp = TRUE\n");
	if (param->null == TRUE)
		printf("param->null = TRUE\n");
	if (param->minus == TRUE)
		printf("param->minus = TRUE\n");
	if (param->plus == TRUE)
		printf("param->plus = TRUE\n");
	if (param->space == TRUE)
		printf("param->space = TRUE\n");
	if (param->is_width == TRUE)
		printf("param->width = %d\n", param->width);
	if (param->is_pre == TRUE)
		printf("param->precision = %d\n", param->precision);
	if (param->len != none)
		printf("param->length = %d\n", param->len);
	if (param->spec != no)
		printf("param->specifier = %c\n\n\n", param->specifier);
}

t_arg	*ft_check_param(const char *format)
{
	char	*next_param;
	t_arg	*param;

	if (*format == '\0' || (next_param = ft_strchr(format, '%')) == NULL
			|| *next_param == '\0')
		return (NULL);
	if ((param = (t_arg *)malloc(sizeof(*param))) == NULL)
		return (NULL);
	/*if (++(*next_param) == '%')
		//do it*/
	++next_param;
	param->spec = no;
	while ((ft_check_flags(&next_param, param)
		|| ft_check_width(&next_param, param)
		|| ft_check_precision(&next_param, param)
		|| ft_check_length(&next_param, param)
		|| ft_find_specifier(&next_param, param))
		&& param->spec == no)
		;
	if (param->spec == no)
		param->specifier = *format;
	param->next = ft_check_param(next_param + 1);
	return (param);
}

int		ft_check_full_len(const char *format, va_list *ap, t_arg *param)
{
	int		ln;

	ln = 1;
	while (*format != '\0')
	{
		if (*format == '%')
			ln = ln + ft_convert_size(format, ap, param);
		if (param->spec != no)
			format = ft_strchr(format, param->specifier);
		else
			format = ft_strchr(format, param->specifier) - 1;
		++ln;
		++format;
	}
	return (ln);
}

int		ft_printf(const char * restrict format, ...)
{
	va_list ap;
	size_t	ln;
	t_arg	*param;

	param = ft_check_param(format);
	while (param != NULL)
	{
		fct(param);
		param = param->next;
	}
	va_start(ap, format);
	ln = ft_check_full_len(format, &ap, param);
	va_end(ap);
	return(ln);
}
