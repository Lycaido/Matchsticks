/*
** display.c for matchsticks in /home/Rev/CPE_2016_matchstick
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Feb	13 15:39:23 2017 Roméo Nahon
** Last update	Mon Feb	13 15:39:23 2017 Roméo Nahon
*/

#include "include/my.h"

void	display_map(char **game, int nb_sticks)
{
  int	i;

  i = -1;
  while (++i < nb_sticks + 2)
    my_printf("%s\n", game[i]);
}
