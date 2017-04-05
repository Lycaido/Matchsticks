/*
** my.h for bootstrap in /home/Rev/CSFML/bootstrap
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Thu Nov	10 10:15:08 2016 Roméo Nahon
** Last update	Thu Nov	10 10:15:08 2016 Roméo Nahon
*/

#ifndef MY_H
# define MY_H

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>

void	my_strerror(char *str);
int	my_printf(char *str, ...);
char	*my_memset(char *str, char, int);
int	my_getnbr(char *);
char	*get_next_line(int);
int	my_strlen(char *);
int	my_strcmp(char *, char *);
char	*intoarg(int, int);
int	my_intlen(int);

typedef struct	s_draw
{
  int	actual_nb_sticks;
  int	width;
  int	r;
  int	c;
  int	j;
}		t_draw;

int	error_manager(int ac, char **av);
int	check_line(char *coord, int nb_sticks);
int	check_matches(char *matches, char **game, int, int);
int	check_total_line(char **game, char *line, int);

int	check_matches_next(char *matches, int nb_max, int line, char **);
int	check_matches_on_line(char *matches, int line, char **);
int	check_empty_lenght_line(char *coord);

char	**draw_game(int nb_sticks);
char	**draw_sticks(int i, char **game, int, int);
char	*draw_more(t_draw *draw, char *game, int i);

void	display_map(char **game, int);

int	matchsticks(char **game, int nb_sticks, int);
int	get_line(char **game, int);
int	get_matches(char **game, int nb_sticks, int*, int);
char	**modifie_map(int line, int matches, char **game);
int	win_o_lose(char **game, int);

int	ia_weak(char **game, int nb_sticks, int *, int);
int	ia_turn(char **game, int nb_sticks, int);

#endif /* MY_H */
