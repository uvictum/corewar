CC= clang

CFLAGS=  -g  -I./lib 

NAME = corewar

FILES = corewar argreader binfuncs memfuncs procfuncs

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

