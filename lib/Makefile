CC= clang

CFLAGS= -g -Wall -Wextra -Werror -c

FILES= ft_atoi ft_isalnum ft_bzero ft_isalpha ft_isdigit ft_intlen ft_isascii ft_isprint ft_iswspace ft_lstadd ft_itoa ft_lstdelone ft_lstdel ft_lstiter ft_ltrcount ft_memalloc ft_lstnew ft_lstlink ft_memccpy ft_memchr ft_memcpy ft_lstmap ft_memcmp ft_memdel ft_memset ft_putchar ft_putendl ft_putchar_fd ft_putendl_fd ft_memmove ft_putnbr ft_putstr_fd ft_putstr ft_skipc ft_sqr ft_putnbr_fd ft_strcat ft_strclr ft_strcmp ft_strchr ft_strcpy ft_strdel ft_strcount ft_strequ ft_strdup ft_striter ft_striteri ft_strlcpy ft_strlcat ft_strjoin ft_strlen ft_strmap ft_strncat ft_strnequ ft_strncmp ft_strmapi ft_strnew ft_strncpy ft_strrchr ft_strsub ft_strnstr ft_strstr ft_tolower ft_toupper ft_strsplit ft_strtrim ft_strtrimc ft_printf ft_get_specs ft_form_buf ft_print_buf ft_funcs ft_print_char ft_wstrlen get_next_line ft_lstadd_end ft_dellst ft_sumnat ft_uitoa_base ft_isnum ft_swapuint ft_swapshrt

SRC= $(addsuffix .c, $(FILES))

OBJ= $(addsuffix .o, $(FILES))

NAME= libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	
$(OBJ):
	$(CC) $(CFLAGS) $(SRC) 

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

