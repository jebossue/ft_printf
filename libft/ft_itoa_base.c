/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:47:10 by afourcad          #+#    #+#             */
/*   Updated: 2017/01/31 18:18:23 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		ft_check_base(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i])
	{
		j= 0;
		while (j != i && base[j])
		{
			if (base[i] == base[j])
				return(0);
			j++;
		}
		i++;
	}
	return(0);
}

char	*ft_itoa_base(int nbr, char *base)
{
	int		size;
	char	*nbr;
	int		is_neg;

	if (ft_check_base(base) == 0)
		return(NULL);
	
}

