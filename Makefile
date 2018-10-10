CC= gcc

CFLAGS=  -Wall -Wextra -Werror -I. -Ilib

NAME = corewar

FILES = corewar \
		argreader \
	   	binfuncs \
	   	memfuncs \
		machine \
		cmndfuncs \
	   	procfuncs \
		add_sub \
		get_args \
		live_zjmp_fork_lfork_aff \
	   	and_or_xor \
		ld_ldi_lld_lldi \
		st_sti

SRC= $(addsuffix .c, $(FILES))

OBJ= $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(OBJ) 
	make -C lib
	$(CC) $(CFLAGS) $(OBJ)  -L./lib -lft -o $@

$(OBJ):
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -f *.o
	make clean -C ./lib

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib

re: fclean all

