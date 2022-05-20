/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_enemie_moves.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:52:27 by zmoussam          #+#    #+#             */
/*   Updated: 2022/05/20 01:32:45 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void moves_enemie_left(t_long *so_long,char point, t_cordinates p, int *bolean)
{   
    int tmp = *bolean;
    if (so_long->map[p.y][p.x - 1] != '1' && so_long->map[p.y][p.x - 1] != 'E')
	{
        if(tmp == 1)
        {
             if (so_long->map[p.y][p.x - 1] == 'C')
             {
                *bolean = 1;
                so_long->map[p.y][p.x - 1] = point;
                so_long->map[p.y][p.x] = 'C';
             }
            else if(so_long->map[p.y][p.x - 1] == '0')
            {
                *bolean = 0;
                so_long->map[p.y][p.x - 1] = point;
                so_long->map[p.y][p.x] = 'C';
                
            }     
        }
        if(tmp == 0)
        {
            if(so_long->map[p.y][p.x - 1] == '0')
            {
                *bolean = 0;
                so_long->map[p.y][p.x - 1] = point;
                so_long->map[p.y][p.x] = '0';
                
            }
            else if (so_long->map[p.y][p.x - 1] == 'C')
             {
                *bolean = 1;
                so_long->map[p.y][p.x - 1] = point;
                so_long->map[p.y][p.x] = '0';
             }
        }
    }
}

void moves_enemie_right(t_long *so_long, char point, t_cordinates p, int *bolean)
{
     int tmp = *bolean;
     
    if (so_long->map[p.y][p.x + 1] != '1' && so_long->map[p.y][p.x + 1] != 'E')
	{
        if(tmp == 1)
        {
             if (so_long->map[p.y][p.x + 1] == 'C')
             {
                *bolean = 1;
                so_long->map[p.y][p.x + 1] = point;
                so_long->map[p.y][p.x] = 'C';
             }
            else if(so_long->map[p.y][p.x + 1] == '0')
            {
                *bolean = 0;
                so_long->map[p.y][p.x + 1] = point;
                so_long->map[p.y][p.x] = 'C';
                
            }     
        }
        if(tmp == 0)
        {
            if(so_long->map[p.y][p.x + 1] == '0')
            {
                *bolean = 0;
                so_long->map[p.y][p.x + 1] = point;
                so_long->map[p.y][p.x] = '0';
                
            }
            else if (so_long->map[p.y][p.x + 1] == 'C')
             {
                *bolean = 1;
                so_long->map[p.y][p.x + 1] = point;
                so_long->map[p.y][p.x] = '0';
             }
        }
    }
}

void moves_enemie_up(t_long *so_long, char point, t_cordinates p, int *bolean)
{
    int tmp = *bolean;
     
    if (so_long->map[p.y - 1][p.x] != '1' && so_long->map[p.y - 1][p.x] != 'E')
	{
        if(tmp == 1)
        {
             if (so_long->map[p.y - 1][p.x] == 'C')
             {
                *bolean = 1;
                so_long->map[p.y - 1][p.x] = point;
                so_long->map[p.y][p.x] = 'C';
             }
            else if(so_long->map[p.y - 1][p.x] == '0')
            {
                *bolean = 0;
                so_long->map[p.y -  1][p.x] = point;
                so_long->map[p.y][p.x] = 'C';
                
            }     
        }
        if(tmp == 0)
        {
            if(so_long->map[p.y - 1][p.x] == '0')
            {
                *bolean = 0;
                so_long->map[p.y - 1][p.x] = point;
                so_long->map[p.y][p.x] = '0';
                
            }
            else if (so_long->map[p.y - 1][p.x] == 'C')
             {
                *bolean = 1;
                so_long->map[p.y - 1][p.x] = point;
                so_long->map[p.y][p.x] = '0';
             }
        }
    }
}
void moves_enemie_down(t_long *so_long, char point ,t_cordinates p, int *bolean)
{
    int tmp = *bolean;
     
    if (so_long->map[p.y + 1][p.x] != '1' && so_long->map[p.y + 1][p.x] != 'E')
	{
        if(tmp == 1)
        {
             if (so_long->map[p.y + 1][p.x] == 'C')
             {
                *bolean = 1;
                so_long->map[p.y + 1][p.x] = point;
                so_long->map[p.y][p.x] = 'C';
             }
            else if(so_long->map[p.y + 1][p.x] == '0')
            {
                *bolean = 0;
                so_long->map[p.y + 1][p.x] = point;
                so_long->map[p.y][p.x] = 'C';
                
            }     
        }
        if(tmp == 0)
        {
            if(so_long->map[p.y + 1][p.x] == '0')
            {
                *bolean = 0;
                so_long->map[p.y + 1][p.x] = point;
                so_long->map[p.y][p.x] = '0';
                
            }
            else if (so_long->map[p.y + 1][p.x] == 'C')
             {
                *bolean = 1;
                so_long->map[p.y + 1][p.x] = point;
                so_long->map[p.y][p.x] = '0';
             }
        }
    }
}
void moves_enemie_red(t_long *so, t_cordinates e,int *bolean)
{
    int randd;
    int l;
    int u;

    l = 0;
    u = 4;
    randd = (rand() % (u - l + 1) + l);
    if(randd == 0)
        moves_enemie_left(so,'R',e,bolean);
    else if(randd == 1)
        moves_enemie_down(so,'R',e,bolean);
    else if(randd == 2)
        moves_enemie_right(so,'R',e,bolean);
    else if(randd == 4)
        moves_enemie_up(so, 'R',e,bolean);
}
void moves_enemie_green(t_long *so, t_cordinates e,int *bolean)
{
    int randd;
    int l;
    int u;

    l = 0;
    u = 4;
    randd = (rand() % (u - l + 1) + l);

    if(randd == 0)
        moves_enemie_left(so,'G',e,bolean);
    else if(randd == 1)
        moves_enemie_down(so,'G',e,bolean);
    else if(randd == 2)
        moves_enemie_right(so,'G',e,bolean);
    else if(randd == 4)
        moves_enemie_up(so, 'G',e,bolean);
}
void handel_enemie_moves(t_long *so_long,int *bolean ,t_cordinates p)
{
    if (so_long->map[p.y][p.x] == 'R')
    {
        //printf("!!!!\n");
		moves_enemie_red(so_long, p,bolean);
    }
	if (so_long->map[p.y][p.x] == 'G')
    {
        moves_enemie_green(so_long, p,bolean);
    }
}