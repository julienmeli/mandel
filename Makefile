CC := cc -Wall -Wextra -Werror
SRCDIR := src
OBJDIR := $(SRCDIR)
MLXDIR := ./include/minilibx-linux
OBJ_MLXDIR := $(MLXDIR)
NAME := libfractol.a
SRC := utils2.c hook.c initialize.c draw.c utils.c
OBJ := $(SRC:.c=.o)
SRCS := $(addprefix $(SRCDIR)/, $(SRC))
OBJS := $(addprefix $(SRCDIR)/, $(OBJ))

all: $(NAME)
	make -C $(OBJ_MLXDIR)
	make main

$(NAME): $(OBJS)
	ar -rcs $@ $^

$(OBJ_MLXDIR)/%.o : $(MLXDIR)/%.c | $(OBJ_MLXDIR)
	$(CC) -c $< -o $@ -I

$(OBJDIR)/%.o : $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) -c $< -o $@ -Iinclude

main:
	cc -Wall -Wextra -Werror main.c -o fractol -I include -L. -lfractol -Linclude/minilibx-linux/ -lmlx -lXext -lX11

clean:
	rm -f $(OBJS)
	make clean -C $(OBJ_MLXDIR)

fclean: clean
	rm -f $(NAME)
	rm -f fractol

re: fclean all

.PHONY: all clean fclean re
