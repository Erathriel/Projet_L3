# Projet_L3

http://gamedevframework.github.io/v0.6.0/build_and_install.html

# Réunion de projet 3

transformable::scale pour le fond à la place de renderState

dt à la place de timescale dans le step de la physique

article génération procédurale: http://fbksoft.com/procedural-level-generation-for-a-2d-platformer/

utiliser array de gf pour faire un tableau à 2 dimensions avec la structure du niveau

config.h.in pour mettre les ressources de data en local

RAPPORT:

page de couverture, de haut en bas: logo de l'univ, nos noms, notre classe, ce que c'est, le titre du projet, une image, la date, l'encadrant, l'année

Remerciements (facultatif)

Intro 1 ou 2 pages, commencer par parler du projet

I Conception: modèles UML, génération procéd, choix techniques (box2d), outils utilisés...

II Réalisation: implémentation, boucle jeu, components, gameprogrammingpatterns...

Conclusion (ou 3e partie): génie logiciel, gestion de projet, comment on a travaillé, github, IDE, virtualbox, métaprojet

# Modifier/ajouter du code au projet

Tout ce qui est à modifier est dans /jeu/game normalement.
Le main est dans code/, les autres .cc dans code/local.
Lorsque vous ajoutez un .cc, il faut:
- modifier le CMakeLists.txt du dossier game et ajouter les .cc là où le commentaire l'indique
- modifier code/XUnityBuild.cc et y ajouter les .cc également

Pour compiler pour la première fois, supprimez le dossier CMakesFiles et le fichier CMakeCache.txt dans /jeu et dans /jeu/game puis mettez-vous dans /jeu, faire

cmake .

make

L'exécutable "game" sera dans /jeu/game. Pour compiler les prochaines fois, make suffit.

# Petit rappel pour les commandes linux git

- git pull : mettre à jour sa version local
- git add . : ajoute tous les fichiers du repertoire courant dans un commit
- git commit : permet de voir les changements qui seront apportés avec les commits en cours et de les editer ( message obligatoire )
- git push : pousse les modifs local sur le serveur git

# Réunion de projet 2

pattern input draw render (un peu comme MVC)

loop{

input C

update M

render V

}

http://gameprogrammingpatterns.com/

groupe de tuiles = une seule longue collision pour ne pas avoir de problèmes de collision

lire manuel box2D (traverser plateforme) http://box2d.org/manual.pdf
 et http://www.iforce2d.net/b2dtut/
 
camera -> view (enlever caméra)

HUD -> screenview

enlever tuile -> voir tuto sfml https://www.sfml-dev.org/tutorials/2.1/graphics-vertex-array-fr.php exemple tilemap (remplacer sf par gf en général suffit)

-> remplacer tuile par map

dans gf, la classe tile layer le fait

levelExit -> plutôt une fonction de level (sensor)

static, kinematic, dynamic = ne bouge pas, bouge sans lois physiques, bouge avec lois physiques

faire des prototypes, noter ce qu'on fait


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
