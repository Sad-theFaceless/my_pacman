#include "pacman.h"

void	end_ncurses_pacman(void)
{
  endwin();
}

void	init_ncurses_pacman(void)
{
  initscr();
  init_color_pacman();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(0);
  nodelay(stdscr, TRUE);
}

int     pars_sizeterm_max(int len_x_max, int len_y_max)
{
  int   row;
  int   col;

  getmaxyx(stdscr, row, col);
  if (col < len_x_max || row < len_y_max)
    {
      clear();
      mvprintw((row) / 2, ((col) - 9) / 2, "Too small");
      refresh();
      usleep(1000);
      return (1);
    }
  refresh();
  return (0);
}
