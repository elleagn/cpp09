#!/bin/bash

runs=100
sum=0
max=0
count=0
size=32

for i in $(seq 1 $runs); do
    cmp=$(./PmergeMe $(shuf -i 1-1000 -n $size | tr "\n" " ") | grep "Comparisons:" | awk '{print $2}')

    echo "Run $i: [$cmp]"
	((count++))
	integ=$(printf "%d" "$cmp")
	sum=$((sum + integ))
	if (( integ > max )); then
		max=$integ
	fi
done

avg=$(echo "scale=2; $sum / $count" | bc)
echo "$count runs of size $size"
echo "Average comparisons: $avg"
echo "Maximum comparisons: $max"
