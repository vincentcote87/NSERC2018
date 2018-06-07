#!/bin/bash
cd $1
for i in ./*; do
    cat $i >> $2'.txt'
done
