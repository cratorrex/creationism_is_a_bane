
CC := cc
CC_FLAGS := -O3 -Wall -Wextra -Werror

HEADER := fractol.h

LIBFT_DIR := libft
LIBFT := libft.a
LIBFTA := $(LIBFT_DIR)/$(LIBFT)

MLX_DIR :=../minilibx# Alter this
MLX :=libmlx.a
MLXA :=$(MLX_DIR)/$(MLX)


EXT_LIB := -L/usr/lib/X11 -L$(MLX_DIR) -lmlx -lm -lXext -lX11 

AR := ar
AR_FLAGS := rcs
# > ar rcs Replace, Don't Warn, Create Archive 

SRC := \
fractol.c fr_init.c fr_init_opt.c \
fr_exit.c \
fr_gen_handler.c ft_atod_e.c ft_atoi_e.c \
fr_julia.c fr_mandelbrot.c\
\

#stop

# LIBFT_MDIR := ps_libft_mod
# LIBFT_MSRC := \
# $(LIBFT_MDIR)/ft_arrlen.c $(LIBFT_MDIR)/ft_atoi_e.c \
# $(LIBFT_MDIR)/ft_split_two.c \
# $(LIBFT_MDIR)/ft_strjoin_free.c

# MOBJ := $(LIBFT_MSRC:.c=.o)

# BONUS := 

OBJ := $(SRC:.c=.o)
# BONUS_OBJ := $(BONUS:.c=.o)

# NAME := push_swap.a
PROGRAM := fractol

# all: $(OBJ) $(MOBJ) $(LIBFT_DIR)/$(LIBFT)
# 	$(CC) $(CC_FLAGS) $(OBJ) $(MOBJ) $(LIBFTA) -o $(PROGRAM)
all: $(PROGRAM)

$(PROGRAM): $(OBJ) $(LIBFT_DIR)/$(LIBFT) $(MLXA)
	$(CC) $(CC_FLAGS) $(OBJ) $(EXT_LIB) $(LIBFTA) -o $(PROGRAM)
# $(CC) $(CC_FLAGS) $(OBJ) ../minilibx/libmlx.a $(LIBFTA) -o $(PROGRAM)
# $(CC) $(CC_FLAGS) $(EXT_LIB) $(OBJ) $(LIBFTA) -o $(PROGRAM)

#all: $(NAME)

# $(NAME): $(OBJ)
#	$(AR) $(AR_FLAGS) $(NAME) $(OBJ)
# $(NAME) $(OBJ) == $@ $^
# '$' is the control symbol
# '^' refers to all requirements
# '<' refers to first requirement (in this case $(OBJ))
# '@' output into NAME via $(NAME)

# bonus: $@ $(BONUS_OBJ)
#	$(AR) $(AR_FLAGS) $(NAME) $(BONUS_OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CC_FLAGS) -c $< -o $@

$(MLXA):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT_DIR)/$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

subclean:
	$(MAKE) -C $(LIBFT_DIR) fclean && $(MAKE) -C $(MLX_DIR) clean

clean:
	rm -f $(OBJ) $(MOBJ)

fclean: clean subclean
	rm -f $(PROGRAM)

re: fclean all

# > make fclean 
# |> internally calls the commands in order 'clean >> fclean'

.PHONY: all clean fclean re subclean
# bonus
