CC := cc
CC_FLAGS := -g #-Wall -Wextra -Werror

MOVES ?= 0  # 0 | 1 | 2
ifeq ($(MOVES),1)
CC_FLAGS += -DDISPLAY_MOVES=1
endif

ifeq ($(MOVES),2)
CC_FLAGS += -DDISPLAY_MOVES=2
endif

ifeq ($(MOVES),3)
CC_FLAGS += -DDISPLAY_MOVES=3
endif


ERRORS ?= 0 # 0 | 1
ifeq ($(ERRORS),1)
CC_FLAGS += -DERROR_TYPE=1
endif

HEADER := push_swap.h

LIBFT_DIR := libft
LIBFT := libft.a
LIBFTA := $(LIBFT_DIR)/$(LIBFT)

AR := ar
AR_FLAGS := rcs
# > ar rcs Replace, Don't Warn, Create Archive 

SRC := \
push_swap.c ps_init.c ps_handler.c ps_handler_utils.c \
ps_debug_dsp_moves.c \
\
ps_instructions/ps_swap.c ps_instructions/ps_rotate.c \
ps_instructions/ps_push.c ps_instructions/ps_rev_rotate.c \
\
ps_sort_nb3.c ps_sort_radix.c
#stop

LIBFT_MDIR := ps_libft_mod
LIBFT_MSRC := \
$(LIBFT_MDIR)/ft_arrlen.c $(LIBFT_MDIR)/ft_atoi_e.c \
$(LIBFT_MDIR)/ft_split_two.c \
$(LIBFT_MDIR)/ft_strjoin_free.c

MOBJ := $(LIBFT_MSRC:.c=.o)

# BONUS := 

OBJ := $(SRC:.c=.o)
# BONUS_OBJ := $(BONUS:.c=.o)

NAME := push_swap.a
PROGRAM := push_swap

all: $(OBJ) $(MOBJ) $(LIBFT_DIR)/$(LIBFT)
	$(CC) $(CC_FLAGS) $(OBJ) $(MOBJ) $(LIBFTA) -o $(PROGRAM)

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

$(LIBFT_DIR)/$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

subclean:
	$(MAKE) -C $(LIBFT_DIR) fclean

clean:
	rm -f $(OBJ) $(MOBJ)

fclean: clean subclean
	rm -f $(PROGRAM)

re: fclean all

# > make fclean 
# |> internally calls the commands in order 'clean >> fclean'

.PHONY: all clean fclean re
# bonus
