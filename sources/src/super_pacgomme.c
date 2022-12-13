#include "pacman.h"

void	ghost_fear(t_pacman *pacman)
{
  int	count;

  if (g_ghost_fear >= 1 && g_fear_child != 0)
    kill(g_fear_child, SIGKILL);
  count = 0;
  g_ghost_fear = 1;
  if ((g_fear_child = fork()) == -1)
    return ;
  if (g_fear_child == 0)
    {
      while (count < 100 - (5 * (pacman->level - 1)))
      	{
      	  usleep(0.1 * SECOND);
      	  count++;
      	}
      usleep(5000);
      kill(getppid(), SIGUSR1);
      usleep(2 * SECOND);
      kill(getppid(), SIGUSR1);
      exit(0);
    }
}
