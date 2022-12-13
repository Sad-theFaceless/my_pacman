#include "pacman.h"

void    calc_poids(t_pacman *pacman, int x, int y)
{
  pacman->astar.map[x][y].G = abs(pacman->astar.map[x][y].pos.x -
				  pacman->astar.start.x) +
    abs(pacman->astar.map[x][y].pos.y -
	pacman->astar.start.y);
  pacman->astar.map[x][y].H = abs(pacman->astar.map[x][y].pos.x -
				  pacman->astar.end.x) +
    abs(pacman->astar.map[x][y].pos.y -
	pacman->astar.end.y);
  pacman->astar.map[x][y].F = pacman->astar.map[x][y].G +
    pacman->astar.map[x][y].H;
}

void    ghost_return_cage(t_pacman *pacman, int ghost)
{
  if (ghost == BLINKY && pacman->blinky.is_eat == 1)
    {
      pacman->astar.end.x = 14;
      pacman->astar.end.y = 12;
    }
  if (ghost == PINKY && pacman->pinky.is_eat == 1)
    {
      pacman->astar.end.x = 14;
      pacman->astar.end.y = 13;
    }
  if (ghost == INKY && pacman->inky.is_eat == 1)
    {
      pacman->astar.end.x = 14;
      pacman->astar.end.y = 14;
    }
  if (ghost == CLYDE && pacman->clyde.is_eat == 1)
    {
      pacman->astar.end.x = 14;
      pacman->astar.end.y = 15;
    }
}

void    ghost_leak_pos(t_pacman *pacman)
{
  if (pacman->pacman.pos.x >= (SIZE_MAP_X / 2) &&
      pacman->pacman.pos.y >= (SIZE_MAP_Y / 2))
    {
      pacman->astar.end.x = 1;
      pacman->astar.end.y = 1;
    }
  else if (pacman->pacman.pos.x < (SIZE_MAP_X / 2) &&
	   pacman->pacman.pos.y < (SIZE_MAP_Y / 2))
    {
      pacman->astar.end.x = 29;
      pacman->astar.end.y = 26;
    }
  else if (pacman->pacman.pos.x >= (SIZE_MAP_X / 2) &&
	   pacman->pacman.pos.y < (SIZE_MAP_Y / 2))
    {
      pacman->astar.end.x = 1;
      pacman->astar.end.y = 26;
    }
  else if (pacman->pacman.pos.x < (SIZE_MAP_X / 2) &&
	   pacman->pacman.pos.y >= (SIZE_MAP_Y / 2))
    {
      pacman->astar.end.x = 29;
      pacman->astar.end.y = 1;
    }
}

int     get_dir(t_pos old, t_pos new, t_pacman *pacman)
{
  if (new.x > old.x && pacman->map[new.x][new.y] != '#')
    return (DOWN);
  else if (new.x < old.x && pacman->map[new.x][new.y] != '#')
    return (UP);
  else if (new.y > old.y && pacman->map[new.x][new.y] != '#')
    return (RIGHT);
  else if (new.y < old.y && pacman->map[new.x][new.y] != '#')
    return (LEFT);
  return (-1);
}

void    astar_raz(t_pacman *pacman)
{
  int   i;
  int   j;

  i = -1;
  while (++i < SIZE_MAP_Y)
    {
      j = -1;
      while (++j < SIZE_MAP_X)
	{
	  pacman->astar.map[i][j].pos.x = i;
	  pacman->astar.map[i][j].pos.y = j;
	  pacman->astar.map[i][j].F = MAX_INT;
	  pacman->astar.map[i][j].G = MAX_INT;
	  pacman->astar.map[i][j].H = MAX_INT;
	  pacman->astar.map[i][j].parent.x = -1;
	  pacman->astar.map[i][j].parent.y = -1;
	            pacman->astar.map[i][j].obst =
		      ((pacman->map[i][j] == '#') ? 1 : 0);
		    pacman->astar.map[i][j].list = BLANK;
	}
    }
  pacman->astar.map[14][0].obst = 1;
  pacman->astar.map[14][27].obst = 1;
}
