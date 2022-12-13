#include "pacman.h"

static void	color_start_fruit(t_pacman *pacman)
{
  if (pacman->actual_fruit == CERISE)
    attron(COLOR_PAIR(_COLOR_RED));
  else if (pacman->actual_fruit == FRAISE)
    attron(COLOR_PAIR(_COLOR_RED));
  else if (pacman->actual_fruit == ORANGE)
    attron(COLOR_PAIR(_COLOR_YELLOW));
  else if (pacman->actual_fruit == POMME)
    attron(COLOR_PAIR(_COLOR_GREEN));
  else if (pacman->actual_fruit == MELON)
    attron(COLOR_PAIR(_COLOR_GREEN));
  else if (pacman->actual_fruit == GALBOSS)
    attron(COLOR_PAIR(_COLOR_BLUE));
  else if (pacman->actual_fruit == CLOCHE)
    attron(COLOR_PAIR(_COLOR_YELLOW));
  else if (pacman->actual_fruit == CLE)
    attron(COLOR_PAIR(_COLOR_YELLOW));
}

static void	color_stop_fruit(t_pacman *pacman)
{
  if (pacman->actual_fruit == CERISE)
    attroff(COLOR_PAIR(_COLOR_RED));
  else if (pacman->actual_fruit == FRAISE)
    attroff(COLOR_PAIR(_COLOR_RED));
  else if (pacman->actual_fruit == ORANGE)
    attroff(COLOR_PAIR(_COLOR_YELLOW));
  else if (pacman->actual_fruit == POMME)
    attroff(COLOR_PAIR(_COLOR_GREEN));
  else if (pacman->actual_fruit == MELON)
    attroff(COLOR_PAIR(_COLOR_GREEN));
  else if (pacman->actual_fruit == GALBOSS)
    attroff(COLOR_PAIR(_COLOR_BLUE));
  else if (pacman->actual_fruit == CLOCHE)
    attroff(COLOR_PAIR(_COLOR_YELLOW));
  else if (pacman->actual_fruit == CLE)
    attroff(COLOR_PAIR(_COLOR_YELLOW));
}

void	print_fruit(t_pacman *pacman)
{
  if (pacman->actual_fruit == -1)
    return ;
  color_start_fruit(pacman);
  mvprintw(17, 26, "%c", pacman->fruit[pacman->actual_fruit]);
  color_stop_fruit(pacman);
}
