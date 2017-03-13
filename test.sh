#! /bin/bash

for file in q*.out
do
  echo $file
  for i in {1..8}
  do
    ./$file $i
  done
  echo
done

echo matmul.out
./matmul.out
