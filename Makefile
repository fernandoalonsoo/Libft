# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fealonso <fealonso@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 17:35:23 by fealonso          #+#    #+#              #
#    Updated: 2024/09/24 09:51:25 by fealonso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Creamos la libreria estatica ar rcs
LIB = ar rcs

# Definimos el compilazor que vamos a utilizar
CC = gcc

# Definimos el nombre del archivo generado el cual será una libreria estatica
NAME = libft.a


# Coloreamos los mensajes de consola
NOC = \033[0m
YELLOW = \033[1;33m
GREEN = \033[1;32m
RED = \033[1;31m

# Lista de archivos que forman parte de la libreria

SRC = src/ft_isalpha.c \
	   src/ft_memcmp.c \
	   src/ft_strnstr.c \
	   src/ft_atoi.c \
	   src/ft_isascii.c \
	   src/ft_memcpy.c \
	   src/ft_memmove.c \
	   src/ft_strlcat.c \
	   src/ft_strrchr.c \
	   src/ft_bzero.c \
	   src/ft_isdigit.c \
	   src/ft_memset.c \
	   src/ft_strlcpy.c \
	   src/ft_isprint.c \
	   src/ft_strchr.c \
	   src/ft_strlen.c \
	   src/ft_tolower.c \
	   src/ft_isalnum.c \
	   src/ft_memchr.c \
	   src/ft_strdup.c \
	   src/ft_strncmp.c \
	   src/ft_toupper.c \
	   src/ft_calloc.c \
	   src/ft_substr.c \
	   src/ft_strjoin.c \
	   src/ft_strtrim.c \
	   src/ft_itoa.c \
	   src/ft_split.c \
	   src/ft_strmapi.c \
	   src/ft_striteri.c \
	   src/ft_putchar_fd.c \
	   src/ft_putstr_fd.c \
	   src/ft_putendl_fd.c \
	   src/ft_putnbr_fd.c

# Los archivos generados al compilar pasarán de ser .c en .o 

OBJ = ${SRC:.c=.o} 

B_SRC = src/ft_lstnew.c \
		src/ft_lstadd_front.c \
		src/ft_lstsize.c \
		src/ft_lstlast.c \
		src/ft_lstadd_back.c \
		src/ft_lstdelone.c \
		src/ft_lstclear.c \
		src/ft_lstiter.c \
		src/ft_lstmap.c

# Los archivos generados al compilar pasarán de ser .c en .o

B_OBJ = ${B_SRC:.c=.o}

# Opciones de compilacion
FLAGS = -Wall -Werror -Wextra

# Incluimos libft.h en una variable el cual contiene todas las cabeceras
INCLUDE = libft.h

# Regla principal que se ejecuta cuando se llama al make
all: ${NAME}

# Unico mensaje que se imprime al comenzar la compilación
start:
	@echo "$(YELLOW)Compiling libft ...$(NOC)"

# Indica como crear la libreria libft.a a partir de archivos .o
${NAME}: start ${OBJ} ${INCLUDE}
	@${LIB} ${NAME} ${OBJ}
	@echo "$(GREEN)Libft compiled ✓$(NOC)"

# Compilamos los archivos .c en .0 usando gcc y las flags
%.o: %.c
	@${CC} ${CCFLAGS} -c -o $@ $<

bonus: start ${B_OBJ} ${INCLUDE}
	@${LIB} ${NAME} ${B_OBJ}
	@echo "$(GREEN)Libft compiled with bonus ✓$(NOC)"

# Elimina los archivos objeto .o
clean:
	@rm -f ${OBJ} ${B_OBJ}
	@echo "$(RED)Lift objects deleted ✓$(NOC)"

# Tambien eliminamos la libreria libft.a
fclean: clean
	@rm -f ${NAME}
	@echo "$(RED)Lift deleted ✓$(NOC)"

# Limpia todo y recompila desde cero (all)
re: fclean all

# Declaramos las reglas que no generan archivos para que make las ejecute correctamente
.PHONY: all clean fclean
