#include "pacman.h"

static void	print_ghosts_2(t_pacman *pacman, char gho, int color)
{
  if (g_ghost_fear >= 1)
    {
      attron(A_BOLD);
      attron(COLOR_PAIR(color));
    }
  print_ghost_amber(pacman, gho);
  print_ghost_cyan(pacman, gho);
  print_ghost_pink(pacman, gho);
  print_ghost_red(pacman, gho);
  if (g_ghost_fear >= 1)
    {
      attroff(COLOR_PAIR(color));
      attroff(A_BOLD);
    }
}

void		print_ghosts(t_pacman *pacman)
{
  static char	gho = 'W';
  static int	color = _COLOR_BLUE;

  if (g_ghost_fear == 1)
    color = _COLOR_BLUE;
  print_ghosts_2(pacman, gho, color);
  if (g_ghost_fear == 2)
    {
      if (color == _COLOR_BLUE)
	color = _COLOR_WHITE;
      else
	color = _COLOR_BLUE;
    }
  if (gho == 'W')
    gho = 'V';
  else
    gho = 'W';
}

void		print_pacman(t_pacman *pacman)
{
  static char	pac = 'C';

  attron(A_BOLD);
  attron(COLOR_PAIR(_COLOR_YELLOW));
  if (pacman->pacman.pos.y >= (SIZE_MAP_X / 2))
    mvprintw(pacman->pacman.pos.x, pacman->pacman.pos.y * 2 + 1, "%c", pac);
  else
    mvprintw(pacman->pacman.pos.x, pacman->pacman.pos.y * 2, "%c", pac);
  attroff(COLOR_PAIR(_COLOR_YELLOW));
  attroff(A_BOLD);
  if (pac == 'C')
    pac = 'c';
  else
    pac = 'C';
}
