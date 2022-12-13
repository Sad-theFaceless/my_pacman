#include "pacman.h"

static void	ghost_move_blinky(t_pacman *pacman, int dir)
{
  if (dir == LEFT)
    pacman->blinky.pos.y = pacman->blinky.pos.y - 1;
  else if (dir == RIGHT)
    pacman->blinky.pos.y = pacman->blinky.pos.y + 1;
  else if (dir == UP)
    pacman->blinky.pos.x = pacman->blinky.pos.x - 1;
  else if (dir == DOWN)
    pacman->blinky.pos.x = pacman->blinky.pos.x + 1;
  if (dir == LEFT || dir == RIGHT || dir == UP || dir == DOWN)
    pacman->blinky.dir = dir;
}

static void	ghost_move_pinky(t_pacman *pacman, int dir)
{
  if (dir == LEFT)
    pacman->pinky.pos.y = pacman->pinky.pos.y - 1;
  else if (dir == RIGHT)
    pacman->pinky.pos.y = pacman->pinky.pos.y + 1;
  else if (dir == UP)
    pacman->pinky.pos.x = pacman->pinky.pos.x - 1;
  else if (dir == DOWN)
    pacman->pinky.pos.x = pacman->pinky.pos.x + 1;
  if (dir == LEFT || dir == RIGHT || dir == UP || dir == DOWN)
    pacman->pinky.dir = dir;
}

static void	ghost_move_inky(t_pacman *pacman, int dir)
{
  if (dir == LEFT)
    pacman->inky.pos.y = pacman->inky.pos.y - 1;
  else if (dir == RIGHT)
    pacman->inky.pos.y = pacman->inky.pos.y + 1;
  else if (dir == UP)
    pacman->inky.pos.x = pacman->inky.pos.x - 1;
  else if (dir == DOWN)
    pacman->inky.pos.x = pacman->inky.pos.x + 1;
  if (dir == LEFT || dir == RIGHT || dir == UP || dir == DOWN)
    pacman->inky.dir = dir;
}

static void	ghost_move_clyde(t_pacman *pacman, int dir)
{
  if (dir == LEFT)
    pacman->clyde.pos.y = pacman->clyde.pos.y - 1;
  else if (dir == RIGHT)
    pacman->clyde.pos.y = pacman->clyde.pos.y + 1;
  else if (dir == UP)
    pacman->clyde.pos.x = pacman->clyde.pos.x - 1;
  else if (dir == DOWN)
    pacman->clyde.pos.x = pacman->clyde.pos.x + 1;
  if (dir == LEFT || dir == RIGHT || dir == UP || dir == DOWN)
    pacman->clyde.dir = dir;
}

void	ghost_move(t_pacman *pacman, int ghost, int dir)
{
  if (ghost == BLINKY)
    ghost_move_blinky(pacman, dir);
  else if (ghost == PINKY)
    ghost_move_pinky(pacman, dir);
  else if (ghost == INKY)
    ghost_move_inky(pacman, dir);
  else if (ghost == CLYDE)
    ghost_move_clyde(pacman, dir);
}
