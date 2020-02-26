/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 05:40:24 by zael-mab          #+#    #+#             */
/*   Updated: 2020/02/14 05:40:25 by zael-mab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FILLER_H
# define FILLER_H

#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

typedef struct s_data
{
    int         fdp; // just for debugging  
    int         x;
    int         y;
    int         pnum;
    char        pl1;
    char        pl2;
    char        *line;
    int         **map;
    char        **tab;
    int         l;
}               t_data;

typedef struct  s_cnt
{
    int         gama;
    int         zeta;
    int         alpha;
    int         beta;
    int         w;
    int         z;
    int         **cornd;
    int         score;
    int         contr;
    int         ind;
    int         tp;
}               t_cnt;

int		checke_the99(t_data data);
void	vs(t_data data);

void 	replace_the_piece(t_data *data, t_cnt *cnt);
void	get_the_piece(t_data data,t_cnt *cnt);
void	map_looper(t_data *data, t_cnt *cnt);


void	check(int x, int y,t_cnt *cnt, t_data *data);



void    louper1(t_data *data, t_cnt *cnt, int y, int x);
void    louper0(t_data *data, t_cnt *cnt, int y, int x);
void	get_ply_num(t_data *data);
void	get_dimxy(t_data *data);
void	free_tbl(void **tbl, int i);
void	ft_crt_map(t_data *data, char *line, int jumper);
void    ini_heat_map(t_data *data, t_cnt *cnt, int y, int x);
void    f_heat_map(t_data *data, t_cnt *cnt);
void    heat_map(t_data *data, t_cnt *cnt);
void    skep_line(char *line);

# endif
