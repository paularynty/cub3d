#This is a comment line
NAME = libft.a
SOURCES = \
		ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
		ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		ft_printf.c ft_printhex.c ft_putaddress.c ft_putchar.c ft_putdecimal.c ft_putstr.c ft_putunsign.c \
		get_next_line.c vector_funcs.c vector_funcs1.c vector_funcs2.c vector_funcs3.c
BSOURCES = \
		ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
		ft_lstmap_bonus.c
OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
#The $@ means the filename representing the target (NAME)
#The $? means the names of all the files? (if I understood correctly)
$(NAME): $(OBJECTS)
		ar rcs $@ $?
bonus: .bonus
.bonus: $(OBJECTS) $(BOBJECTS)
	ar rcs $(NAME) $(OBJECTS) $(BOBJECTS)
	@touch .bonus
%.o: %.c
		$(CC) -c $(CFLAGS) $?
clean:
		rm -f $(OBJECTS) $(BOBJECTS)
		rm -f .bonus
fclean: clean
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re bonus