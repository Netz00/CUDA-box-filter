# Exercise 1

- *Napisati program koji će računati sumu niza unesenog od strane korisnika.*

- *Zadatak riješiti [sekvencijalno](./sequential.cpp), a zatim [paralelizirati](./parallel.cpp) problem koristeći pthread.*

- *U izvještaju objasniti kako ste paralelizirali problem, koliko niti je korišteno, te zašto.*

## Solution

Execute test code with:
```bash
gcc main.c parallel.c sequential.c array.c -o main -lpthread && ./main
```


### Reading/generating array
Code responsible for handling array can be found [here](./array.cpp).
- Read array from stdin
- Generate array randomly
- Print the array

### Sequential sum
Code responsible for sequential sum of array elements can be found [here](./sequential.cpp).
- Calculate sum of all elements in array and return the result

### Parallelised sum
Code responsible for parallelised sum of array elements can be found [here](./parallel.cpp).
1. Split the array in NUM_THREADS subarrays
2. Calculate sequential sum of each subarray in threads independetly 
3. Wait till all threads execute and then sum the results
- Number of threads 2, 4, 8 were tested, and 2 threads had best perfomance.


## Results
*NUM_THREADS 2*

Array Length |   PARALLEL    |  SEQUENTAL
-------------|---------------|------------
1            |   0.000800 s  |  0.000006 s
10           |   0.000442 s  |  0.000007 s
100          |   0.000480 s  |  0.000004 s
1000         |   0.000248 s  |  0.000008 s
10000        |   0.000473 s  |  0.000041 s
100000       |   0.000740 s  |  0.000423 s
1000000      |   0.004281 s  |  0.004002 s
10000000     | **0.036420 s**|  0.039574 s
100000000    | **0.380668 s**|  0.383230 s
1000000000   | **3.424999 s**|  3.814460 s

---
*NUM_THREADS 4*

Array Length |   PARALLEL    |  SEQUENTAL
-------------|---------------|------------
1            |   0.001346 s  |  0.000003 s
10           |   0.000741 s  |  0.000004 s
100          |   0.000475 s  |  0.000004 s
1000         |   0.000432 s  |  0.000007 s
10000        |   0.000575 s  |  0.000049 s
100000       |   0.000927 s  |  0.000417 s
1000000      |   0.004368 s  |  0.004082 s
10000000     | **0.044516 s**|  0.045308 s
100000000    | **0.359088 s**|  0.383255 s
1000000000   | **3.557832 s**|  3.849736 s

---

*NUM_THREADS 8*
Array Length |   PARALLEL    |  SEQUENTAL
-------------|---------------|------------
1            |   0.001610 s  |  0.000003 s
10           |   0.001116 s  |  0.000003 s
100          |   0.001086 s  |  0.000004 s
1000         |   0.000900 s  |  0.000007 s
10000        |   0.003290 s  |  0.000042 s
100000       |   0.001563 s  |  0.000397 s
1000000      |   0.005921 s  |  0.003818 s
10000000     |   0.038344 s  |  0.038660 s
100000000    |   0.394244 s  |  0.386456 s
1000000000   | **3.663846 s**|  3.875184 s


## Issue

Issue, using threads cause only negative efect on perfomance
 SEQUENTAL | PARALLEL
-----------|-----------
0.000003 s | 0.001128 s
0.009709 s | 0.011254 s
0.004552 s | 0.005289 s
0.004014 s | 0.004898 s
0.041205 s | 0.039637 s
0.379131 s | 0.392338 s
3.854432 s | 3.983880 s

Fix: Calling function from thread is not an option!

---