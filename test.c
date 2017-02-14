/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 13:18:18 by jebossue          #+#    #+#             */
/*   Updated: 2017/02/14 17:34:11 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*void	pint(char *str)
{
	printf("%c\n", *str);
}*/
int	main()
{
//	int		i;
	char	*str = "45 dkfuh g 65";
//	i = -45;	
	printf("%p\n", str);
//	printf("%#    1mnd0.d\n", atoi(str));
/*	i = 0;
	while (*str)
	{
		pint(str);
		(str)++;
//		i++;
	}
//	i = 250;
	printf("bonjour %.1d, %s\n", i, str);*/
	// COMPORTEMENT INDETERMINE ?? AV %u et un int en parametre
	return (0);
}
