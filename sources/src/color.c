#include "pacman.h"

void	init_color_pacman(void)
{
  if (has_colors() == FALSE)
    {
      endwin();
      printf("Your terminal does not support color\n");
      exit(1);
    }
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_PINK, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

void	color_start(char ch)
{
  if (ch == '#')
    attron(COLOR_PAIR(_COLOR_BLUE));
}

void	color_stop(char ch)
{
  if (ch == '#')
    attroff(COLOR_PAIR(_COLOR_BLUE));
}
