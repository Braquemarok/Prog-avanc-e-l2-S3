CC = g++
CFLAGS = -Wall -Wextra -Wpedantic -g
LDFLAGS = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
SRC = main.cpp
BIN = game

$(BIN): $(SRC) World.h Joueur.h Monstre.h Map.h Tir.h Sound.h Lecteur.h Game.h
	$(CC) $(CFLAGS) $(SRC) -o $(BIN) $(LDFLAGS)


clean:
	rm -f $(BIN)
