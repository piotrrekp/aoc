#!/bin/bash

test1=abcdef609043
test2=pqrstuv1048970



INPUT=iwrupvqb
# number=346370 #first part answer
number=346300
begin=x
while [ "$begin" != "000000" ] ; do
	begin=$(echo -n $INPUT$number | md5sum | cut -c1-6)
	number=$((number + 1))
	echo $((number - 1 )) with $begin
done
echo $((number - 1))


