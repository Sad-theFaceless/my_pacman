#include "pacman.h"

void	struct_clean(t_pacman *pacman)
{
  init_map(pacman);
  pacman->dir_key = LEFT;
  pacman->pacman.dir = LEFT;
  pacman->pacman.pos.x = 23;
  pacman->pacman.pos.y = 14;
  pacman->blinky.pos.x = 14;
  pacman->blinky.pos.y = 12;
  pacman->pinky.pos.x = 14;
  pacman->pinky.pos.y = 13;
  pacman->inky.pos.x = 14;
  pacman->inky.pos.y = 14;
  pacman->clyde.pos.x = 14;
  pacman->clyde.pos.y = 15;
  pacman->blinky.dir = UP;
  pacman->pinky.dir = UP;
  pacman->inky.dir = UP;
  pacman->clyde.dir = UP;
  pacman->blinky.is_eat = 0;
  pacman->pinky.is_eat = 0;
  pacman->inky.is_eat = 0;
  pacman->clyde.is_eat = 0;
  pacman->blinky.waiting = 3 * 4;
  pacman->pinky.waiting = 6 * 4;
  pacman->inky.waiting = 9 * 4;
  pacman->clyde.waiting = 12 * 4;
}

void	next_level(t_pacman *pacman)
{
  struct_clean(pacman);
  pacman->level = pacman->level + 1;
}

void	init_pacman(t_pacman *pacman)
{
  struct_clean(pacman);
  pacman->lifes = 3;
  pacman->score = 0;
  pacman->high_score = load_highscore();
  pacman->level = 1;
  pacman->fruit[CERISE] = '%';
  pacman->fruit[FRAISE] = 'V';
  pacman->fruit[ORANGE] = 'Q';
  pacman->fruit[POMME] = 'o';
  pacman->fruit[MELON] = 'O';
  pacman->fruit[GALBOSS] = 'W';
  pacman->fruit[CLOCHE] = '^';
  pacman->fruit[CLE] = 'F';
  pacman->actual_fruit = -1;
  pacman->pacman.is_eat = -1;
  pacman->pacman.waiting = -1;
}

int	pacman(t_pacman *pacman)
{
  int	restart;

  while (pacman->lifes > 0)
    {
      if (pars_sizeterm_max(2 * SIZE_MAP_X, SIZE_MAP_Y) == 0)
	{
	  clear();
	  print_game(pacman);
	  usleep(0.20 * SECOND);
	  if ((restart = start_game(pacman)) != 0)
	    pacman->lifes = 0;
	  else
	    {
	      move_ghosts(pacman);
	      verif_dead(pacman);
	    }
	}
      else
	usleep(1 * SECOND);
    }
  kill(g_fruit_child, SIGKILL);
  game_over(pacman);
  save_highscore(pacman);
  return (restart);
}
