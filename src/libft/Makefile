
NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memmove.c \
		ft_memcpy.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
		ft_strnstr.c ft_calloc.c ft_strdup.c ft_atoi.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_substr.c ft_strjoin.c ft_striteri.c \
		ft_strmapi.c ft_itoa.c ft_putnbr_fd.c  ft_strtrim.c ft_split.c \
		ft_putstr.c ft_putchar.c ft_putnbr_base.c \
		ft_printf.c ft_printf_utils.c ft_count_matrix.c ft_free_matrix.c \
		ft_free_spatial_matrix.c ft_free_matrix_size_n.c ft_swap.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_free_list.c \
		ft_strcmp.c ft_labs.c ft_strndup.c get_next_line.c get_next_line_utils.c \
		ft_latoi.c

OBJ = $(SRC:%.c=%.o)

all:	$(NAME)

$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)

%.o: %.c 
	$(CC) -c $(CFLAGS) $?

.PHONY: all clean fclean re

clean:
	rm -f $(OBJ)
fclean:	clean
	rm -f $(NAME)
re:	fclean all

bonus: $(OBJB)
	ar rc $(NAME) $^
	ranlib $(NAME)
























# NAME = libft.a

# SHELL := /bin/bash
# COUNT := 0



# CFLAGS = -Wall -Wextra -Werror -g3
# CFILES =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
# 			ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memmove.c \
# 			ft_memcpy.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
# 			ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
# 			ft_strnstr.c ft_calloc.c ft_strdup.c ft_atoi.c ft_putchar_fd.c \
# 			ft_putstr_fd.c ft_putendl_fd.c ft_substr.c ft_strjoin.c ft_striteri.c \
# 			ft_strmapi.c ft_itoa.c ft_putnbr_fd.c  ft_strtrim.c ft_split.c \
# 			ft_putstr.c ft_putchar.c ft_putnbr_base.c \
# 			ft_printf.c ft_printf_utils.c ft_count_matrix.c ft_free_matrix.c \
# 			ft_free_spatial_matrix.c ft_free_matrix_size_n.c ft_swap.c ft_power.c \
# 			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
# 			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_free_list.c \
# 			ft_strcmp.c ft_labs.c ft_strndup.c get_next_line.c get_next_line_utils.c \
# 			ft_latoi.c

# OBJS = $(CFILES:%.c=%.o)
	   
# all : $(NAME)

# $(NAME) : $(OBJS)
# 	@ar rcs $(NAME) $(OBJS)

# %.o:%.c
# 	@$(eval COUNT=$(shell expr $(COUNT) + 1))
# 	@cc $(CFLAGS) -I ./ -c $< -o $@

# fclean : clean
# 	@rm -f $(NAME)

# clean :
# 	@rm -f $(OBJS)

# re : fclean all
