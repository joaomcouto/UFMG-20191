#!/bin/bash

gnuplot <<- EOF

set title "Tempo de Execução"
set xlabel "Tamanho do vetor"
set ylabel "Centésimos de segundo"
set xrange [0:10000000]
#set yrange [0:450]
set grid
set terminal postscript eps enhanced lw 3 "Times-Roman" 24
set term png
set output "grafico_array.png"
plot \
"time/MOM.txt" with linespoints pt 7 ps 0.5 title "MOM",\
"time/Quickselect.txt" with linespoints pt 8 ps 0.5 title "Quickselect",\

EOF
