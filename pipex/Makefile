CC := cc
CC_FLAGS := -Wall -Wextra -Werror -g


HEADER := pipex.h
HEADER_BONUS := pipex_bonus.h

LIBFT_DIR := libft
LIBFT := libft.a
LIBFTA := $(LIBFT_DIR)/$(LIBFT)

EXT_LIB := 

AR := ar
AR_FLAGS := rcs
# > ar rcs Replace, Don't Warn, Create Archive 

SRC := pipex.c \
ft_strmatch.c ft_arrlen.c \
px_exec.c px_exit.c \
\

BONUS_SRC := pipex_bonus.c \
ft_strmatch.c ft_arrlen.c \
px_exec.c px_exit.c \
px_heredoc_exec_bonus.c \
gnl/get_next_line_bonus.c gnl/get_next_line_utils_bonus.c \
\

#stop

OBJ := $(SRC:.c=.o)
BONUS_OBJ := $(BONUS_SRC:.c=.o)

PROGRAM := pipex
PROGRAM_BONUS := pipex_bonus

# all: $(OBJ) $(MOBJ) $(LIBFT_DIR)/$(LIBFT)
# 	$(CC) $(CC_FLAGS) $(OBJ) $(MOBJ) $(LIBFTA) -o $(PROGRAM)
all: normal bonus
normal: $(PROGRAM)
bonus: HEADER := HEADER_BONUS
bonus: $(PROGRAM_BONUS)

$(PROGRAM): $(OBJ) $(LIBFT_DIR)/$(LIBFT)
	$(CC) $(CC_FLAGS) $(OBJ) $(EXT_LIB) $(LIBFTA) -o $(PROGRAM)

$(PROGRAM_BONUS): $(BONUS_OBJ) $(LIBFT_DIR)/$(LIBFT)
	$(CC) $(CC_FLAGS) $(BONUS_OBJ) $(EXT_LIB) $(LIBFTA) -o $(PROGRAM_BONUS)

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
# 	$(AR) $(AR_FLAGS) $(NAME) $(BONUS_OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CC_FLAGS) -c $< -o $@


$(LIBFT_DIR)/$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

subclean:
	$(MAKE) -C $(LIBFT_DIR) fclean

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean subclean
	rm -f $(PROGRAM) $(PROGRAM_BONUS)

re: fclean all

# > make fclean 
# |> internally calls the commands in order 'clean >> fclean'

.PHONY: all clean fclean re subclean normal bonus
# bonus
