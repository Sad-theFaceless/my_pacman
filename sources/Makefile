# PARAMETERS

SRCDIR	= src
SRC	= ./$(SRCDIR)/main.c \
	  ./$(SRCDIR)/ncurses.c \
	  ./$(SRCDIR)/pacman.c \
	  ./$(SRCDIR)/print.c \
	  ./$(SRCDIR)/print_char.c \
	  ./$(SRCDIR)/print_ghosts.c \
	  ./$(SRCDIR)/print_fruit.c \
	  ./$(SRCDIR)/print_map.c \
	  ./$(SRCDIR)/game.c \
	  ./$(SRCDIR)/map.c \
	  ./$(SRCDIR)/movement.c \
	  ./$(SRCDIR)/score.c \
	  ./$(SRCDIR)/color.c \
	  ./$(SRCDIR)/tools.c \
	  ./$(SRCDIR)/ia_ghosts.c \
	  ./$(SRCDIR)/ia_tools.c \
	  ./$(SRCDIR)/move_ghost.c \
	  ./$(SRCDIR)/super_pacgomme.c \
	  ./$(SRCDIR)/signal.c \
	  ./$(SRCDIR)/fruits.c \
	  ./$(SRCDIR)/dead.c \
	  ./$(SRCDIR)/a_star.c \
	  ./$(SRCDIR)/ghost_move.c \
	  ./$(SRCDIR)/tools_astar.c \
	  ./$(SRCDIR)/tools_ia_ghosts.c \
	  ./$(SRCDIR)/virtual.c \
	  ./$(SRCDIR)/screen.c \
	  ./$(SRCDIR)/clyde.c \
	  ./$(SRCDIR)/inky.c
NAME	= my_pacman
DEBUG	= 0
MOREF	= 1
LNCURSE = 1
SILENT	= 0
OBJ	= $(SRC:.c=.o)

# COMPILATION

CFLAGS	+= -I./include/
ifeq	($(MOREF), 1)
CFLAGS	+= -W -Wall -Wextra -pedantic -Wmissing-prototypes
endif
ifeq	($(DEBUG), 1)
CFLAGS	+= -g3
endif
ifeq	($(LNCURSE), 1)
CFLAGS	+= -lncurses
endif

# SILENTS

ifeq	($(SILENT), 1)
.SILENT: $(OBJ)
.SILENT: $(NAME)
.SILENT: clean
.SILENT: fclean
.SILENT: re
endif

# MACROS

COMP    = cc
RM      = rm -rf

# CONSTRUCTION EXECUTABLE

all:	$(NAME)

$(NAME): $(OBJ)
	$(COMP) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
