GREEN = \033[0;32m
NC = \033[0m
YELLOW = \033[0;33m
WHITE=$'\x1b[37m'
IWHITE=\033[107;1;30m
BLACK=\033[0;30m

NAME = minirt.a

LIB = libft.a

HEADER = include/miniRT.h

SRCS = ./get_function/get_param.c ./get_function/get_view.c ./get_function/get_forms.c \
	./check_function/check_param.c ./check_function/check_view.c ./check_function/check_forms.c \
	./init_function/init_struct.c ./init_function/init_forms.c ./init_function/init_view.c \
	./parser.c \
	./free.c \
	./set_param.c
	

OBJET = ${SRCS:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -g -Wall -Werror -Wextra

%.o : %.c $'{HEADER}
	@echo "${GREEN}[OK]${NC}	${YELLOW}Compiling :${NC}" $<
	@${CC} ${CFLAGS} -I ${HEADER}  -c $< -o $@

all: ${NAME}

${NAME}: ${LIB} ${OBJET} ${HEADER}
	@ar src ${NAME} ${OBJET}

${LIB}:
	@echo "${GREEN}-------------------------------------${NC}"
	@echo "${GREEN}--------------- LIB_FT --------------${NC}"
	@echo "${GREEN}-------------------------------------${NC}"
	@make -C Libft all
	@echo "${GREEN}-------------------------------------${NC}"
	@echo "${GREEN}-------------- MINIRT ---------------${NC}"
	@echo "${GREEN}-------------------------------------${NC}"

clean:
	@${RM} ${OBJET}
	@make -C Libft clean
	@echo "Object has been supressed."

fclean: clean
	@${RM} ${NAME}
	@make -C Libft fclean
	@echo "minirt.a has been supressed."

re:     fclean ${NAME}

.PHONY: all clean fclean re