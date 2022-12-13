#include "pacman.h"

void	print_ghost_amber(t_pacman *pacman, char gho)
{
  if (pacman->clyde.is_eat == 1)
    gho = '\"';
  if (g_ghost_fear == 0)
    attron(COLOR_PAIR(_COLOR_YELLOW));
  if (pacman->clyde.pos.y >= (SIZE_MAP_X / 2))
    mvprintw(pacman->clyde.pos.x, pacman->clyde.pos.y * 2 + 1, "%c", gho);
  else
    mvprintw(pacman->clyde.pos.x, pacman->clyde.pos.y * 2, "%c", gho);
  if (g_ghost_fear == 0)
    attroff(COLOR_PAIR(_COLOR_YELLOW));
}

void	print_ghost_cyan(t_pacman *pacman, char gho)
{
  if (pacman->inky.is_eat == 1)
    gho = '\"';
  if (g_ghost_fear == 0)
    attron(COLOR_PAIR(_COLOR_CYAN));
  if (pacman->inky.pos.y >= (SIZE_MAP_X / 2))
    mvprintw(pacman->inky.pos.x, pacman->inky.pos.y * 2 + 1, "%c", gho);
  else
    mvprintw(pacman->inky.pos.x, pacman->inky.pos.y * 2, "%c", gho);
  if (g_ghost_fear == 0)
    attroff(COLOR_PAIR(_COLOR_CYAN));
}

void	print_ghost_pink(t_pacman *pacman, char gho)
{
  if (pacman->pinky.is_eat == 1)
    gho = '\"';
  if (g_ghost_fear == 0)
    attron(COLOR_PAIR(_COLOR_PINK));
  if (pacman->pinky.pos.y >= (SIZE_MAP_X / 2))
    mvprintw(pacman->pinky.pos.x, pacman->pinky.pos.y * 2 + 1, "%c", gho);
  else
    mvprintw(pacman->pinky.pos.x, pacman->pinky.pos.y * 2, "%c", gho);
  if (g_ghost_fear == 0)
    attroff(COLOR_PAIR(_COLOR_PINK));
}

void	print_ghost_red(t_pacman *pacman, char gho)
{
  if (pacman->blinky.is_eat == 1)
    gho = '\"';
  if (g_ghost_fear == 0)
    attron(COLOR_PAIR(_COLOR_RED));
  if (pacman->blinky.pos.y >= (SIZE_MAP_X / 2))
    mvprintw(pacman->blinky.pos.x, pacman->blinky.pos.y * 2 + 1, "%c", gho);
  else
    mvprintw(pacman->blinky.pos.x, pacman->blinky.pos.y * 2, "%c", gho);
  if (g_ghost_fear == 0)
    attroff(COLOR_PAIR(_COLOR_RED));
}
