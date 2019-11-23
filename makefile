CC = g++
CFLAGS = -Wall -Wextra -Wpedantic -g
LDFLAGS = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
SRC = main.cpp Game.cpp entite/liste_entite.cpp entite/Entite.cpp entite/Animation.cpp entite/Joueur/Joueur.cpp entite/Monstres/Monstre.cpp entite/Tirs/Tir.cpp entite/Tirs/Tir1.cpp entite/Tirs/Tir2.cpp World.cpp Sound.cpp Lecteur.cpp
BIN = game

$(BIN): $(SRC) *.h entite/*.h entite/Joueur/*.h entite/Monstres/*.h entite/Tirs/*.h 
	$(CC) $(CFLAGS) $(SRC) -o $(BIN) $(LDFLAGS)


clean:
	rm -f $(BIN)
