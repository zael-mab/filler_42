/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 05:41:07 by zael-mab          #+#    #+#             */
/*   Updated: 2019/04/12 16:01:09 by zael-mab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t j;

	j = 0;
	if (s1 && s2)
	{
		while ((s1[j] || s2[j]) && j < n)
		{
			if (s1[j] != s2[j])
				return (0);
			j++;
		}
		return (1);
	}
	return (0);
}
