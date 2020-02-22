/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 05:40:19 by zael-mab          #+#    #+#             */
/*   Updated: 2020/02/14 05:40:20 by zael-mab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void    louper0(t_data *data, t_cnt *cnt, int y, int x)
{
    cnt->ind = data->map[x][y] + 1;
    if (x + 1 < data->x && y + 1 < data->y)
    {
        if (data->map[x + 1][y + 1] == 99)
            data->map[x + 1][y + 1] = cnt->ind;
    }
    if (x + 1 < data->x && y - 1 > -1)
    {
        if (data->map[x + 1][y - 1] == 99)
            data->map[x + 1][y - 1] = cnt->ind;
    }
    if (x - 1 > -1 && y - 1 > -1)
    {
        if (data->map[x - 1][y - 1] == 99)
            data->map[x - 1][y - 1] = cnt->ind;
    }
    if (x - 1 > -1 && y + 1 < data->y)
    {
        if (data->map[x - 1][y + 1] == 99)
            data->map[x - 1][y + 1] = cnt->ind;
    }
}

void    louper1(t_data *data, t_cnt *cnt, int y, int x)
{
    if (x + 1 < data->x)
    {
        if (data->map[x + 1][y] == 99)
            data->map[x + 1][y] = cnt->ind;
    }
    if (x - 1 > -1)
    {
        if (data->map[x - 1][y] == 99)
            data->map[x - 1][y] = cnt->ind;
    }
    if (y - 1 > -1)
    {
        if (data->map[x][y - 1] == 99)
            data->map[x][y - 1] = cnt->ind;
    }
    if (y + 1 < data->y)
    {
        if (data->map[x][y + 1] == 99)
            data->map[x][y + 1] = cnt->ind;
    }
}

void    f_heat_map(t_data *data, t_cnt *cnt)
{
    int x;
    int y;
    
    x = -1;
    while (++x < data->x)
    {
        y = -1;
        while (++y < data->y)
        {
            cnt->ind = cnt->tp;
            if (data->map[x][y] == cnt->ind)
            {
                louper0(data, cnt, y, x);
                louper1(data, cnt, y, x);
            }
        }
    }
}

void	map_looper(t_data *data, t_cnt *cnt)
{
	int x;
	int y;

	x = -1;
	while (++x < data->x)
	{
		y = -1;
		while (++y < data->y)
		{
			if (data->map[x][y] == cnt->tp || data->map[x][y] == 99)
			{
				f_heat_map(data, cnt);
				cnt->tp++;
			}
		}
	}
}