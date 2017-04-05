/*
** main.c for matchstick in /home/Rev/CPE_2016_matchstick
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Feb	13 09:30:34 2017 Roméo Nahon
** Last update	Mon Feb	13 09:30:34 2017 Roméo Nahon
*/

#include "include/my.h"

int	main(int ac, char **av)
{
  char	**game;
  int	state;

  if ((error_manager(ac, av)) == 84)
    return (0);
  game = draw_game(my_getnbr(av[1]));
  state = matchsticks(game, my_getnbr(av[1]), my_getnbr(av[2]));
  if (state == 1)
    return (1);
  else if (state == 2)
    return (2);
  else if (state == 10)
    return (0);
}
