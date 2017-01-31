/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzerocustom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:52:09 by afourcad          #+#    #+#             */
/*   Updated: 2017/01/31 18:16:56 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzerocutom(void *s, size_t n, char c)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = s;
	while (i < n - 1)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
}
