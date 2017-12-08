# Projet_L3

http://gamedevframework.github.io/v0.6.0/build_and_install.html

# Modifier/ajouter du code au projet

Tout ce qui est à modifier est dans /jeu/game normalement.
Le main est dans code/, les autres .cc dans code/local.
Lorsque vous ajoutez un .cc, il faut:
- modifier le CMakeLists.txt du dossier game et ajouter les .cc là où le commentaire l'indique
- modifier code/XUnityBuild.cc et y ajouter les .cc également

Pour compiler, mettez-vous dans /jeu, faire
cmake .
puis
make
L'exécutable "game" sera dans /jeu/game.

# Petit rappel pour les commandes linux git

- git pull : mettre à jour sa version local
- git add . : ajoute tous les fichiers du repertoire courant dans un commit
- git commit : permet de voir les changements qui seront apportés avec les commits en cours et de les editer ( message obligatoire )
- git push : pousse les modifs local sur le serveur git

# Réunion de projet 1

article génération procédurale: http://fbksoft.com/procedural-level-generation-for-a-2d-platformer/

voir documentation de sfml (partie graphique équivalente)

utiliser box2D (ou le moteur physique inclut dans gf)

prendre les graphismes de http://kenney.nl/

installer gf sur les ordi de la fac:
_DCMAKE_INSTALL_DIR = ~/local
export PATH = $PATH:~/local/bin,~/local/games
export LD_LIBRARY_PATH = $LD_LIBRARY_PATH:~/local/lib

commenter le code

rapport technique

soutenance (20 à 30 minutes)

# Note :

- Ne mettez pas de maj et d'espace dans les noms de repertoire pour un parcours de l'arborescence le plus simple possible svp