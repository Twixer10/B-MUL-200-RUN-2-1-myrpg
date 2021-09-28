##
## EPITECH PROJECT, 2020
## makefile exe
## File description:
## fct
##

SRC	=		src/main.c	\
			src/play/view.c\
			src/play/player.c\
			src/assets/assets_manager.c	\
			src/assets/hud.c \
			src/assets/inventory.c \
			src/assets/item_storage.c \
			src/windows/windows_manager.c \
			src/loops/loop_menu.c \
			src/loops/loop_ng.c	\
			src/loops/loop_play.c \
			src/loops/loop_setting.c \
			src/button/button_manager.c \
			src/button/slide_manager.c \
			src/button/slider.c \
			src/utils/utils.c \
			src/utils/btn_sel.c	\
			src/utils/ng_class.c \
			src/credit/credit.c	\
			src/inputs/textbox.c \
			src/assets/music_manager.c \
			src/free/free_manager.c \
			src/map/add.c \
			src/map/draw.c \
			src/map/free.c \
			src/map/get.c \
			src/map/collision.c \
			src/map/init.c \
			src/lost/lostfile1.c

CFLAGS	=	-W -Wextra -Wall -Werror -g3

LFLAGS	=	-L lib/my -lmy -l csfml-audio -l csfml-graphics -l csfml-network -l csfml-system -l csfml-window ./lib/mxml/libmxml.a -lpthread

IFLAGS	=	-I include/

NAME	=	my_rpg

all:
	make -C lib/my all
	gcc -o $(NAME) $(SRC) $(IFLAGS) $(LFLAGS) $(CFLAGS)

clean:
	make -C lib/my clean
	rm -f *~
	rm -f *.o

fclean:
	make -C lib/my fclean
	rm -f $(NAME)

re:	fclean all
	make -C lib/my re
