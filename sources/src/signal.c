#include "pacman.h"

void	anti_zombie(void)
{
  wait(NULL);
}

void	catch_sig1(void)
{
  g_ghost_fear++;
  if (g_ghost_fear == 3)
    g_ghost_fear = 0;
}

void	catch_sig2(void)
{
  if (g_make_fruit == 1)
    g_make_fruit = 0;
  else
    g_make_fruit++;
}

void	catch_sigsegv(void)
{
  endwin();
  printf("segmentation fault (core dumped)\n");
  exit(139);
}
