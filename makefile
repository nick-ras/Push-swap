NAME := push_swap
CC := gcc

HEADER := ../push_swap.h

LIBFT_DIR			:= libft_for_push_swap
LIBFT_A			:= ./libft_for_push_swap/libft.a

FT_PRINTF_DIR	:= ../printf
PRINTF_A	:= ./printf/libftprintf.a

SRC_DIR := ./src/
OBJ_DIR := ./obj/

FLAGS = -Wall -Wextra -Werror -g

RM = rm -rf

SRC_FILES	:= main.c push_back.c make_lists.c \
			lis_and_sort.c find_exit.c  \
			commands_1.c commands_2.c libft_changed.c

OBJ_FILES	:= ${SRC_FILES:.c=.o} #SLET
SRC			:= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			:= $(addprefix $(OBJ_DIR), $(OBJ_FILES))
#If objeft doesnt exist, it will create one
OBJS =      $(SRC_FILES:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT_A) $(PRINTF_A) -o $(NAME)
	echo "code has been compiled!"
# -C changs directory

clean:
	$(RM) $(OBJ)
	make clean -C $(OBJ_DIR)
	make clean -C $(PRINTF_DIR)
#try first line at two last lines too

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_A)
	$(RM) $(PRINTF_A)
	$(RM) $(OBJ_DIR)

# if object file doesnt exist, or soruce file has changed, (refers to) two different files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -c $^ $(CFLAGS)  -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

#remmeber to add  "libft.so" to clean
#so:
#	$(CC) -nostartfiles -fPIC $(FLAGS) $(SRCBONUS) 
#	gcc -nostartfiles -shared -o libft.so $(OBJSBONUS)

re: fclean all

.PHONY: all fclean re bonus