CC = g++
CFLAGS = -Wall -Wextra -Wpedantic -g
LDFLAGS = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
SRC = *.cpp Entites/*.cpp Entites/Joueur/*.cpp Entites/Monstres/*.cpp Entites/Tirs/*.cpp 
BIN = game

$(BIN): $(SRC) *.h Entites/*.h Entites/Joueur/*.h Entites/Monstres/*.h Entites/Tirs/*.h 
	$(CC) $(CFLAGS) $(SRC) -o $(BIN) $(LDFLAGS)


clean:
	rm -f $(BIN)
