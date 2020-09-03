GREEN = \033[0;32m
NC = \033[0m
YELLOW = \033[0;33m

NAME = libft.a

HEADER = libft.h

SRCS = ./char_function/ft_isalnum.c ./char_function/ft_isalpha.c ./char_function/ft_isascii.c ./char_function/ft_isdigit.c \
./char_function/ft_isprint.c ./char_function/ft_putchar.c ./char_function/ft_tolower.c ./char_function/ft_toupper.c \
./fd_function/ft_putchar_fd.c ./fd_function/ft_putendl_fd.c ./fd_function/ft_putnbr_fd.c ./fd_function/ft_putstr_fd.c \
./mem_function/ft_bzero.c ./mem_function/ft_calloc.c ./mem_function/ft_memccpy.c ./mem_function/ft_memchr.c \
./mem_function/ft_memcmp.c ./mem_function/ft_memcpy.c ./mem_function/ft_memmove.c ./mem_function/ft_memset.c \
./mem_function/ft_realloc.c \
./str_function/ft_atoi.c ./str_function/ft_itoa_base.c ./str_function/ft_itoa.c \
./str_function/ft_putstr.c ./str_function/ft_split.c ./str_function/ft_strchr.c ./str_function/ft_strdup.c \
./str_function/ft_strjoin.c ./str_function/ft_strjoinfree.c ./str_function/ft_strlcat.c ./str_function/ft_strlcpy.c \
./str_function/ft_strlen.c ./str_function/ft_strmapi.c ./str_function/ft_strncmp.c ./str_function/ft_strnstr.c \
./str_function/ft_strrchr.c ./str_function/ft_strtrim.c ./str_function/ft_substr.c ./str_function/ft_utoa_base.c \
./str_function/ft_split_cset.c ./str_function/ft_atod.c ./str_function/ft_strisnum.c ./str_function/ft_dtoa.c \
./ft_printf/convert_c.c ./ft_printf/convert_nb.c ./ft_printf/convert_percent.c ./ft_printf/convert_s.c \
./ft_printf/flags_nb.c ./ft_printf/ft_printf_utils.c ./ft_printf/ft_printf_utils2.c ./ft_printf/ft_printf_utils3.c \
./ft_printf/ft_printf.c \
./GNL/get_next_line_utils.c ./GNL/get_next_line.c


SRCS_BONUS = ./list_function/ft_lstnew_bonus.c ./list_function/ft_lstadd_front_bonus.c ./list_function/ft_lstsize_bonus.c \
./list_function/ft_lstlast_bonus.c ./list_function/ft_lstadd_back_bonus.c ./list_function/ft_lstdelone_bonus.c \
./list_function/ft_lstclear_bonus.c ./list_function/ft_lstiter_bonus.c ./list_function/ft_lstmap_bonus.c

OBJET = ${SRCS:.c=.o}

OBJET_BONUS = ${SRCS_BONUS:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -g -Wall -Werror -Wextra

%.o : %.c ${HEADER}
	@echo "${GREEN}[OK]${NC}	${YELLOW}Compiling :${NC}" $<
	@${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

$(NAME): ${OBJET} ${HEADER}
	@ar src ${NAME} ${OBJET}

bonus: ${OBJET} ${OBJET_BONUS} ${HEADER}
	@ar src ${NAME} ${OBJET} ${OBJET_BONUS}

clean:
	@${RM} ${OBJET} ${OBJET_BONUS}

fclean: clean
	@${RM} ${NAME} ../${NAME}

re:     fclean ${NAME}

.PHONY: all clean fclean re bonus
