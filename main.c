/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 05:40:00 by zael-mab          #+#    #+#             */
/*   Updated: 2020/02/14 05:40:02 by zael-mab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


void	skep_line(char *line)
{
	get_next_line(0, &line);
	free(line);
}

void	get_ply_num(t_data *data)   // geting the player number & character (o/x);
{
	size_t i;

	i = -1;
	get_next_line(0, &data->line);
	data->pnum = ft_atoi(data->line + 10);
	if (data->pnum == 0)
		exit (EXIT_FAILURE);
	if (data->pnum == 1)
	{
		data->pl1 = 'o';
		data->pl2 = 'x';
	}
	if (data->pnum == 2)
	{
		data->pl1 = 'x';
		data->pl2 = 'o';
	}
	free(data->line);
	// dprintf(data->fdp ,"\n|%d|\n", data->pnum);
}

void	get_dimxy(t_data *data)		// geting the map coordinates (^|^ X) / (Y->)
{
	size_t i;

	i = 0;
	get_next_line(0, &data->line);
	data->tab = ft_strsplit(data->line, ' ');
	data->x = ft_atoi(data->tab[1]);
	data->y = ft_atoi(data->tab[2]);
	// dprintf(data->fdp ,"x=|%d| y=|%d|\n", data->x, data->y);
	if (data->x == 0 || data->y == 0)
		exit(EXIT_FAILURE);
	ft_strdel(data->tab);
	free(data->line);
}

void	vrf_mapdy(t_data *data) 	// checking the lines;
{
	int i;
	
	i = 0;
	get_next_line(0, &data->line);
	// ft_putstr_fd (data->line, data->fdp);
	while (data->line[i] && i < data->y)
	{
		if (data->line[i] != ' ' && i < 4)
			exit(EXIT_FAILURE);
		if (!(ft_isdigit(data->line[i])) && i >= 4)
			exit(EXIT_FAILURE);
		i++;
	}
	free(data->line);
}


void		vrf_mapdx(t_data *data, char *line)	// checking the lines;
{
	int		i;
	char	c;

	i = -1;
	data->tab = ft_strsplit(line, ' ');
	while (data->tab[0][++i])
		if (!(ft_isdigit(data->tab[0][i])))
			exit(EXIT_FAILURE);
			// dprintf (data->fdp, "%c", data->tab[0][i]); // same here exit failure
	i = -1;
	while (data->tab[1][++i])
	{
		c = data->tab[1][i];
		if (!(c == '.' || c == 'x' || c == 'X' || c == 'o' || c == 'O'))
			// dprintf (data->fdp, "%c", c);	// change it to exit failure
			exit(EXIT_FAILURE);
	}
	ft_strdel(data->tab);
}

void	free_tbl(void **tbl, int i)
{
	int	jumper;

	jumper = -1;
	while (++jumper < i)
		free(tbl[i]);
	free(tbl);
}

void	ft_crt_map(t_data *data, char *line, int jumper)
{
	int i;
	int j;

	i = -1;
	data->tab = ft_strsplit (line, ' ');
	j = jumper - 1;
	while (data->tab[1][++i] && i < data->y)
	{
		if (data->tab[1][i] == '.')
			data->map[j][i] = 777;
		if (data->tab[1][i] == data->pl1 || data->tab[1][i] == ft_toupper(data->pl1))
			data->map[j][i] = -1;
		if (data->tab[1][i] == data->pl2 || data->tab[1][i] == ft_toupper(data->pl2))
			data->map[j][i] = 0;
		// dprintf (data->fdp, "[%d]", data->map[j][i]);
	}
	ft_strdel(data->tab);
	// dprintf (data->fdp, "\n");
}

int			main (void)
{
	char	*line = NULL;
	t_data	data;
	t_cnt 	cnt;
	int 	i;
	int 	jumper;

	ft_bzero(&data, sizeof(t_data));
	ft_bzero(&cnt, sizeof(t_cnt));
	data.fdp = open ("tmp1", O_RDWR | O_CREAT);
	get_ply_num(&data);

////
//////////////////////
	while (1)
	{
		
		ft_putstr_fd ("I'm here0\n", data.fdp);	
		get_dimxy(&data);
		vrf_mapdy(&data);
		
		data.map = (int **)malloc (sizeof (int *) * (data.x));
			// exit(0);
		i = 0;
		jumper = 0;
		ft_putnbr_fd (data.y, data.fdp);
		ft_putnbr_fd (data.x, data.fdp);
		while (i++ < data.x)
		{
			get_next_line(0 , &line);
			// if ()
			dprintf (data.fdp,"%s\n", line);
			data.map[jumper++] = (int *)malloc (sizeof (int) * data.y);
				// ft_strdel((char*)data.map[jumper]);
			vrf_mapdx(&data, line);
			ft_crt_map(&data, line, i);
			free(line);
		}
	//////////////////////////
		cnt.tp = 0;
		map_looper(&data, &cnt);
		// map_looper(&data, &cnt);
		vs(data);
		get_the_piece(data, &cnt);
		// ft_putstr_fd ("I'm here22\n", data.fdp);	
		ft_strdel((char **)data.map);
	}
	close (data.fdp);
	return (0);
}


void	vs(t_data data)   // heatmap vs on tmp(data.fdp)
{
	int i;
	int j;

	i = -1;
	dprintf (data.fdp,"\n");
	while (++i < data.x)
	{
		j = -1;
		while (++j < data.y)
			dprintf (data.fdp,"|%2d", data.map[i][j]);
		dprintf (data.fdp,"\n");
	}
}