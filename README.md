🟦 Déplacement d’un carré bleu sur une interface verte — SDL3 & C++
📌 Description
Ce projet est une démonstration simple de l’utilisation de la bibliothèque SDL3 en C++ pour créer une interface graphique interactive. L’objectif est de déplacer un carré bleu à l’aide du clavier dans une fenêtre dont le fond est vert.
🛠️ Technologies utilisées
• 	Langage : C++
• 	Bibliothèque graphique : SDL3
• 	Outils de compilation : CMake (optionnel mais recommandé)
🎮 Fonctionnalités
• 	Création d’une fenêtre avec SDL3
• 	Affichage d’un fond vert
• 	Dessin d’un carré bleu
• 	Déplacement du carré avec les touches directionnelles du clavier (↑ ↓ ← →)
• 	Rafraîchissement fluide de l’affichage
📦 Installation
Prérequis
• 	Un compilateur C++ compatible C++17 ou supérieur
• 	SDL3 installée sur votre système
• 	(Optionnel) CMake pour faciliter la compilation
Compilation manuelle:

clang++ sdl3.cpp -o sdl -lsdl3

📁 Structure du projet:
sdl.exe
sdl3.cpp
readme 

🧠 Notes techniques
• 	Le carré est dessiné avec . SDL_Render
• 	Les événements clavier sont gérés via .SDL_Event
• 	Le rendu est mis à jour à chaque frame avec . SDL_RenderEvent

