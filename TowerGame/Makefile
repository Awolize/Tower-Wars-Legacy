
# Makefile för lol
#

G	= g++
LFLAGS	= -L/usr/lib/x86_64-linux-gnu -lSDL -lm
SFML	= -I${SFML_ROOT}/include -L${SFML_ROOT}/lib -lsfml-system -lsfml-window -lsfml-graphics -lsfml-network

all: 	main.o Tower.o Player.o Soldier.o
	@echo "** Buidling the game..."
	$(G) -o TowerGame main.o Player.o Soldier.o Tower.o $(LFLAGS) $(SFML)

main.o:	main.cpp
	$(G) -c "main.cpp" -o main.o

Tower.o: Tower.cpp
	$(G) -c "Tower.cpp" -o Tower.o

Player.o: Player.cpp
	$(G) -c "Player.cpp" -o Player.o

Soldier.o: Soldier.cpp
	$(G) -c "Soldier.cpp" -o Soldier.o

clean:
	@echo "** Removing object files and executable..."
	@\rm -rf *.o *.gch core

zap: clean
	@\rm -f TowerGame *~
