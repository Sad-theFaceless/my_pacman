#include "pacman.h"

int	verif_and_get_move_segf(t_pacman *pacman)
{
  if (pacman->pacman.pos.x == 14 &&
      (pacman->pacman.pos.y <= 6 || pacman->pacman.pos.y >= 21))
    {
      pacman->astar.end.x = pacman->pacman.pos.x;
      pacman->astar.end.y = pacman->pacman.pos.y;
      return (1);
    }
  return (0);
}

void	ia_alea(t_pacman *pacman, int ghost)
{
  int	clyde_like;

  clyde_like = 0;
  while (autorize_move_ghost(pacman, clyde_like, ghost) == 0)
    {
      clyde_like = rand() % 4;
      clyde_like++;
    }
  move_ghost(pacman, clyde_like, ghost);
}

int	autorize_move_ghost(t_pacman *pacman, int dir, int ghost)
{
  int	autorize_move;
  int	x;
  int	y;

  get_pos_ghost(pacman, ghost, &x, &y);
  autorize_move = 0;
  if (dir == LEFT &&
      pacman->map[x][y - 1] != '#')
    autorize_move++;
  else if (dir == RIGHT &&
	   pacman->map[x][y + 1] != '#')
    autorize_move++;
  else if (dir == UP &&
	   pacman->map[x - 1][y] != '#')
    autorize_move++;
  else if (dir == DOWN &&
	   pacman->map[x + 1][y] != '#' &&
	   pacman->map[x + 1][y] != '-')
    autorize_move++;
  return (autorize_move);
}
