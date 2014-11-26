/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itao.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <vterzian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 17:34:24 by vterzian          #+#    #+#             */
/*   Updated: 2014/11/19 16:59:54 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_intlen(unsigned int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		nbr;
	char	*strnew;
	int		size;

	nbr = n;
	if (n < 0)
	{
		nbr *= -1;
		size = ft_intlen(nbr) + 1;
	}
	else
		size = ft_intlen(nbr);
	strnew = ft_strnew(size);
	if (strnew == NULL)
		return (NULL);
	if (n < 0)
		strnew[0] = '-';
	while (nbr > 0)
	{
		strnew[size - 1] = (nbr % 10) + '0';
		nbr /= 10;
		size--;
	}
	if (n == 0)
		strnew[0] = '0';
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (strnew);
}
