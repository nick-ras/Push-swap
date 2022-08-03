NAME = push_swap
CC := gcc

LIBFT_PATH	= ./libft/
LIBFT_A	= $(LIBFT_PATH)libft.a

PRINTF_PATH	= ./printf/
PRINTF_A	= $(PRINTF_PATH)libftprintf.a

SRC_PATH = ./src/
OBJ_PATH = ./obj/

FLAGS = -Wall -Wextra -Werror -g3

RM = rm -rf

SRC_FILES	= main.c push_back.c make_lists.c \
			lis_and_sort.c find_exit.c \
			commands_1.c commands_2.c \
			libft_changed.c

OBJ_FILES	= ${SRC:.c=.o} #SLET
OBJ			= $(addprefix $(SRC_PATH),$(OBJ_FILES))

#If objeft doesnt exist, it will create one

$(NAME): $(PRINTF_A) $(OBJ_FILES)
#	cp $(LIBFT_A) $(NAME)
#	cp $(PRINTF_A) $(NAME)
	$(CC) $(FLAGS) $(OBJ_FILES) -o $(NAME)
	echo "code has been compiled!"

all: $(OBJ_PATH) $(NAME)

$(PRINTF_A):
	make -C $(PRINTF_PATH) all

clean:
# make -C $(LIBFT_PATH) clean
# make -C $(PRINTF_PATH) clean
	$(RM) $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME)
# $(RM) $(LIBFT_A)
# $(RM) $(PRINTF_A)
	$(RM) obj

# if object file doesnt exist, or soruce file has changed, (refers to) two different files
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) -c $^ $(CFLAGS)  -o $@

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

#remmeber to add  "libft.so" to clean
#so:
#	$(CC) -nostartfiles -fPIC $(FLAGS) $(SRCBONUS) 
#	gcc -nostartfiles -shared -o libft.so $(OBJSBONUS)

re: fclean all

.PHONY: all fclean re bonus