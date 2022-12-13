#include "pacman.h"

static void	print_level(t_pacman *pacman)
{
  mvprintw(16, 46, "  LEVEL:");
  mvprintw(18, 50 - pos_center(pacman->level), "%d", pacman->level);
}

static void	print_scores(t_pacman *pacman)
{
  mvprintw(10, 0, "  SCORE:");
  mvprintw(12, 5 - pos_center(pacman->score), "%d", pacman->score);
  mvprintw(16, 0, "HIGHSCORE:");
  mvprintw(18, 5 - pos_center(pacman->high_score), "%d", pacman->high_score);
}

static void	print_lifes(t_pacman *pacman)
{
  mvprintw(10, 46, " LIFE(S):");
  attron(A_BOLD);
  attron(COLOR_PAIR(_COLOR_YELLOW));
  mvprintw(12, 48, "C");
  attroff(COLOR_PAIR(_COLOR_YELLOW));
  attroff(A_BOLD);
  mvprintw(12, 50, "x %d", pacman->lifes);
}

void	game_over(t_pacman *pacman)
{
  clear();
  print_map(pacman);
  refresh();
  print_scores(pacman);
  refresh();
  print_lifes(pacman);
  refresh();
  print_level(pacman);
  refresh();
  attron(A_BOLD);
  attron(COLOR_PAIR(_COLOR_RED));
  mvprintw(17, 23, "GAME  OVER");
  attroff(COLOR_PAIR(_COLOR_RED));
  attroff(A_BOLD);
  refresh();
  corner();
  refresh();
  usleep(4 * SECOND);
}

void    print_game(t_pacman *pacman)
{
  print_map(pacman);
  print_fruit(pacman);
  print_ghosts(pacman);
  print_pacman(pacman);
  print_scores(pacman);
  print_lifes(pacman);
  print_level(pacman);
  corner();
  refresh();
}
