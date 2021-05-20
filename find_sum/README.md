Результаты тестов занимательные, брутфорс работает быстрей. Вариант с сортировкой настолько сильно вымывает кэш процессора?


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