NAME = ft_retro
FLAG = -Wall -Wextra -Werror -lncurses -o
SRC = main.cpp Player.cpp GameEntity.cpp Enemy.cpp Bullet.cpp


all:
	@clang++ $(FLAG) $(NAME) $(SRC)
	@echo "\033[32mBuilt $(NAME).\033[0m"
clean:
	@/bin/rm -f $(NAME)
	@echo "\033[32mCleaned up compiled files.\033[0m"
run: all
	./$(NAME)
