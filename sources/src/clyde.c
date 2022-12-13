#include "pacman.h"

static void	continue_path(t_pacman *pacman)
{
  int		clyde_like;

  clyde_like = rand() % 4 + 1;
  while (autorize_move_ghost(pacman, clyde_like, CLYDE) == 0 ||
	 clyde_like == contrary(pacman->clyde.dir))
    clyde_like = rand() % 4 + 1;
  ghost_move(pacman, CLYDE, clyde_like);
}

void	clyde_rand_move(t_pacman *pacman)
{
  int	clyde_like;

  if ((pacman->clyde.pos.x >= 12 && pacman->clyde.pos.x <= 16) &&
      (pacman->clyde.pos.y >= 10 && pacman->clyde.pos.y <= 17))
    {
      pacman->astar.start.x = pacman->clyde.pos.x;
      pacman->astar.start.y = pacman->clyde.pos.y;
      pacman->astar.end.x = 11;
      pacman->astar.end.y = 14;
      ghost_move(pacman, CLYDE,
		 get_dir(pacman->clyde.pos, start_astar(pacman), pacman));
      return ;
    }
  if (nbr_path(pacman, pacman->clyde.pos.x, pacman->clyde.pos.y) == 2)
    {
      if (autorize_move_ghost(pacman, pacman->clyde.dir, CLYDE) != 0)
	ghost_move(pacman, CLYDE, pacman->clyde.dir);
      else
	continue_path(pacman);
      return ;
    }
  clyde_like = rand() % 4 + 1;
  while (autorize_move_ghost(pacman, clyde_like, CLYDE) == 0)
    clyde_like = rand() % 4 + 1;
  ghost_move(pacman, CLYDE, clyde_like);
}
