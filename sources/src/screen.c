#include "pacman.h"

static void	screen_move(char gho, char pac)
{
  attron(COLOR_PAIR(_COLOR_RED));
  mvprintw(6, 16, "%c", gho);
  mvprintw(16, 17, "%c", gho);
  attroff(COLOR_PAIR(_COLOR_RED));
  attron(COLOR_PAIR(_COLOR_PINK));
  mvprintw(8, 16, "%c", gho);
  mvprintw(16, 21, "%c", gho);
  attroff(COLOR_PAIR(_COLOR_PINK));
  attron(COLOR_PAIR(_COLOR_CYAN));
  mvprintw(10, 16, "%c", gho);
  mvprintw(16, 25, "%c", gho);
  attroff(COLOR_PAIR(_COLOR_CYAN));
  attron(COLOR_PAIR(_COLOR_YELLOW));
  mvprintw(12, 16, "%c", gho);
  mvprintw(16, 29, "%c", gho);
  attron(A_BOLD);
  mvprintw(16, 37, "%c", pac);
  attroff(A_BOLD);
  attroff(COLOR_PAIR(_COLOR_YELLOW));
  attron(A_BOLD);
  attron(COLOR_PAIR(_COLOR_BLUE));
  mvprintw(24, 22, "%c", gho);
  attroff(COLOR_PAIR(_COLOR_BLUE));
  attroff(A_BOLD);
}

static void	anim_screen(void)
{
  static int	anim = 2;

  if (anim == 2)
    {
      screen_move('W', 'C');
      anim = 1;
      attron(A_BOLD);
      mvprintw(27, 18, "PRESS SPACE TO START");
      attroff(A_BOLD);
    }
  else if (anim == 1)
    {
      screen_move('V', 'c');
      anim = 2;
      mvprintw(27, 18, "                    ");
    }
}

static void	start_part_1(void)
{
  clear();
  attron(A_BOLD);
  mvprintw(3, 20, "CHARACTER / NICKNAME");
  attron(COLOR_PAIR(_COLOR_RED));
  mvprintw(6, 18, "- SHADOW     \"BLINKY\"");
  attroff(COLOR_PAIR(_COLOR_RED));
  attron(COLOR_PAIR(_COLOR_PINK));
  mvprintw(8, 18, "- SPEEDY     \"PINKY\"");
  attroff(COLOR_PAIR(_COLOR_PINK));
  attron(COLOR_PAIR(_COLOR_CYAN));
  mvprintw(10, 18, "- BASHFUL    \"INKY\"");
  attroff(COLOR_PAIR(_COLOR_CYAN));
  attron(COLOR_PAIR(_COLOR_YELLOW));
  mvprintw(12, 18, "- POKEY      \"CLYDE\"");
  attroff(COLOR_PAIR(_COLOR_YELLOW));
  mvprintw(20, 22, ".   10 pts");
  mvprintw(22, 22, "*   50 pts");
  mvprintw(24, 26, "200 pts");
  attroff(A_BOLD);
}

void	corner(void)
{
  int	i;

  attron(A_BOLD);
  attron(COLOR_PAIR(_COLOR_RED));
  i = -1;
  while (++i < SIZE_MAP_Y)
    mvprintw(i, 2 * SIZE_MAP_X, "+");
  i = -1;
  while (++i < 2 * SIZE_MAP_X)
    if (i % 2 == 0)
      mvprintw(SIZE_MAP_Y, i, "+");;
  mvprintw(SIZE_MAP_Y, 2 * SIZE_MAP_X, "+");
  attroff(COLOR_PAIR(_COLOR_RED));
  attroff(A_BOLD);
}

int	starting_screen(void)
{
  int	ch;
  int	ch2;

  ch = getch();
  ch2 = ch;
  while (ch == ch2)
    {
      ch = getch();
      if (!(ch >= 0 && ch <= 127))
	ch = ch2;
      if (pars_sizeterm_max(2 * SIZE_MAP_X, SIZE_MAP_Y) == 0)
	{
	  start_part_1();
	  anim_screen();
	  corner();
	  usleep(0.25 * SECOND);
	  refresh();
	}
    }
  if (ch != 32)
    {
      endwin();
      return (1);
    }
  return (0);
}
