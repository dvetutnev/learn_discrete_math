Есть массив целых чисел и число K. Найти два таких (не обязательно различных) числа в массиве, сумма которых равна K, либо вывести, что таких чисел нет.

```
([3, 1, 2], 3) => [1, 2]
([4, 6, 5], 6) => None
([3], 6) => None
([4, 5, 1, 3], 8) => [5, 3]

Time - O(N) или O(NlogN)

Time - O(N), Mem - O(N)
Time - O(NlogN), Mem - O(1)
```


Результаты тестов довольно занимательные, брутфорс работает быстрей. Вариант с сортировкой настолько сильно вымывает кэш процессора?


```
2021-05-21T01:38:30+03:00
Running /home/dvetutnev/learn_discrete_math/build/bin/benchmark_find_sum
Run on (8 X 4000 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x4)
  L1 Instruction 32 KiB (x4)
  L2 Unified 256 KiB (x4)
  L3 Unified 8192 KiB (x1)
Load Average: 1.25, 1.38, 1.45
***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.
--------------------------------------------------------------
Benchmark                    Time             CPU   Iterations
--------------------------------------------------------------
BM_bruteforce/10          59.6 ns         59.6 ns     10292577
BM_bruteforce/100         6904 ns         6902 ns        99157
BM_bruteforce/1000         224 ns          224 ns      3134954
BM_bruteforce/10000      41741 ns        41732 ns        16819
BM_sort/10                 268 ns          268 ns      2640897
BM_sort/100               3456 ns         3455 ns       199644
BM_sort/1000             99781 ns        99779 ns         6895
BM_sort/10000          1793285 ns      1793218 ns          388
```

Update: в предыдущем варианте была написана какая-то фигня. Результаты исправленной версии (не сказать, что крутые алгоритмы на современных машинах дают заметный прирост).


```
[nix-shell:/home/learn_discrete_math/sbuild]$ bin/benchmark_find_sum 
2021-05-24T02:43:42+03:00
Running bin/benchmark_find_sum
Run on (8 X 4000 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x4)
  L1 Instruction 32 KiB (x4)
  L2 Unified 256 KiB (x4)
  L3 Unified 8192 KiB (x1)
Load Average: 0.46, 0.37, 0.34
***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.
--------------------------------------------------------------
Benchmark                    Time             CPU   Iterations
--------------------------------------------------------------
BM_bruteforce/10          58.7 ns         58.7 ns     10878412
BM_bruteforce/100         6616 ns         6616 ns       102779
BM_bruteforce/1000        1234 ns         1234 ns       556338
BM_bruteforce/10000       4783 ns         4783 ns       134932
BM_sort/10                 394 ns          394 ns      1774242
BM_sort/100               5091 ns         5090 ns       127557
BM_sort/1000              2730 ns         2730 ns       237647
BM_sort/10000             9333 ns         9333 ns        71690

[nix-shell:/home/learn_discrete_math/sbuild]$ bin/benchmark_find_sum 
2021-05-24T02:43:56+03:00
Running bin/benchmark_find_sum
Run on (8 X 4000 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x4)
  L1 Instruction 32 KiB (x4)
  L2 Unified 256 KiB (x4)
  L3 Unified 8192 KiB (x1)
Load Average: 0.50, 0.39, 0.34
***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.
--------------------------------------------------------------
Benchmark                    Time             CPU   Iterations
--------------------------------------------------------------
BM_bruteforce/10          57.1 ns         57.1 ns     11544208
BM_bruteforce/100         6842 ns         6842 ns       102737
BM_bruteforce/1000        3159 ns         3159 ns       216742
BM_bruteforce/10000       2636 ns         2636 ns       262513
BM_sort/10                 491 ns          491 ns      1791373
BM_sort/100               5219 ns         5218 ns       128628
BM_sort/1000              5070 ns         5069 ns       136679
BM_sort/10000             5881 ns         5881 ns       112135
```
