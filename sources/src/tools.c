#include "pacman.h"

int	nbr_path(t_pacman *pacman, int x, int y)
{
  int	nbr_path;

  nbr_path = 0;
  if (pacman->map[x][y - 1] != '#' && pacman->map[x][y - 1] != '-')
    nbr_path++;
  if (pacman->map[x][y + 1] != '#' && pacman->map[x][y + 1] != '-')
    nbr_path++;
  if (pacman->map[x - 1][y] != '#' && pacman->map[x - 1][y] != '-')
    nbr_path++;
  if (pacman->map[x + 1][y] != '#' && pacman->map[x + 1][y] != '-')
    nbr_path++;
  return (nbr_path);
}

int	verif_is_out(t_pacman *pacman, int x, int y)
{
  if (pacman->map[x + 1][y] == '-')
    return (1);
  else
    return (0);
}

void	get_pos_ghost(t_pacman *pacman, int ghost, int *x, int *y)
{
  if (ghost == BLINKY)
    {
      *x = pacman->blinky.pos.x;
      *y = pacman->blinky.pos.y;
    }
  else if (ghost == PINKY)
    {
      *x = pacman->pinky.pos.x;
      *y = pacman->pinky.pos.y;
    }
  else if (ghost == INKY)
    {
      *x = pacman->inky.pos.x;
      *y = pacman->inky.pos.y;
    }
  else if (ghost == CLYDE)
    {
      *x = pacman->clyde.pos.x;
      *y = pacman->clyde.pos.y;
    }
}

int	pos_center(int tmp)
{
  int	i;

  i = 0;
  while (tmp / 10 > 0)
    {
      tmp = tmp / 10;
      i = i + 1;
    }
  i = i - (i / 2);
  return (i);
}
