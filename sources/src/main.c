#include "pacman.h"

int g_ghost_fear;
int g_make_fruit;
pid_t g_fear_child;
pid_t g_fruit_child;

int	start_pacman(t_pacman *my_pacman)
{
  init_pacman(my_pacman);
  if (starting_screen() != 0)
    return (0);
  g_ghost_fear = 0;
  g_make_fruit = 0;
  g_fear_child = getpid();
  g_fruit_child = getpid();
  fork_for_fruits();
  if (pacman(my_pacman) != 0)
    return (0);
  return (42);
}

int		main(void)
{
  t_pacman	my_pacman;
  int		restart;

  printf("\033[8;%d;%dt", SIZE_MAP_Y, 2 * SIZE_MAP_X);
  signal(SIGSEGV, (__sighandler_t)catch_sigsegv);
  signal(SIGUSR1, (__sighandler_t)catch_sig1);
  signal(SIGUSR2, (__sighandler_t)catch_sig2);
  signal(SIGCHLD, (__sighandler_t)anti_zombie);
  srand(time(NULL) * getpid());
  init_ncurses_pacman();
  restart = start_pacman(&my_pacman);
  end_ncurses_pacman();
  return (restart);
}
