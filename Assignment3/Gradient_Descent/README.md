# Gradient Descent

## System Configuration

Algorithm: Gradient Descent (one-variable polynomial minimization)

Function Form: f(x) = c0 + c1·x + c2·x² + ... + cd·x^d

Update Rule: x_new = x - learning_rate · f'(x)

Language: C++

Compiler: g++ (MinGW-w64 on Windows)

Note: Gradient Descent does not use a graph or CSR — it reads polynomial coefficients and scalar optimization parameters directly from its text file.

## Run Command

```bash
cd Gradient_Descent
mingw32-make
./gradientDescent.exe or ./gradientDescent.out (depending on OS)
```

Direct compile (equivalent to the Makefile target):

```bash
g++ -std=c++17 -O2 driver.cpp gradientDescent.cpp -o gradientDescent
./gradientDescent gd_01.txt
```

## Results Table

| Test File     | Degree | Initial x | Learning Rate | Tolerance | Max Iterations | Expected x* | Actual x         | Actual f(x)      | Iterations | Converged |         Time | Status |
| -------------- | -----: | --------: | -------------: | ---------: | --------------: | -----------: | ---------------- | ----------------- | ---------: | :-------: | -----------: | ------ |
| `gd_01.txt` |      2 |         0 |            0.10 |       1e-6 |            5,000 |            3 | 2.9999995063      | 0.0000000000       |         70 |    Yes    |  <1 μs (0 ms) | Pass   |
| `gd_02.txt` |      4 |         2 |            0.02 |       1e-6 |           10,000 |            0 | 0.0000002379      | 0.0000000000       |        180 |    Yes    |  <1 μs (0 ms) | Pass   |
| `gd_03.txt` |      6 |         2 |            0.02 |       1e-6 |           20,000 |            0 | 0.0000004835      | 0.0000000000       |        349 |    Yes    |  <1 μs (0 ms) | Pass   |
| `gd_04.txt` |      8 |         2 |            0.01 |       1e-8 |           50,000 |            0 | 0.0000000050      | 0.0000000000       |        948 |    Yes    |  <1 μs (0 ms) | Pass   |
| `gd_05.txt` |     10 |         2 |           0.005 |      1e-10 |          100,000 |            0 | 0.0000000000      | 0.0000000000       |      2,364 |    Yes    |  <1 μs (0 ms) | Pass   |

All five required polynomial degrees (2, 4, 6, 8, 10) converged to their expected minima within the specified tolerance and iteration budget.

**Execution time note:** All five runs reported `0.0000000000 ms`. Even the largest test (`gd_05.txt`, degree 10, 2,364 iterations) involves only a few floating-point multiply-adds per iteration, which completes well below the resolution of the timer being used. Per the assignment's timing-averaging allowance (Section 4.3 / Section 8), repeated runs would be needed to obtain a non-zero measurement; this was not done here, so the raw (effectively unmeasurable) time is reported as-is.

## Time Complexity

Algorithm: Gradient Descent (1D polynomial)

Time Complexity: O(d · k), where d is the polynomial degree and k is the number of iterations until convergence (or MAX_ITERATIONS)

Space Complexity: O(d) — storage for the d+1 coefficients

Each iteration evaluates f'(x) directly from the coefficient list in O(d) time, then applies the update rule x_new = x - learning_rate · f'(x). The loop stops as soon as |f'(x)| ≤ tolerance or the iteration cap is reached, so total work scales with both the degree of the polynomial and how many steps convergence takes.

## Notes

- Per the assignment's timing rule, only the gradient-descent update loop itself is timed. Reading the input file (degree, coefficients, initial x, learning rate, tolerance, max iterations) and printing the result are excluded from the timed region.
- The same polynomial-evaluation and derivative-evaluation implementation was used for every degree (2, 4, 6, 8, 10) — no per-test hard-coded objective function.
- All five required objective functions are convex with a single global minimum, so no divergence or local-minimum issues were encountered; every run converged (`Converged: true`) before hitting its iteration cap.
- Iteration count grows with degree (70 → 180 → 349 → 948 → 2,364) as higher-degree terms flatten the gradient near the minimum and tighten tolerances (down to 1e-10 for `gd_05`) require more refinement steps to satisfy |f'(x)| ≤ tolerance.
- Final x values for `gd_02`–`gd_05` converge to ~0, matching the expected minimum x* = 0; `gd_01` converges to ~3, matching its expected minimum x* = 3.
