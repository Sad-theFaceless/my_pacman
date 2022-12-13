#include "pacman.h"

void		up_score(t_pacman *pacman, int points)
{
  static int	is_up = 0;

  pacman->score = pacman->score + points;
  if (pacman->score - is_up >= 10000)
    {
      is_up = is_up + 10000;
      pacman->lifes = pacman->lifes + 1;
    }
}

int		load_highscore(void)
{
  struct stat	sb;
  int		fd;
  char		buffer;
  char		nbr[10];
  int		i;

  if (stat("./data/highscore_pacman", &sb) == -1 || S_ISREG(sb.st_mode) != 1 ||
      (fd = open("./data/highscore_pacman", O_RDONLY)) < 0)
    return (0);
  buffer = '\0';
  i = -1;
  while (++i < 10)
    nbr[i] = '\0';
  i = -1;
  while (read(fd, &buffer, 1) > 0 && buffer != '\n' && i < 8)
    nbr[++i] = buffer;
  if (close(fd) == -1)
    return (0);
  if (buffer == '\n' || i >= 8)
    return (0);
  i = -1;
  while (nbr[++i])
    if (!(nbr[i] >= '0' && nbr[i] <= '9'))
      return (0);
  return (atoi(nbr));
}

void	save_highscore(t_pacman *pacman)
{
  int	fd;
  int	tmp;
  char	nbr[10];
  int	i;

  if ((fd = open("./data/highscore_pacman", O_RDWR | O_CREAT | O_TRUNC,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
    return ;
  i = -1;
  while (++i < 10)
    nbr[i] = '\0';
  tmp = pacman->high_score;
  sprintf(nbr, "%d", tmp);
  i = -1;
  while (nbr[++i])
    write(fd, &nbr[i], 1);
  if (close(fd) == -1)
    return ;
}
