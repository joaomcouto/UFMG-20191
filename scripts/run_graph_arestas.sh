#!/bin/bash

N=100
T=100000
NUM_IT=5

mkdir -p results/

mkdir -p results/camerini
mkdir -p results/camerini_sorted
mkdir -p results/kruskal
mkdir -p results/prim
mkdir -p results/boruvka

for i in `seq $N`
do

  R=$(($i*$T))
  PTS=$( echo "(sqrt((8*$R)+1)+1)/2" | bc  )
  printf "N -> $R - $PTS\n"

  ./create_graph $PTS $NUM_IT

  D=0
  for j in camerini camerini_sorted kruskal prim boruvka
  do

    D=$(($D+1))
    mkdir -p results/$j/num_$R/

    for k in `seq $NUM_IT`
    do
      FILE_IN="file/graph$k.txt"
      FILE_OUT="results/$j/num_$R/time$k.txt"
      /usr/bin/time -f "%E" -o $FILE_OUT ./../tp2 $FILE_IN $D > lixo
    done
  done

done

TOT=$(($N*$T))

./mean_graph $TOT $T

rm lixo
