#include "pacman.h"

static void	print_map_3(t_pacman *pacman, int i, int j, int *k)
{
  if (pacman->map[i][j] == '.' || pacman->map[i][j] == '*')
    {
      attron(A_BOLD);
      mvprintw(i, j + *k, "%c", pacman->map[i][j]);
      if (j < (SIZE_MAP_X / 2))
	mvprintw(i, j + (*k = *k + 1), " ");
      else
	{
	  mvprintw(i, j + *k, " ");
	  mvprintw(i, j + (*k = *k + 1), "%c", pacman->map[i][j]);
	}
      attroff(A_BOLD);
    }
  else if (pacman->map[i][j] == '-')
    {
      attron(A_BOLD);
      mvprintw(i, j + *k, "%c", pacman->map[i][j]);
      mvprintw(i, j + (*k = *k + 1), "-");
      attroff(A_BOLD);
    }
  else if (pacman->map[i][j] == ' ')
    {
      mvprintw(i, j + *k, "%c", pacman->map[i][j]);
      mvprintw(i, j + (*k = *k + 1), " ");
    }
}

static void	print_map_2(t_pacman *pacman, int i, int j, int *k)
{
  color_start(pacman->map[i][j]);
  if (pacman->map[i][j] == '#')
    {
      mvprintw(i, j + *k, "#");
      mvprintw(i, j + (*k = *k + 1), "#");
    }
  else
    print_map_3(pacman, i, j, k);
  color_stop(pacman->map[i][j]);
}

void	print_map(t_pacman *pacman)
{
  int	i;
  int	j;
  int	k;

  i = -1;
  while (++i < SIZE_MAP_Y)
    {
      j = -1;
      k = 0;
      while (++j < SIZE_MAP_X)
	print_map_2(pacman, i, j, &k);
    }
}
