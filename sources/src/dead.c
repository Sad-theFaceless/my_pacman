#include "pacman.h"

static void	lose(t_pacman *pacman)
{
  usleep(1 * SECOND);
  pacman->lifes = pacman->lifes - 1;
  pacman->dir_key = LEFT;
  pacman->pacman.dir = LEFT;
  pacman->pacman.pos.x = 23;
  pacman->pacman.pos.y = 14;
  pacman->blinky.pos.x = 14;
  pacman->blinky.pos.y = 12;
  pacman->pinky.pos.x = 14;
  pacman->pinky.pos.y = 13;
  pacman->inky.pos.x = 14;
  pacman->inky.pos.y = 14;
  pacman->clyde.pos.x = 14;
  pacman->clyde.pos.y = 15;
  pacman->blinky.waiting = 2 * 4;
  pacman->pinky.waiting = 4 * 4;
  pacman->inky.waiting = 6 * 4;
  pacman->clyde.waiting = 8 * 4;
}

static void	eat_ghost(t_pacman *pacman)
{
  up_score(pacman, 200);
  if (pacman->blinky.pos.x == pacman->pacman.pos.x &&
      pacman->blinky.pos.y == pacman->pacman.pos.y)
    {
      pacman->blinky.is_eat = 1;
    }
  if (pacman->pinky.pos.x == pacman->pacman.pos.x &&
      pacman->pinky.pos.y == pacman->pacman.pos.y)
    {
      pacman->pinky.is_eat = 1;
    }
  if (pacman->inky.pos.x == pacman->pacman.pos.x &&
      pacman->inky.pos.y == pacman->pacman.pos.y)
    {
      pacman->inky.is_eat = 1;
    }
  if (pacman->clyde.pos.x == pacman->pacman.pos.x &&
      pacman->clyde.pos.y == pacman->pacman.pos.y)
    {
      pacman->clyde.is_eat = 1;
    }
}

int	verif_dead(t_pacman *pacman)
{
  if ((pacman->blinky.pos.x == pacman->pacman.pos.x &&
       pacman->blinky.pos.y == pacman->pacman.pos.y) ||
      (pacman->pinky.pos.x == pacman->pacman.pos.x &&
       pacman->pinky.pos.y == pacman->pacman.pos.y) ||
      (pacman->inky.pos.x == pacman->pacman.pos.x &&
       pacman->inky.pos.y == pacman->pacman.pos.y) ||
      (pacman->clyde.pos.x == pacman->pacman.pos.x &&
       pacman->clyde.pos.y == pacman->pacman.pos.y))
    {
      print_game(pacman);
      if (g_ghost_fear == 0)
	lose(pacman);
      else
	eat_ghost(pacman);
      return (1);
    }
  return (0);
}
