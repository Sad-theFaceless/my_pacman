#include "pacman.h"

void	inky_ia_clyde(t_pacman *pacman)
{
  if (pacman->inky.is_eat == 1)
    {
      pacman->astar.start.x = pacman->inky.pos.x;
      pacman->astar.start.y = pacman->inky.pos.y;
      ghost_return_cage(pacman, INKY);
      ghost_move(pacman, INKY,
		 get_dir(pacman->inky.pos, start_astar(pacman), pacman));
    }
  else
    inky_rand_move(pacman);
}

void		inky_ia_pinky(t_pacman *pacman)
{
  static int	scatter = 0;

  scatter++;
  pacman->astar.start.x = pacman->inky.pos.x;
  pacman->astar.start.y = pacman->inky.pos.y;
  if (pacman->inky.is_eat == 1)
    ghost_return_cage(pacman, INKY);
  else if (scatter >= 100 || scatter < (70 + 2 * (pacman->level - 1)))
    {
      anticipate_move_pacman(pacman);
      if (scatter >= 100)
	scatter = 0;
    }
  else
    ghost_leak_pos(pacman);
  ghost_move(pacman, INKY,
	     get_dir(pacman->inky.pos, start_astar(pacman), pacman));
}

static void	continue_path(t_pacman *pacman)
{
  int		clyde_like;

  clyde_like = rand() % 4 + 1;
  while (autorize_move_ghost(pacman, clyde_like, INKY) == 0 ||
	 clyde_like == contrary(pacman->inky.dir))
    clyde_like = rand() % 4 + 1;
  ghost_move(pacman, INKY, clyde_like);
}

void	inky_rand_move(t_pacman *pacman)
{
  int	clyde_like;

  if ((pacman->inky.pos.x >= 12 && pacman->inky.pos.x <= 16) &&
      (pacman->inky.pos.y >= 10 && pacman->inky.pos.y <= 17))
    {
      pacman->astar.start.x = pacman->inky.pos.x;
      pacman->astar.start.y = pacman->inky.pos.y;
      pacman->astar.end.x = 11;
      pacman->astar.end.y = 14;
      ghost_move(pacman, INKY,
		 get_dir(pacman->inky.pos, start_astar(pacman), pacman));
      return ;
    }
  if (nbr_path(pacman, pacman->inky.pos.x, pacman->inky.pos.y) == 2)
    {
      if (autorize_move_ghost(pacman, pacman->inky.dir, INKY) != 0)
	ghost_move(pacman, INKY, pacman->inky.dir);
      else
	continue_path(pacman);
      return ;
    }
  clyde_like = rand() % 4 + 1;
  while (autorize_move_ghost(pacman, clyde_like, INKY) == 0)
    clyde_like = rand() % 4 + 1;
  ghost_move(pacman, INKY, clyde_like);
}
