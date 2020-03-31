##Projet C++ : TO DO LIST##

Afin de lancer le programme, il faut taper dans un terminal:
g++ todolist.cpp
puis
./a.out

On a alors un menu déroulant qui apparaît dans le terminal.
Si on tape 0, on sauvegarde les données dans un fichier text associé au repo git et on ferme la session en cours.
Si on tape 1, on peut afficher la liste des tâches et les selectionner pour les modifier ou même les supprimer.
Si on tape 2, on peut ajouter une tache (l'ajout de sous-taches se faisant via le menu optenu en tapant 1)
Si on tape 3, on efface tout ce qui est contenu dans la liste de taches en cours.

Cependant, il ne faut pas utiliser d'espace car cela cause des erreurs.
Pour le choix de la date de fin ou de création, je n'ai pas utilisé de bibliothèque permettant de la prendre directement dans l'horloge. Il faut donc les rentrer manuellement.
Je n'ai pas réussi à coder de fonction permettant de sélectionner les tâches en fonction de paramètres tels que leur priorité,...

Mon programme ne remplit pas les exigences demandées. En effet, il parvient bien à enregistrer les tâches dans un fichier mais il ne parvient pas à lire le fichier, ce qui est problématique.