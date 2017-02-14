/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:30:14 by jebossue          #+#    #+#             */
/*   Updated: 2017/02/13 17:04:06 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "includes/ft_printf.h"

int		main()
{
	char *str = "bla";
	printf("%#-+ 10d\njhfg\n", 3510);
	ft_printf("%-10d %# .10s\n", 3510, str);
	return (0);
}
