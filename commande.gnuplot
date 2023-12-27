# Premier graphique avec échelle logarithmique
set terminal png
#set title "Évolution du temps en fonction de la taille de l'entrée en échelle logarithmique"
set output 'benchmark/FFT_vs_NAIVE_log.png'
set xlabel 'degrée du polynome'
set ylabel 'temps (en seconde)'
set xrange [1:15000]
set logscale x
set logscale y
set yrange [1e-8:1e-1]
set format y '%.1e'
plot 'benchmark/data_FFT.txt' using 1:2 with lines title 'fftMultiplyPolynomials', \
     'benchmark/data_NAIVE.txt' using 1:2 with lines title 'naiveMultiplyPolynomials'

# Deuxième graphique sans échelle logarithmique
set key top left
#set title "Évolution du temps en fonction de la taille de l'entrée"
set output 'benchmark/FFT_vs_NAIVE.png'
unset logscale y # Retour à l'échelle linéaire pour l'axe des y
unset logscale x
set yrange [1e-5:1e-2]
set format y '%g' # Format par défaut ou adapté à vos données
plot 'benchmark/data_FFT.txt' using 1:2 with lines title 'fftMultiplyPolynomials', \
     'benchmark/data_NAIVE.txt' using 1:2 with lines title 'naiveMultiplyPolynomials'


# ZOOM
set key top left
#set title "Évolution du temps en fonction de la taille de l'entrée"
set output 'benchmark/FFT_vs_NAIVE_zoom.png'
set xrange [4000:6000]
set yrange [1e-5:1e-2]
set format y '%g' # Format par défaut ou adapté à vos données
plot 'benchmark/data_FFT.txt' using 1:2 with lines title 'fftMultiplyPolynomials', \
     'benchmark/data_NAIVE.txt' using 1:2 with lines title 'naiveMultiplyPolynomials'

# THEORIQUE


#
set key top left
#set title "Évolution du temps en fonction de la taille de l'entrée"
set output 'benchmark/FFT_vs_NAIVE_THEO.png'
set yrange [0:140000]
unset xrange
set logscale x
plot 'benchmark/data_FFT_THEO.txt' using 1:2 with lines title 'fftMultiplyPolynomials', \
     'benchmark/data_NAIVE_THEO.txt' using 1:2 with lines title 'naiveMultiplyPolynomials'