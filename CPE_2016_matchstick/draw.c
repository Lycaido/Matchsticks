/*
** draw.c for matchstick in /home/Rev/CPE_2016_matchstick
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Feb	13 09:31:06 2017 Roméo Nahon
** Last update	Mon Feb	13 09:31:06 2017 Roméo Nahon
*/

#include "include/my.h"

char	*draw_more(t_draw *draw, char *game, int i)
{
  char	*new_game;

  draw->c = draw->j - 1;
  while (++(draw->r) < draw->actual_nb_sticks + 1)
    {
      game[draw->j++] = '|';
      game[draw->j] = ' ';
      if (draw->j == draw->width - 1)
	game[draw->j] = '*';
    }
  draw->r = 0;
  while (++(draw->r) < draw->actual_nb_sticks)
    game[draw->c--] = '|';
  draw->actual_nb_sticks += 1;
  return (game);
}

char	**draw_sticks(int i,
		      char **game,
		      int final_nb_sticks,
		      int nb_sticks)
{
  t_draw	*draw;

  if ((draw = malloc(sizeof(t_draw))) == NULL) return (NULL);
  draw->width = final_nb_sticks + 2;
  draw->actual_nb_sticks = 1;
  while (++i < nb_sticks + 2)
    {
      if ((game[i] = malloc(sizeof(char) * draw->width)) == NULL)
	return (NULL);
      game[i] = my_memset(game[i], '\0', draw->width);
      draw->r = 0;
      draw->j = -1;
      while (++draw->j < draw->width)
	{
	  if (i == 0 || i == (nb_sticks + 2) - 1) game[i][draw->j] = '*';
	  else if (draw->j == 0 || draw->j == draw->width - 1)
	    game[i][draw->j] = '*';
	  else if (draw->j == draw->width / 2)
	    game[i] = draw_more(draw, game[i], i);
	  else
	    game[i][draw->j] = ' ';
	}
    }
  return (game);
}
char	**draw_game(int nb_sticks)
{
  char	**game;
  int	final_nb_sticks;
  int	i;

  i = -1;
  if ((game = malloc(sizeof(char *) * nb_sticks + 2)) == NULL)
    return (NULL);
  final_nb_sticks = 1;
  while (++i < nb_sticks - 1)
    final_nb_sticks = final_nb_sticks + 2;
  i = -1;
  game = draw_sticks(i, game, final_nb_sticks, nb_sticks);
  return (game);
}
