#include "pacman.h"

static void	get_pacgomme(t_pacman *pacman)
{
  if (pacman->map[pacman->pacman.pos.x][pacman->pacman.pos.y] == '.')
    {
      pacman->map[pacman->pacman.pos.x][pacman->pacman.pos.y] = ' ';
      up_score(pacman, 10);
    }
  else if (pacman->map[pacman->pacman.pos.x][pacman->pacman.pos.y] == '*')
    {
      pacman->map[pacman->pacman.pos.x][pacman->pacman.pos.y] = ' ';
      up_score(pacman, 50);
      ghost_fear(pacman);
    }
}

static int	get_key(t_pacman *pacman)
{
  int		ch;

  ch = 0;
  ch = getch();
  if (ch == 27)
    return (1);
  else if (ch == KEY_LEFT || ch == 'q')
    pacman->dir_key = LEFT;
  else if (ch == KEY_RIGHT || ch == 'd')
    pacman->dir_key = RIGHT;
  else if (ch == KEY_UP || ch == 'z')
    pacman->dir_key = UP;
  else if (ch == KEY_DOWN || ch == 's')
    pacman->dir_key = DOWN;
  return (0);
}

static void	is_high_score(t_pacman *pacman)
{
  if (pacman->score > pacman->high_score)
    pacman->high_score = pacman->score;
}

static void	verif_level(t_pacman *pacman)
{
  int		i;
  int		j;
  int		count_pacgommes;

  count_pacgommes = 0;
  i = 0;
  while (i < SIZE_MAP_Y)
    {
      j = 0;
      while (j < SIZE_MAP_X)
	{
	  if (pacman->map[i][j] == '.' || pacman->map[i][j] == '*')
	    count_pacgommes++;
	  j++;
	}
      i++;
    }
  if (count_pacgommes == 0)
    next_level(pacman);
}

int	start_game(t_pacman *pacman)
{
  if (get_key(pacman) != 0)
    return (1);
  get_pacgomme(pacman);
  move_pacman(pacman);
  if (verif_dead(pacman) == 1)
    return (0);
  get_pacgomme(pacman);
  get_fruit(pacman);
  verif_fruit(pacman);
  is_high_score(pacman);
  verif_level(pacman);
  return (0);
}
