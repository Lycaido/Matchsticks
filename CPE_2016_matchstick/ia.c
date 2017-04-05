/*
** ia.c for matchsticks in /home/Rev/CPE_2016_matchstick
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Feb	13 19:22:21 2017 Roméo Nahon
** Last update	Sun Feb	26 11:39:24 2017 Roméo Nahon
*/

#include "include/my.h"

int	count_line(char *game)
{
  int	i;
  int	nb;

  i = -1;
  nb = 0;
  while (game[++i] != '\0')
    {
      if (game[i] == '|')
	nb += 1;
    }
  return (nb);
}

int	ia_weak(char **game, int nb_sticks, int *line, int nb_max)
{
  int	matches;
  int	i;
  int	j;
  int	nb_matches;
  int	k;

  i = -1;
  j = -1;
  nb_matches = 0;
  while (i == -1)
    {
      k = -1;
      j += 1;
      while (game[j][++k])
	if (game[j][k] == '|' && game[j][k] != ' ' && game[j][k] != '*')
	  nb_matches += 1;
      if (nb_matches > 0) i = 0;
    }
  *line = j;
  while (nb_matches > nb_max)
    nb_matches -= 1;
  if ((nb_matches % 2) == 1)
    return ((nb_matches / 2) + 1);
  else
    return ((nb_matches / 2));
}

int	ia_turn(char **game, int nb_sticks, int nb_max)
{
  int	line_ia;
  int	matches_ia;

  line_ia = 0;
  my_printf("\nAI's turn...\n");
  matches_ia = ia_weak(game, nb_sticks, &line_ia, nb_max);
  my_printf("AI removed %d match(es) from line %d\n", matches_ia, line_ia);
  game = modifie_map(line_ia, matches_ia, game);
  display_map(game, nb_sticks);
  if ((win_o_lose(game, nb_sticks)) == 1)
    {
      my_printf("I lost... snif... but I’ll get you next time!!\n");
      return (1);
    }
  return (0);
}
