#!/bin/bash
END=50000000
START=10000000
STEP=10000000
for i in `seq $START $STEP $END`; do
    python3 -c "print('{:.2f}'.format(${i}/${END}*100), end='\r')"
    for j in {1..5}; do
        echo -e "$i,$(./cpp-version $i)$(./rust-version $i)" >> results.csv
    done
done
echo