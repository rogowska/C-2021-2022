#! /bin/bash

echo "Start main loop over przypadki list"

allprzypadki=(100 316 500 700 1000 3162 5000 7000 10000 31622 50000 70000 100000 316227)
    for przypadek in ${allprzypadki[@]}; do
        echo "wykonanie programu dla liczby przedzialow 99 i wylosowanych liczb: $przypadek"
        timeout 900 bash -c "time ./generator_wrapper.exp $przypadek"
    done
