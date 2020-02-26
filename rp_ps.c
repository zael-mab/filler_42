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
	// dprintf (data.fdp, "\nw<%d>:z<%d>\n", cnt->w, cnt->z); // the piece dim
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

	// dprintf (data.fdp, "contr:[%d]\n", cnt->contr);
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
				// if (cnt->zeta < i && cnt->gama > j)

				// cnt->gama = (cnt->gama > j) ? cnt->gama : j;
				// if (cnt->gama > j)
				// 	cnt->zeta = (cnt->zeta < i) ? cnt->zeta : i;
				cnt->cornd[x] = (int*)malloc (sizeof (int) * 3);
				cnt->cornd[x][0] = i;
				cnt->cornd[x][1] = j;
				cnt->cornd[x][2] = -1;
				// dprintf(data.fdp, "|%d * %d|", cnt->cornd[x][0], cnt->cornd[x][1]);
				x++;
			}
		}
		// dprintf (data.fdp, "\n");
	}

	replace_the_piece(&data, cnt);
}

////////////////////////////
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
		{
			if (data->map[x][y] == -1)
			{
				check(x, y, cnt, data);
				// dprintf (data->fdp, "%d * %d | %d | alpha:%d beta:%d score =%d\n", x, y, cnt->contr, cnt->alpha, cnt->beta, cnt->score);
			}

		}
	}
	ft_putstr_fd ("\nBfcku\n", data->fdp);
	ft_putnbr(cnt->zeta);
	ft_putchar(' ');
	ft_putnbr(cnt->gama);
	ft_putchar ('\n');
}

void	check(int x, int y, t_cnt *cnt, t_data *data)
{
	int i;
	int w;
	int z;
	int t1;
	int t2;
	int res;
	int j;


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
		
		while (++i < cnt->contr)  // and != 0 the enamy points
		{
			if (cnt->cornd[i][2] == -1)
			{
				w = cnt->cornd[i][0] - cnt->alpha;
				z = cnt->cornd[i][1] - cnt->beta;
				if (data->map[w][z] > 0 && z < data->y && data->x > w)
				{
					ft_putchar_fd(' ', data->fdp);
					ft_putnbr_fd(data->map[w][z], data->fdp);
					res += data->map[w][z];
					ft_putchar_fd('-', data->fdp);
					ft_putnbr_fd(res, data->fdp);
				}
				else
				{
					res = 0;
					break ;
				}
			}

		}
		cnt->cornd[j][0] = t1;
		cnt->cornd[j][1] = t2;
		cnt->cornd[j][2] = -1;

		if ((cnt->score > res || cnt->score == 0) && res > 0)
		{
			cnt->zeta = x - t1;
			cnt->gama = y - t2;
			data->l = j;
			cnt->score = res;
		} // have the score & and the token position

	}
	///////////////////////////////////
	
	dprintf (data->fdp, "\nzeta = %d | gama = %d | score = %d\n", cnt->zeta, cnt->gama, cnt->score);
	dprintf (data->fdp, "\nres = %d | l = %d ", res, data->l);
	
}