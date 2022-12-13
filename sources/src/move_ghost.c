#include "pacman.h"

static void	move_blinky(t_pacman *pacman, int dir)
{
  if (dir == LEFT &&
      pacman->map[pacman->blinky.pos.x][pacman->blinky.pos.y - 1] != '#')
    ghost_move(pacman, BLINKY, LEFT);
  else if (dir == RIGHT &&
	   pacman->map[pacman->blinky.pos.x][pacman->blinky.pos.y + 1] != '#')
    ghost_move(pacman, BLINKY, RIGHT);
  else if (dir == UP &&
	   pacman->map[pacman->blinky.pos.x - 1][pacman->blinky.pos.y] != '#')
    ghost_move(pacman, BLINKY, UP);
  else if (dir == DOWN &&
	   pacman->map[pacman->blinky.pos.x + 1][pacman->blinky.pos.y] != '#' &&
	   pacman->map[pacman->blinky.pos.x + 1][pacman->blinky.pos.y] != '-')
    ghost_move(pacman, BLINKY, DOWN);
}

static void	move_pinky(t_pacman *pacman, int dir)
{
  if (dir == LEFT &&
      pacman->map[pacman->pinky.pos.x][pacman->pinky.pos.y - 1] != '#')
    ghost_move(pacman, PINKY, LEFT);
  else if (dir == RIGHT &&
	   pacman->map[pacman->pinky.pos.x][pacman->pinky.pos.y + 1] != '#')
    ghost_move(pacman, PINKY, RIGHT);
  else if (dir == UP &&
	   pacman->map[pacman->pinky.pos.x - 1][pacman->pinky.pos.y] != '#')
    ghost_move(pacman, PINKY, UP);
  else if (dir == DOWN &&
	   pacman->map[pacman->pinky.pos.x + 1][pacman->pinky.pos.y] != '#' &&
	   pacman->map[pacman->pinky.pos.x + 1][pacman->pinky.pos.y] != '-')
    ghost_move(pacman, PINKY, DOWN);
}

static void	move_inky(t_pacman *pacman, int dir)
{
  if (dir == LEFT &&
      pacman->map[pacman->inky.pos.x][pacman->inky.pos.y - 1] != '#')
    ghost_move(pacman, INKY, LEFT);
  else if (dir == RIGHT &&
	   pacman->map[pacman->inky.pos.x][pacman->inky.pos.y + 1] != '#')
    ghost_move(pacman, INKY, RIGHT);
  else if (dir == UP &&
	   pacman->map[pacman->inky.pos.x - 1][pacman->inky.pos.y] != '#')
    ghost_move(pacman, INKY, UP);
  else if (dir == DOWN &&
	   pacman->map[pacman->inky.pos.x + 1][pacman->inky.pos.y] != '#' &&
	   pacman->map[pacman->inky.pos.x + 1][pacman->inky.pos.y] != '-')
    ghost_move(pacman, INKY, DOWN);
}

static void	move_clyde(t_pacman *pacman, int dir)
{
  if (dir == LEFT &&
      pacman->map[pacman->clyde.pos.x][pacman->clyde.pos.y - 1] != '#')
    ghost_move(pacman, CLYDE, LEFT);
  else if (dir == RIGHT &&
	   pacman->map[pacman->clyde.pos.x][pacman->clyde.pos.y + 1] != '#')
    ghost_move(pacman, CLYDE, RIGHT);
  else if (dir == UP &&
	   pacman->map[pacman->clyde.pos.x - 1][pacman->clyde.pos.y] != '#')
    ghost_move(pacman, CLYDE, UP);
  else if (dir == DOWN &&
	   pacman->map[pacman->clyde.pos.x + 1][pacman->clyde.pos.y] != '#' &&
	   pacman->map[pacman->clyde.pos.x + 1][pacman->clyde.pos.y] != '-')
    ghost_move(pacman, CLYDE, DOWN);
}

void	move_ghost(t_pacman *pacman, int dir, int ghost)
{
  if (ghost == BLINKY)
    move_blinky(pacman, dir);
  else if (ghost == PINKY)
    move_pinky(pacman, dir);
  else if (ghost == INKY)
    move_inky(pacman, dir);
  else if (ghost == CLYDE)
    move_clyde(pacman, dir);
}
