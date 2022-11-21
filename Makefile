NAME=libftprintf.a
LIBFT_PATH = libft
LIBFT=libft.a
SFILES= ft_printf.c ft_parse_argument.c ft_uitoa.c ft_print_hex_lowercase.c \
	ft_print_hex_pointer.c ft_str_argument.c
OFILES= *.o

SOFILES=$(SFILES:.c=.o)

$(NAME): all 

CFLAGS= -Wall -Werror -Wextra

cc = cc

$(SOFILES): $(SFILES)
	      $(cc) $(CFLAGS) - c $(SFILES) ft_printf.h

all:	
	make -C $(LIBFT_PATH) all
	mv $(LIBFT_PATH)/libft.a ./
	$(cc) $(CFLAGS) -c $(SFILES) ft_printf.h
	make -C $(LIBFT_PATH) clean
	ar x $(LIBFT)
	rm $(LIBFT)
	ar rc $(NAME) $(OFILES)
clean:
	rm -f $(OFILES) 
fclean:	clean
	rm -f $(NAME)
	
re: fclean all
