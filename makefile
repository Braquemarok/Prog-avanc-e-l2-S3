CC = g++
CFLAGS = -Wall -Wextra -Wpedantic -g
LDFLAGS = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
SRC = main.cpp Game.cpp entite/Entite.cpp entite/Animation.cpp entite/Joueur/Joueur.cpp entite/Monstres/Monstre.cpp entite/Tirs/Tir.cpp entite/Tirs/Tir1.cpp entite/Tirs/Tir2.cpp World.cpp Sound.cpp Lecteur.cpp
BIN = game

<<<<<<< HEAD
$(BIN): $(SRC) World.h entite/Entite.h entite/Joueur/Joueur.h entite/Monstres/Monstre.h Map.h entite/Tirs/Tir.h entite/Tirs/Tir1.h entite/Tirs/Tir2.h Sound.h Lecteur.h entite/Animation.h
=======
$(BIN): $(SRC) World.h Joueur.h Monstre.h Map.h Tir.h Sound.h
>>>>>>> v2
	$(CC) $(CFLAGS) $(SRC) -o $(BIN) $(LDFLAGS)


clean:
	rm -f $(BIN)
