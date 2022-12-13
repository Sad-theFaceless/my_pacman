#include "pacman.h"

static void	deplace_pacman(t_pacman *pacman)
{
  if (pacman->pacman.dir == LEFT &&
      pacman->map[pacman->pacman.pos.x][pacman->pacman.pos.y - 1] != '#')
    pacman->pacman.pos.y = pacman->pacman.pos.y - 1;
  else if (pacman->pacman.dir == RIGHT &&
	   pacman->map[pacman->pacman.pos.x][pacman->pacman.pos.y + 1] != '#')
    pacman->pacman.pos.y = pacman->pacman.pos.y + 1;
  else if (pacman->pacman.dir == UP &&
	   pacman->map[pacman->pacman.pos.x - 1][pacman->pacman.pos.y] != '#')
    pacman->pacman.pos.x = pacman->pacman.pos.x - 1;
  else if (pacman->pacman.dir == DOWN &&
	   pacman->map[pacman->pacman.pos.x + 1][pacman->pacman.pos.y] != '#' &&
	   pacman->map[pacman->pacman.pos.x + 1][pacman->pacman.pos.y] != '-')
    pacman->pacman.pos.x = pacman->pacman.pos.x + 1;
}

static void     teleport_pacman(t_pacman *pacman)
{
  if (pacman->pacman.pos.x == 14)
    {
      if (pacman->pacman.pos.y == 1 && pacman->pacman.dir == LEFT)
	pacman->pacman.pos.y = 27;
      if (pacman->pacman.pos.y == 26 && pacman->pacman.dir == RIGHT)
	pacman->pacman.pos.y = 0;
    }
}

static void	autorize_dir(t_pacman *pacman)
{
  if (pacman->dir_key == LEFT &&
      pacman->map[pacman->pacman.pos.x][pacman->pacman.pos.y - 1] != '#')
    pacman->pacman.dir = LEFT;
  else if (pacman->dir_key == RIGHT &&
	   pacman->map[pacman->pacman.pos.x][pacman->pacman.pos.y + 1] != '#')
    pacman->pacman.dir = RIGHT;
  else if (pacman->dir_key == UP &&
	   pacman->map[pacman->pacman.pos.x - 1][pacman->pacman.pos.y] != '#')
    pacman->pacman.dir = UP;
  else if (pacman->dir_key == DOWN &&
	   pacman->map[pacman->pacman.pos.x + 1][pacman->pacman.pos.y] != '#' &&
	   pacman->map[pacman->pacman.pos.x + 1][pacman->pacman.pos.y] != '-')
    pacman->pacman.dir = DOWN;
}

void	move_pacman(t_pacman *pacman)
{
  autorize_dir(pacman);
  teleport_pacman(pacman);
  deplace_pacman(pacman);
}
