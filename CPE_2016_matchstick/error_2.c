/*
** error_2.c for matchstick in /home/Rev/CPE_2016_matchstick
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Wed Feb	22 10:20:55 2017 Roméo Nahon
** Last update	Wed Feb	22 10:20:55 2017 Roméo Nahon
*/

#include "include/my.h"

int	check_matches_next(char *matches,
			   int nb_max,
			   int line,
			   char **game)
{
  if ((matches[0] < '1' && matches[0] > '9') ||
      my_getnbr(matches) < 0 || matches[0] < '0' || matches[0] > '9')
    {
      my_printf("Error: invalid input (positive number expected)\n");
      return (84);
    }
  else if (my_getnbr(matches) > nb_max && matches[0] != '\0')
    {
      my_printf("Error: you cannot remove more");
      my_printf(" than %d matches per turn\n", nb_max);
      return (84);
    }
  else if (my_strcmp(matches,
		     intoarg(my_getnbr(matches),
			     my_intlen(my_getnbr(matches) + 1))) == 1)
    {
      my_printf("Error: invalid input (positive number expected)\n");
      return (84);
    }
  else if ((check_matches_on_line(matches, line, game)) == 84)
    return (84);
}

int	check_matches_on_line(char *matches, int line, char **game)
{
  int	i;
  int	j;

  i = -1;
  j = 0;
  while (game[line][++i] != '\0')
    if (game[line][i] == '|')
      j += 1;
  if (my_getnbr(matches) > j && matches[0] != '\0')
    {
      my_printf("Error: not enough matches on this line\n");
      return (84);
    }
  return (0);
}

int	check_empty_lenght_line(char *coord)
{
  if (coord[0] == '\0')
    return (84);
  if (my_strlen(coord) <= 0)
    {
      my_printf("Error: invalid input (positive number expected)\n");
      return (84);
    }
  return (0);
}
