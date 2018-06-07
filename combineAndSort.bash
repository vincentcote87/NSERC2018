#!/bin/bash
if [ $# -ge 1 ]
then
	location="./$1/*"
else
	location="./*"
fi
unsorted=$(basename -a $location)
dirpath=${location::-1}
list=''
for f in $unsorted; do
	if [[ "$f"=~"^[0-9]+$" ]]
	then
		list=$list$dirpath$f' '
	fi
done
cat $list &> temporary
