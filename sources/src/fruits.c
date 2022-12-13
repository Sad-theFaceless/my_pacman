#include "pacman.h"

static int	size_rand_fruit(t_pacman *pacman)
{
  int   allowed_fruit;

  allowed_fruit = 1;
  if (pacman->level == 2)
    allowed_fruit = 2;
  else if (pacman->level == 3 || pacman->level == 4)
    allowed_fruit = 3;
  else if (pacman->level == 5 || pacman->level == 6)
    allowed_fruit = 4;
  else if (pacman->level == 7 || pacman->level == 8)
    allowed_fruit = 5;
  else if (pacman->level == 9 || pacman->level == 10)
    allowed_fruit = 6;
  else if (pacman->level == 11 || pacman->level == 12)
    allowed_fruit = 7;
  else if (pacman->level >= 13)
    allowed_fruit = 8;
  return (allowed_fruit);
}

void	verif_fruit(t_pacman *pacman)
{
  int	size_rand;

  if (g_make_fruit <= 0)
    {
      pacman->actual_fruit = -1;
      return ;
    }
  if (pacman->actual_fruit >= 0)
    return ;
  size_rand = size_rand_fruit(pacman);
  pacman->actual_fruit = (rand() % size_rand);
}

void	fork_for_fruits(void)
{
  if ((g_fruit_child = fork()) == -1)
    return ;
  if (g_fruit_child == 0)
    {
      srand(time(NULL) * getpid());
      while (42)
	{
	  usleep(1 * SECOND);
	  if (((rand() % 100) + 1) <= 3)
	    {
	      kill(getppid(), SIGUSR2);
	      usleep(10 * SECOND);
	      kill(getppid(), SIGUSR2);
	    }
	}
      exit(0);
    }
}

void	get_fruit(t_pacman *pacman)
{
  if (pacman->pacman.pos.x == 17 && pacman->pacman.pos.y == 13)
    if (pacman->actual_fruit != -1)
      {
	g_make_fruit = -1;
	if (pacman->actual_fruit == CERISE)
	  up_score(pacman, 100);
	else if (pacman->actual_fruit == FRAISE)
	  up_score(pacman, 300);
	else if (pacman->actual_fruit == ORANGE)
	  up_score(pacman, 500);
	else if (pacman->actual_fruit == POMME)
	  up_score(pacman, 700);
	else if (pacman->actual_fruit == MELON)
	  up_score(pacman, 1000);
	else if (pacman->actual_fruit == GALBOSS)
	  up_score(pacman, 2000);
	else if (pacman->actual_fruit == CLOCHE)
	  up_score(pacman, 3000);
	else if (pacman->actual_fruit == CLE)
	  up_score(pacman, 5000);
      }
}
