CC = g++
CFLAGS = -Wall -Wextra -Wpedantic -g
LDFLAGS = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
SRC = main.cpp
BIN = game

$(BIN): $(SRC) World.h entite/Entite.h entite/Joueur/Joueur.h entite/Monstres/Monstre.h Map.h entite/Tirs/Tir.h entite/Tirs/Tir1.h entite/Tirs/Tir2.h Sound.h Lecteur.h Game.h
	$(CC) $(CFLAGS) $(SRC) -o $(BIN) $(LDFLAGS)


clean:
	rm -f $(BIN)
