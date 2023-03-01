# Astronid Colony Management System

En tant qu'explorateur de l'espace, vous avez été chargé de la gestion de colonies sur des planètes lointaines. A la suite de la découverte d'un nouveau type de vie extraterrestre, vous vous êtes vu confier la gestion de la colonie de cette nouvelle espèce.

Vous devez donc développer un système capable de prédire les développements de ce nouvel être unicellulaire.

## Fonctionnement

Heureusement pour vous, une équipe de scientifiques a déjà étudié cette nouvelle espèce et a pu déterminer un certain nombre de faits sur son comportement. Ils ont également mis au point un mode de culture permettant de reproduire les conditions de vie de cette nouvelle espèce.

### Description de l'espèce et du milieu de culture

- Vous disposez d'un milieu de culture contenant des cellules de la nouvelle espèce.
- La taille du milieu de culture est variable
- Chaque cellule peut se trouver dans un de ces deux états : vivante ou morte
- Chaque cellule possède 8 voisins (en diagonale ou non) (les bords du milieu de culture sont considérés comme des cellules mortes)
- Chaque cellule possède un état initial (vivante ou morte)
- Les cellules vivantes peuvent mourir et les cellules mortes peuvent renaître

### Règles de développement

- Une cellule vivante avec moins de 2 voisins vivants meurt de solitude
- Une cellule vivante avec plus de 3 voisins vivants meurt de surpopulation
- Une cellule vivante avec 2 ou 3 voisins vivants survit
- Une cellule morte avec exactement 3 voisins vivants devient une cellule vivante

### Exemple

Voici un exemple de milieu de culture incluant 9 cellules vivantes :

```
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 1 1 1 0 0 0
0 0 0 1 1 1 0 0 0
0 0 0 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
```

Après un cycle de développement, le milieu de culture devient :

```
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0
0 0 0 1 0 1 0 0 0
0 0 1 0 0 0 1 0 0
0 0 0 1 0 1 0 0 0
0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
```

Comme vous pouvez le constater, les cellules centrales sont mortes par surpopulation et les cellules qui les entouraient sont revenues à la vie.

## Votre mission

Vous devez développer un système capable de prédire les développements de cette nouvelle espèce. Pour cela, vous devez :

- Créer un programme graphique permettant de visualiser le milieu de culture, ainsi que les états des cellules
- Générer un milieu de culture aléatoire
- Varier la vitesse de développement de l'espèce (par exemple, 1 cycle toutes les secondes, 10 cycles toutes les secondes, etc.)
- Permettre de mettre en pause le développement de l'espèce
- Permettre de relancer le développement de l'espèce

Les ordinateurs dont vous disposez sont anciens (soucis de budget de la NASA), il est donc préférable de ne pas utiliser de librairies graphiques trop lourdes. Vous pouvez utiliser la SFML.

## Bonus

- Une fois votre simulation fonctionnelle, vous pouvez vous amuser à trouver des configurations de milieu de culture particulièrement intéressantes (stables, mouvantes, etc.)
- Vous pouvez également ajouter des fonctionnalités supplémentaires (par exemple, des indicateurs pour suivre l'évolution de la population, etc.)

#

#

#

*les plus perspicaces auront remarqué que ce projet est inspiré du célèbre jeu de Conway, le jeu de la vie*

*https://fr.wikipedia.org/wiki/Jeu_de_la_vie*
*https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life*
*https://www.youtube.com/watch?v=C2vgICfQawE*
