set dgrid3d 30,30
set title "Graphique 3D avec Gradient de Couleur"
set xlabel "Axe X"
set ylabel "Axe Y"
set zlabel "Axe Z"
set pm3d at s  # Active le mode pm3d pour la coloration de surface
set palette defined (0 "blue", 1 "green", 2 "yellow", 3 "red")  # Définit le gradient de couleur
set terminal png
set output "output.png"
splot "data_NAIVE.txt" using 1:2:3 with pm3d
set output
