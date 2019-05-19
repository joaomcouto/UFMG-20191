#!/bin/bash

gnuplot <<- EOF

set title "Tempo de Execução"
set xlabel "Número de Arestas"
set ylabel "Centésimos de segundo"
set xrange [0:10000000]
#set yrange [0:450]
set grid
set terminal postscript eps enhanced lw 3 "Times-Roman" 24
set term png
set output "grafico_graph.png"
plot \
"time/camerini.txt" with linespoints pt 3 ps 0.5 title "Camerini",\
"time/camerini_sorted.txt" with linespoints pt 4 ps 0.5 title "Camerini Sorted",\
"time/prim.txt" with linespoints pt 6 ps 0.5 title "Prim",\
"time/kruskal.txt" with linespoints pt 7 ps 0.5 title "Kruskal",\
"time/boruvka.txt" with linespoints pt 5 ps 0.5 title "Boruvka"

EOF
