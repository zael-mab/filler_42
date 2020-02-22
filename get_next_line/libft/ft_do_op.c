/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseffian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 22:50:51 by hseffian          #+#    #+#             */
/*   Updated: 2019/04/22 01:14:16 by hseffian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_do_op(int a, char b, int c)
{
	int x;

	x = 0;
	if (b == '+')
		x = a + c;
	if (b == '-')
		x = a - c;
	if (b == '*')
		x = a * c;
	if (b == '/')
	{
		if (c != 0)
			x = a / c;
		else
			exit(1);
	}
	if (b == '%')
	{
		if (c != 0)
			x = a % c;
		else
			exit(1);
	}
	return (x);
}
