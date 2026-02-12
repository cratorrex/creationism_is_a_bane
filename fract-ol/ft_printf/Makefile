CC := cc
CC_FLAGS := -Wall -Wextra -Werror

HEADER := ft_printf.h
SUBDIRS := ../libft
LIBFT := libft.a

AR := ar
AR_FLAGS := rcs
# > ar rcs Replace, Don't Warn, Create Archive 

SRC :=  \
ft_printf.c ft_printf_handler.c \
ft_handle_char.c ft_handle_str.c ft_handle_int_dec.c ft_handle_uint.c \
ft_handle_hex.c ft_handle_point.c 

LIBFTSRC := $(SUBDIRS)/ft_itoa.c $(SUBDIRS)/ft_strdup.c $(SUBDIRS)/ft_strlen.c \
$(SUBDIRS)/ft_putchar_fd.c $(SUBDIRS)/ft_putnbr_fd.c $(SUBDIRS)/ft_putstr_fd.c \
$(SUBDIRS)/ft_strchr.c

# BONUS := 

OBJ := $(SRC:.c=.o) $(LIBFTSRC:.c=.o)
# BONUS_OBJ := $(BONUS:.c=.o)

NAME := libftprintf.a

all: $(NAME)

$(NAME): $(SUBDIRS)/$(LIBFT) $(OBJ)
	$(AR) $(AR_FLAGS) $(NAME) $(OBJ)
# $(NAME) $(OBJ) == $@ $^
# '$' is the control symbol
# '^' refers to all requirements
# '<' refers to first requirement (in this case $(OBJ))
# '@' output into NAME via $(NAME)

# bonus: $@ $(BONUS_OBJ)
#	$(AR) $(AR_FLAGS) $(NAME) $(BONUS_OBJ)

$(SUBDIRS)/$(LIBFT):
	$(MAKE) -C $(SUBDIRS) all

%.o: %.c $(HEADER) $(SUBDIRS)/$(LIBFT)
	$(CC) $(CC_FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ) $(BONUS_OBJ)

subclean:
	$(MAKE) fclean -C $(SUBDIRS)

fclean: subclean clean
	rm -f $(NAME)

re: fclean all

# > make fclean 
# |> internally calls the commands in order 'clean >> fclean'

.PHONY: all clean subclean fclean re
# bonus
