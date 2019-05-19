#!/bin/bash

N=80
T=50
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
  printf "N -> $R\n"

  ./create_graph $R $NUM_IT

  D=0
  for j in camerini kruskal prim boruvka camerini_sorted
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
