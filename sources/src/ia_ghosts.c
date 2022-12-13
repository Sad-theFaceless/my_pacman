#include "pacman.h"

static void	blinky(t_pacman *pacman)
{
  static int	scatter = 0;

  if (pacman->blinky.waiting > 0)
    {
      pacman->blinky.waiting = pacman->blinky.waiting - 1;
      return ;
    }
  if (pacman->blinky.pos.x == 14 && pacman->blinky.pos.y == 12)
    pacman->blinky.is_eat = 0;
  scatter++;
  pacman->astar.start.x = pacman->blinky.pos.x;
  pacman->astar.start.y = pacman->blinky.pos.y;
  if (pacman->blinky.is_eat == 1)
    ghost_return_cage(pacman, BLINKY);
  else if (scatter >= 100 || scatter < (70 + 2 * (pacman->level - 1)))
    {
      pacman->astar.end.x = pacman->pacman.pos.x;
      pacman->astar.end.y = pacman->pacman.pos.y;
      if (scatter >= 100)
	scatter = 0;
    }
  else
    ghost_leak_pos(pacman);
  ghost_move(pacman, BLINKY,
	     get_dir(pacman->blinky.pos, start_astar(pacman), pacman));
}

static void	pinky(t_pacman *pacman)
{
  static int    scatter = 0;

  if (pacman->pinky.waiting > 0)
    {
      pacman->pinky.waiting = pacman->pinky.waiting - 1;
      return ;
    }
  if (pacman->pinky.pos.x == 14 && pacman->pinky.pos.y == 13)
    pacman->pinky.is_eat = 0;
  scatter++;
  pacman->astar.start.x = pacman->pinky.pos.x;
  pacman->astar.start.y = pacman->pinky.pos.y;
  if (pacman->pinky.is_eat == 1)
    ghost_return_cage(pacman, PINKY);
  else if (scatter >= 100 || scatter < (70 + 2 * (pacman->level - 1)))
    {
      anticipate_move_pacman(pacman);
      if (scatter >= 100)
	scatter = 0;
    }
  else
    ghost_leak_pos(pacman);
  ghost_move(pacman, PINKY,
	     get_dir(pacman->pinky.pos, start_astar(pacman), pacman));
}

static void	inky(t_pacman *pacman)
{
  static int	what_ia = 0;

  if (pacman->inky.waiting > 0)
    {
      pacman->inky.waiting = pacman->inky.waiting - 1;
      return ;
    }
  if (pacman->inky.pos.x == 14 && pacman->inky.pos.y == 14)
    pacman->inky.is_eat = 0;
  if (nbr_path(pacman, pacman->inky.pos.x, pacman->inky.pos.y) > 2)
    what_ia = rand() % 2;
  if (what_ia == 0)
    inky_ia_pinky(pacman);
  else if (what_ia == 1)
    inky_ia_clyde(pacman);
}

static void	clyde(t_pacman *pacman)
{
  if (pacman->clyde.waiting > 0)
    {
      pacman->clyde.waiting = pacman->clyde.waiting - 1;
      return ;
    }
  if (pacman->clyde.pos.x == 14 && pacman->clyde.pos.y == 15)
    pacman->clyde.is_eat = 0;
  if (pacman->clyde.is_eat == 1)
    {
      pacman->astar.start.x = pacman->clyde.pos.x;
      pacman->astar.start.y = pacman->clyde.pos.y;
      ghost_return_cage(pacman, CLYDE);
      ghost_move(pacman, CLYDE,
		 get_dir(pacman->clyde.pos, start_astar(pacman), pacman));
    }
  else
    clyde_rand_move(pacman);
}

void	move_ghosts(t_pacman *pacman)
{
  blinky(pacman);
  pinky(pacman);
  inky(pacman);
  clyde(pacman);
}
