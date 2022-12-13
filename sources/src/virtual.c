#include "pacman.h"

void	move_pos_virtual(t_pacman *pacman, t_pos *next, int dir)
{
  if (dir == RIGHT)
    {
      if (autorize_dir_virtual(pacman, next, dir) != 0)
	next->y = next->y + 1;
    }
  else if (dir == LEFT)
    {
      if (autorize_dir_virtual(pacman, next, dir) != 0)
	next->y = next->y - 1;
    }
  else if (dir == UP)
    {
      if (autorize_dir_virtual(pacman, next, dir) != 0)
	next->x = next->x - 1;
    }
  else if (dir == DOWN)
    {
      if (autorize_dir_virtual(pacman, next, dir) != 0)
	next->x = next->x + 1;
    }
}

int     autorize_dir_virtual(t_pacman *pacman, t_pos *pos, int dir)
{
  if (dir == RIGHT)
    {
      if (pacman->map[pos->x][pos->y + 1] == '#')
	return (0);
    }
  else if (dir == LEFT)
    {
      if (pacman->map[pos->x][pos->y - 1] == '#')
	return (0);
    }
  else if (dir == UP)
    {
      if (pacman->map[pos->x - 1][pos->y] == '#')
	return (0);
    }
  else if (dir == DOWN)
    {
      if (pacman->map[pos->x + 1][pos->y] == '#')
	return (0);
    }
  return (1);
}
