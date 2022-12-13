#include "pacman.h"

static void	get_current_node(t_pacman *pacman)
{
  int		i;
  int		j;
  t_pos		pos;
  int		min_F;

  min_F = MAX_INT;
  pos.x = -1;
  pos.y = -1;
  i = -1;
  while (++i < SIZE_MAP_Y)
    {
      j = -1;
      while (++j < SIZE_MAP_X)
	if (pacman->astar.map[i][j].F < min_F &&
	    pacman->astar.map[i][j].list == OPEN)
	  {
	    min_F = pacman->astar.map[i][j].F;
	    pos.x = i;
	    pos.y = j;
	  }
    }
  pacman->astar.cur.x = pos.x;
  pacman->astar.cur.y = pos.y;
}

static void     astar_step_2(t_pacman *pacman, int x, int y)
{
  if (pacman->astar.map[x][y].obst == 1 ||
      pacman->astar.map[x][y].list == CLOSE)
    return ;
  else if (pacman->astar.map[x][y].list != OPEN)
    {
      calc_poids(pacman, x, y);
      pacman->astar.map[x][y].list = OPEN;
      pacman->astar.map[x][y].parent.x = pacman->astar.cur.x;
      pacman->astar.map[x][y].parent.y = pacman->astar.cur.y;
    }
}

static t_pos	get_new_pos(t_pacman *pacman)
{
  t_pos		one;
  t_pos		two;

  one.x = pacman->astar.end.x;
  one.y = pacman->astar.end.y;
  two.x = pacman->astar.map[one.x][one.y].parent.x;
  two.y = pacman->astar.map[one.x][one.y].parent.y;
  while (!(pacman->astar.map[two.x][two.y].parent.x == -1 &&
	   pacman->astar.map[two.x][two.y].parent.y == -1))
    {
      one.x = two.x;
      one.y = two.y;
      two.x = pacman->astar.map[one.x][one.y].parent.x;
      two.y = pacman->astar.map[one.x][one.y].parent.y;
    }
  return (one);
}

static int	nbr_open(t_pacman *pacman)
{
  int		i;
  int		j;
  int		nb_open;

  nb_open = 0;
  i = -1;
  while (++i < SIZE_MAP_Y)
    {
      j = -1;
      while (++j < SIZE_MAP_X)
	{
	  if (pacman->astar.map[i][j].list == OPEN)
	    nb_open++;
	}
    }
  return (nb_open);
}

t_pos	start_astar(t_pacman *pacman)
{
  astar_raz(pacman);
  if (pacman->astar.start.x == pacman->astar.end.x &&
      pacman->astar.start.y == pacman->astar.end.y)
    return (pacman->astar.end);
  pacman->astar.cur.x = pacman->astar.start.x;
  pacman->astar.cur.y = pacman->astar.start.y;
  pacman->astar.map[pacman->astar.start.x]
    [pacman->astar.start.y].list = OPEN;
  calc_poids(pacman, pacman->astar.start.x, pacman->astar.start.y);
  get_current_node(pacman);
  while ((!(pacman->astar.cur.x == pacman->astar.end.x &&
	    pacman->astar.cur.y == pacman->astar.end.y)) ||
	 nbr_open(pacman))
    {
      get_current_node(pacman);
      pacman->astar.map[pacman->astar.cur.x][pacman->astar.cur.y].list = CLOSE;
      if (pacman->astar.cur.x == pacman->astar.end.x &&
	  pacman->astar.cur.y == pacman->astar.end.y)
	return (get_new_pos(pacman));
      astar_step_2(pacman, pacman->astar.cur.x - 1, pacman->astar.cur.y);
      astar_step_2(pacman, pacman->astar.cur.x + 1, pacman->astar.cur.y);
      astar_step_2(pacman, pacman->astar.cur.x, pacman->astar.cur.y - 1);
      astar_step_2(pacman, pacman->astar.cur.x, pacman->astar.cur.y + 1);
    }
  return (get_new_pos(pacman));
}
