#ifndef __PACMAN_H_
# define __PACMAN_H_

# include <curses.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <time.h>
# include <signal.h>

# define SIZE_MAP_X	(28)
# define SIZE_MAP_Y	(31)

# define RIGHT	(1)
# define LEFT	(2)
# define UP	(3)
# define DOWN	(4)

# define COLOR_PINK	COLOR_MAGENTA

# define _COLOR_RED	1
# define _COLOR_GREEN	2
# define _COLOR_YELLOW	3
# define _COLOR_BLUE	4
# define _COLOR_PINK	5
# define _COLOR_CYAN	6
# define _COLOR_WHITE	7

# define CERISE		0
# define FRAISE		1
# define ORANGE		2
# define POMME		3
# define MELON		4
# define GALBOSS	5
# define CLOCHE		6
# define CLE		7

# define SECOND	1000000

# define BLINKY	0
# define PINKY	1
# define INKY	2
# define CLYDE	3

# define OPEN	1
# define CLOSE	-1
# define BLANK	0

# define MAX_INT	2147483646

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef struct	s_node
{
  t_pos		pos;
  int		list;
  int		F;
  int		G;
  int		H;
  int		obst;
  t_pos		parent;
}		t_node;

typedef struct	s_astar
{
  t_node	map[SIZE_MAP_Y][SIZE_MAP_X];
  t_pos		start;
  t_pos		cur;
  t_pos		end;
}		t_astar;

typedef struct	s_entity
{
  t_pos		pos;
  int		dir;
  int		is_eat;
  int		waiting;
}		t_entity;

typedef struct	s_pacman
{
  char		map[SIZE_MAP_Y][SIZE_MAP_X];
  t_entity	pacman;
  t_entity	blinky;
  t_entity	pinky;
  t_entity	inky;
  t_entity	clyde;
  char		dir_key;
  int		lifes;
  int		score;
  int		high_score;
  int		level;
  char		fruit[8];
  int		actual_fruit;
  t_astar	astar;
}		t_pacman;

extern int	g_ghost_fear;
extern pid_t	g_fear_child;
extern pid_t	g_fruit_child;
extern int	g_make_fruit;

int	pars_sizeterm_max(int len_x_max, int len_y_max);
void	init_ncurses_pacman(void);
void	end_ncurses_pacman(void);
int	pacman(t_pacman *pacman);
void	init_pacman(t_pacman *pacman);
void	init_color_pacman(void);
void	print_game(t_pacman *pacman);
void	print_pacman(t_pacman *pacman);
void	print_map(t_pacman *pacman);
int	start_game(t_pacman *pacman);
void	move_pacman(t_pacman *pacman);
void	init_map(t_pacman *pacman);
int	load_highscore(void);
void	save_highscore(t_pacman *pacman);
void	color_start(char ch);
void	color_stop(char ch);
int	pos_center(int tmp);
void	next_level(t_pacman *pacman);
void	print_ghosts(t_pacman *pacman);
void	move_ghosts(t_pacman *pacman);
void	catch_sig1(void);
void	catch_sig2(void);
void	ghost_fear(t_pacman *pacman);
void	print_ghost_amber(t_pacman *pacman, char gho);
void	print_ghost_cyan(t_pacman *pacman, char gho);
void	print_ghost_pink(t_pacman *pacman, char gho);
void	print_ghost_red(t_pacman *pacman, char gho);
void	catch_sigsegv(void);
void	fork_for_fruits(void);
void	verif_fruit(t_pacman *pacman);
void	print_fruit(t_pacman *pacman);
void	get_fruit(t_pacman *pacman);
void	up_score(t_pacman *pacman, int points);
int	verif_dead(t_pacman *pacman);
void	move_ghost(t_pacman *pacman, int dir, int ghost);
void	get_pos_ghost(t_pacman *pacman, int ghost, int *x, int *y);
int	verif_is_out(t_pacman *pacman, int x, int y);
int	autorize_move_ghost(t_pacman *pacman, int dir, int ghost);
void	ia_alea(t_pacman *pacman, int ghost);
void	struct_clean(t_pacman *pacman);
void	astar_raz(t_pacman *pacman);
t_pos	start_astar(t_pacman *pacman);
void	calc_poids(t_pacman *pacman, int x, int y);
void	ghost_move(t_pacman *pacman, int ghost, int dir);
int	nbr_path(t_pacman *pacman, int x, int y);
int	get_dir(t_pos old, t_pos new, t_pacman *pacman);
void	ghost_leak_pos(t_pacman *pacman);
void	ghost_return_cage(t_pacman *pacman, int ghost);
int	contrary(int dir);
void	clyde_rand_move(t_pacman *pacman);
void	anticipate_move_pacman(t_pacman *pacman);
int	autorize_dir_virtual(t_pacman *pacman, t_pos *pos, int dir);
void	move_pos_virtual(t_pacman *pacman, t_pos *next, int dir);
int	verif_and_get_move_segf(t_pacman *pacman);
void	game_over(t_pacman *pacman);
void	anti_zombie(void);
void	inky_rand_move(t_pacman *pacman);
void	inky_ia_pinky(t_pacman *pacman);
void	inky_ia_clyde(t_pacman *pacman);
int	starting_screen(void);
void	corner(void);
int	start_pacman(t_pacman *pacman);

#endif /* !__PACMAN_H_ */
