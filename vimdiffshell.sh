#!/bin/bash

echo -n "Filename: "
read filename

echo -n "Directory 1: "
read directory1

echo -n "Directory 2: "
read directory2


vimdiff "$directory1/$filename" "$directory2/$filename"
