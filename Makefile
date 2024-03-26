NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror


SRC = src.c zoom.c main.c fractal.c src2.c
OBJ = ${SRC:.c=.o}
all: ${NAME}

${NAME}: ${OBJ}
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)
	@clear
	@echo  "\033[0;32m		Compilation done\n"
	@echo "\033[0;93m		Run ./fractol"
	@echo "		Usage: ./fractol [fractal]"
	@echo "		Fractals: mandelbrot, julia, tricorn\n"
	@echo "\033[1;31m		Example: ./fractol mandelbrot"
	@echo "		Example: ./fractol julia"
	@echo "		Example: ./fractol tricorn\n"
	@echo "\\033[0;36m		Usage: "
	@echo "        		Zoom : scroll"
	@echo "        		Move : arrows"
	@echo "        		Change color : H, G, F"
	@echo "        		Change fractal : M, J, T"
	@echo "        		Reset : middle mouse click"
	@echo "        		Exit : ESC\n\n"
	@echo "\033[0;97m							Enjoy!\n"
	@echo "						Made by: yasbelgh"

	
clean:
	@rm -f $(OBJ)
	@clear

fclean: clean
	@rm -f $(NAME)
	@clear


re: fclean all