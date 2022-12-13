#!/bin/bash

less ./sources/data/README
./sources/my_pacman
while [ ${?} == 42 ]
do
    ./sources/my_pacman
done
