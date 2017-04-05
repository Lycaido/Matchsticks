/*
** matchsticks.c for matchsticks in /home/Rev/CPE_2016_matchstick
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Feb	13 15:42:25 2017 Roméo Nahon
** Last update	Mon Feb	13 15:42:25 2017 Roméo Nahon
*/

#include "include/my.h"

char	**modifie_map(int line, int matches, char **game)
{
  int	i;
  int	j;
  int	r;

  i = 0;
  j = -1;
  r = -1;
  while (++i < 200)
    {
      j += 1;
      if (game[line][j] == '|')
	if (game[line][j + 1] == ' ' || game[line][j + 1] == '*')
	  i = 200;
    }
  while (++r < matches)
    {
      game[line][j] = ' ';
      j -= 1;
    }
  return (game);
}

int	get_line(char **game, int nb_sticks)
{
  int	line_nb;
  char	*line;
  int	status;

  if ((line = malloc(sizeof(char) * 3)) == NULL)
    return (84);
  line = my_memset(line, '\0', 3);
  my_printf("Line: ");
  line = get_next_line(0);
  if (my_getnbr(line) == -42)
    return (-32);
  while (check_total_line(game, line, nb_sticks) == 1)
    {
      my_printf("Line: ");
      line = get_next_line(0);
      if (my_getnbr(line) == -42)
	return (-32);
      line_nb = my_getnbr(line);
    }
  return (my_getnbr(line));
}

int	get_matches(char **game, int nb_sticks, int *line_nb, int nb_max)
{
  char	*matches;
  int	matches_nb;

  if ((matches = malloc(sizeof(char) * 3)) == NULL)
    return (84);
  matches = my_memset(matches, '\0', 3);
  if ((*line_nb = get_line(game, nb_sticks)) == -32)
    return (-32);
  my_printf("Matches: ");
  matches = get_next_line(0);
  if (my_getnbr(matches) == -42)
    return (-32);
  matches_nb = my_getnbr(matches);
  if ((check_matches(matches, game, nb_max, *line_nb)) == 84)
    if ((matches_nb = get_matches(game, nb_sticks, line_nb, nb_max))
	== -32)
      return (-32);
  return (matches_nb);
}

int	win_o_lose(char **game, int nb_sticks)
{
  int	i;
  int	j;

  i = 0;
  while (i < (nb_sticks + 2))
    {
      j = -1;
      while (game[i][++j] != '\0')
	{
	  if (game[i][j] == '|' && game[i][j]
	      != ' ' && game[i][j] != '*')
	    return (0);
	}
      i += 1;
    }
  return (1);
}
int	matchsticks(char **game, int nb_sticks, int nb_max)
{
  int	line_nb;
  int	matches_nb;
  int	i;

  i = 0;
  while (42)
    {
      if (i == 0) display_map(game, nb_sticks);
      my_printf("\nYour turn:\n");
      if ((matches_nb = get_matches(game, nb_sticks, &line_nb, nb_max))
	  == -32)
	return (10);
      my_printf("Player removed %d", matches_nb);
      my_printf(" match(es) from line %d\n", line_nb);
      game = modifie_map(line_nb, matches_nb, game);
      display_map(game, nb_sticks);
      if ((win_o_lose(game, nb_sticks)) == 1)
	{
	  my_printf("You lost, too bad...\n");
	  return (2);
	}
      i = 1;
      if ((ia_turn(game, nb_sticks, nb_max)) == 1)
	return (1);
    }
}
