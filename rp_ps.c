/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rp_ps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:48:34 by zael-mab          #+#    #+#             */
/*   Updated: 2020/02/21 13:48:36 by zael-mab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_the_piece(t_data data,t_cnt *cnt)
{
	int		i;
	int 	j;

	get_next_line(0, &data.line);
	data.tab = ft_strsplit(data.line, ' ');
	free (data.line);
	i = -1;
	cnt->w = ft_atoi(data.tab[1]); 					//number of lines
	cnt->z = ft_atoi(data.tab[2]);					//len
	data.tab = (char **)malloc (sizeof(char *) * cnt->w);
	cnt->contr = 0;
	while (++i < cnt->w)
	{
		get_next_line(0, &data.line);
		j = -1;
		while (data.line[++j])
			if (data.line[j] == '*')
				cnt->contr += 1;	// get the number of '*'
		data.tab[i] = (char *)malloc (sizeof(char) * cnt->z);
		data.tab[i] = ft_strcpy(data.tab[i], data.line);
		free (data.line);
	}

//////////////////////////////////////

	int x;
	
	x = 0;
	i = -1;
	cnt->cornd = (int **) malloc (sizeof (int *) * cnt->contr);
	while (++i < cnt->w)
	{
		j = -1;
		while (++j < cnt->z)
		{
			if (data.tab[i][j] == '*')   // save the cord of the token
			{
				cnt->cornd[x] = (int*)malloc (sizeof (int) * 3);
				cnt->cornd[x][0] = i;
				cnt->cornd[x][1] = j;
				cnt->cornd[x][2] = -1;
				x++;
			}
		}
		dprintf (data.fdp, "\n");
	}
	replace_the_piece(&data, cnt);
}

void 	replace_the_piece(t_data *data, t_cnt *cnt)
{
	int x;
	int y;

	x = -1;
	cnt->score = 0;
	while (++x < data->x)
	{
		y = -1;
		while (++y < data->y)
			if (data->map[x][y] == -1)
				check(x, y, cnt, data);
	}
	ft_putnbr(cnt->zeta);
	ft_putchar(' ');
	ft_putnbr(cnt->gama);
	ft_putchar ('\n');
}

void	check(int x, int y, t_cnt *cnt, t_data *data)
{
	int i;
	int w = 0;
	int z = 0;
	int t1;
	int t2;
	int res;
	int j;
	int ind;


	j = -1;
	while (++j < cnt->contr) 
	{
		cnt->alpha = cnt->cornd[j][0] - x;
		cnt->beta = cnt->cornd[j][1] - y;
		t1 = cnt->cornd[j][0];
		t2 = cnt->cornd[j][1];
		cnt->cornd[j][0] = x;
		cnt->cornd[j][1] = y;
		cnt->cornd[j][2] = 1;
		i = -1;
		res = 0;
		ind = 0;
		while (++i < cnt->contr)  // and != 0 the enamy points
		{
			if (cnt->cornd[i][2] == -1)
			{
				w = cnt->cornd[i][0] - cnt->alpha;
				z = cnt->cornd[i][1] - cnt->beta;
				if (w < 0 || z < 0 || z >= data->y || data->x <= w)
				{
					ind = 0;
					res = 0;
					break ;
				}
				// if (w < 0 || z < 0)
				// 	break ;
				if (z < data->y && data->x > w)
				{
					if (data->map[w][z] >= 1 )
					{
						ind +=1;
						res += data->map[w][z];
					}
					if (data->map[w][z] < 1)
					{
						res = 0;
						ind = 0;
						break ;
					}
				}
				
			}

		}
		cnt->cornd[j][0] = t1;
		cnt->cornd[j][1] = t2;
		cnt->cornd[j][2] = -1;
		if (( cnt->score >= res || cnt->score == 0) && res > 0 && ind + 1 == cnt->contr)
		{
			cnt->zeta = (x - t1);
			cnt->gama = (y - t2);
			cnt->score = res;
		} // have the score & and the token position

	}
}