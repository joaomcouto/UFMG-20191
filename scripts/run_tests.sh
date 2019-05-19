#!/bin/bash

IT=10
OK=0

./create_graph 4000 $IT
cd ..

for i in `seq $IT`
do
  printf "Iteration -> $i\n"
  ./tester "scripts/file/graph$i.txt"
done
