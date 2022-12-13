#include "pacman.h"

void		anticipate_move_pacman(t_pacman *pacman)
{
  t_pos		next;
  int		dir;
  int		clyde_like;

  next.x = pacman->pacman.pos.x;
  next.y = pacman->pacman.pos.y;
  if (verif_and_get_move_segf(pacman) == 1)
    return ;
  dir = pacman->pacman.dir;
  while (nbr_path(pacman, next.x, next.y) == 2)
    {
      if (autorize_dir_virtual(pacman, &next, dir) == 0)
  	{
  	  clyde_like = rand() % 4 + 1;
  	  while (autorize_dir_virtual(pacman, &next, clyde_like) == 0 ||
  		 clyde_like == contrary(dir))
  	    clyde_like = rand() % 4 + 1;
  	  dir = clyde_like;
  	}
      move_pos_virtual(pacman, &next, dir);
    }
  pacman->astar.end.x = next.x;
  pacman->astar.end.y = next.y;
}

int	contrary(int dir)
{
  if (dir == RIGHT)
    return (LEFT);
  else if (dir == LEFT)
    return (RIGHT);
  else if (dir == UP)
    return (DOWN);
  else if (dir == DOWN)
    return (UP);
  else
    return (-1);
}
