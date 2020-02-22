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
	dprintf (data.fdp, "\nw<%d>:z<%d>\n", cnt->w, cnt->z); // the piece dim
	data.tab = (char **)malloc (sizeof(char *) * cnt->w);
	cnt->contr = 0;
	while (++i < cnt->w)
	{
		get_next_line(0, &data.line);
		j = -1;
		while (data.line[++j])
			if (data.line[j] == '*')
				cnt->contr += 1;	// get the number of '*'
		dprintf (data.fdp, "%s\n", data.line); 
		data.tab[i] = (char *)malloc (sizeof(char) * cnt->z);
		data.tab[i] = ft_strcpy(data.tab[i], data.line);
		free (data.line);
	}

//////////////////////////////////////

	dprintf (data.fdp, "contr:[%d]\n", cnt->contr);
	int x;
	
	x = 0;
	i = -1;
	// cnt->gama = -1;
	// cnt->zeta = -1;
	cnt->cornd = (char **) malloc (sizeof (char *) * cnt->contr);
	while (++i < cnt->w)
	{
		j = -1;
		while (++j < cnt->z)
		{
			if (data.tab[i][j] == '*')   // save the cord of the token
			{
				// if (cnt->zeta < i && cnt->gama > j)

				// cnt->gama = (cnt->gama > j) ? cnt->gama : j;
				// if (cnt->gama > j)
				// 	cnt->zeta = (cnt->zeta < i) ? cnt->zeta : i;
				cnt->cornd[x] = (char*)malloc (sizeof (char) * 2);
				cnt->cornd[x][0] = i;
				cnt->cornd[x][1] = j;
				dprintf(data.fdp, "|%d * %d|", cnt->cornd[x][0], cnt->cornd[x][1]);
				x++;
			}
		}
		dprintf (data.fdp, "\n");
	}
	replace_the_piece(&data, cnt);
}

////////////////////////////
void 	replace_the_piece(t_data *data, t_cnt *cnt)
{
	int x;
	int y;
	int i;
	int w;
	int z;
	// int res = 0;
	int score = 0;

	x = -1;
	while (++x < data->x)
	{
		y = -1;
		while (++y < data->y)
		{
			if (data->map[x][y] == -1)
			{
				i = 0;
				// while (++i)
				// {
					cnt->alpha = abs(cnt->cornd[i][0] - x);
					cnt->beta = abs(cnt->cornd[i][1] - y);
					cnt->cornd[i][0] = x;
					cnt->cornd[i][1] = y;
					while (i++ < cnt->contr - 1)
					{
						w = cnt->cornd[i][0] + cnt->alpha;
						z = cnt->cornd[i][1] + cnt->beta;
						if (data->map[w][z] == -1)
							dprintf (data->fdp,"ops");
						else
						{
							score += data->map[w][z];
							data->map[w][z] = -2;	
						}
						
					}
				// }
				dprintf (data->fdp, "%d * %d | %d | alpha:%d beta:%d score =%d\n", x, y, cnt->contr, cnt->alpha, cnt->beta, score);
			}

		}
	}
	// vs(*data);
}

// void	check(int x, int y, int alpha, int beta)
// {

// }