#!/bin/bash

# Assurez-vous d'être dans le répertoire où se trouvent vos fichiers .xpm
cd textures8

# Boucle sur tous les fichiers .xpm
for fichier in *.xpm; do
    # Vérifie si le fichier est un fichier .xpm
    if [ -f "$fichier" ]; then
        # Applique la commande de conversion à chaque fichier .xpm
        convert "$fichier" -scale 8x8 "$fichier"
    fi
done

