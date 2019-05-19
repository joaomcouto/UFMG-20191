#!/bin/bash

N=100
T=100000
NUM_IT=5

mkdir -p results/

mkdir -p results/MOM
mkdir -p results/Quickselect

for i in `seq $N`
do

  R=$(($i*$T))
  printf "N -> $R\n"

  ./create_array $R $NUM_IT

  D=0
  for j in MOM Quickselect
  do

    D=$(($D+1))
    mkdir -p results/$j/num_$R/

    for k in `seq $NUM_IT`
    do
      FILE_IN="file/array$k.txt"
      FILE_OUT="results/$j/num_$R/time$k.txt"
      /usr/bin/time -f "%E" -o $FILE_OUT ./../array $FILE_IN $D  > lixo
    done
  done

done

TOT=$(($N*$T))

./mean_array $TOT $T

rm lixo
