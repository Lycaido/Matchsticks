/*
** error.c for matchstick in /home/Rev/CPE_2016_matchstick
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Feb	13 09:35:17 2017 Roméo Nahon
** Last update	Mon Feb	13 09:35:17 2017 Roméo Nahon
*/

#include "include/my.h"

int	error_manager(int ac, char **av)
{
  if (ac <= 2 || ac > 3)
    {
      my_strerror("argument invalid\n");
      return (84);
    }
  if (my_getnbr(av[1]) > 100 || my_getnbr(av[1]) < 1)
    {
      my_strerror("numbers of sticks invalid\n");
      return (84);
    }
  if (my_getnbr(av[2]) <= 0)
    return (84);
  return (0);
}

int	check_line(char *coord, int nb_sticks)
{
  char	*res;

  if ((res = malloc(sizeof(char) * my_strlen(coord))) == NULL)
    return (84);
  if (check_empty_lenght_line(coord) == 84)
    return (84);
  else if (my_getnbr(coord) < 0 || coord[0] < '0' || coord[0] > '9')
    {
      my_printf("Error: invalid input (positive number expected)\n");
      return (84);
    }
  else if (my_getnbr(coord) > nb_sticks || my_getnbr(coord) == 0)
    {
      my_printf("Error: this line is out of range\n");
      return (84);
    }
  else if (my_strcmp(coord, intoarg(my_getnbr(coord),
				    my_intlen(my_getnbr(coord) + 1))) == 1)
    {
      my_printf("Error: invalid input (positive number expected)\n");
      return (84);
    }
  return (0);
}

int	check_matches(char *matches, char **game, int nb_max, int line)
{
  char	*res;

  if ((res = malloc(sizeof(char) * my_strlen(matches))) == NULL)
    return (84);
  res = my_memset(res, '\0', my_strlen(matches));
  if (matches[0] == '\0')
    {
      my_printf("Error: invalid input (positive number expected)\n");
      return (84);
    }
  else if (matches[0] == '0' && matches[0] != '\0')
    {
      my_printf("Error: you have to remove at least one match\n");
      return (84);
    }
  else if (my_strlen(matches) > 4 && my_strlen(matches) < 1 &&
	   matches[0] != '\0')
    {
      my_printf("Error: invalid input (positive number expected)\n");
      return (84);
    }
  else if ((check_matches_next(matches, nb_max, line, game)) == 84)
    return (84);
  return (0);
}

int	check_total_line(char **game, char *line, int nb_sticks)
{
  int	i;
  int	j;

  i = -1;
  j = 0;
  if (my_strlen(line) == 0)
    {
      my_printf("Error: invalid input (positive number expected)\n");
      return (1);
    }
  if (check_line(line, nb_sticks) == 84)
    return (1);
  while (game[my_getnbr(line)][++i])
    if (game[my_getnbr(line)][i] == '|')
      j += 1;
  if (j > 0)
    return (0);
  else
    {
      my_printf("Error: not enough matches on this line\n");
      return (1);
    }
  return (0);
}
