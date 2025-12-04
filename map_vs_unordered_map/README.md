# Performance Comparison: `map` vs `unordered_map` in C++

This project benchmarks the **lookup performance** of two standard associative containers:

- `std::map` (ordered, Red-Black Tree)
- `std::unordered_map` (hash table)

The goal is to observe how each structure behaves when performing **1,000 lookups** after inserting **1,000,000 random keys**.

---

## What the Program Does

1. Generates **1,000,000 random integers** between 1 and 1,000,000.  
2. Inserts all keys into:
   - a `std::map<int, int>`
   - a `std::unordered_map<int, int>`
3. Performs **1,000 lookups** in each container.
4. Measures the time using `std::chrono::high_resolution_clock`.
5. Prints the lookup times in **microseconds (μs)**.

---

## Why This Benchmark?

- `std::map` keeps elements **sorted**, using a self-balancing tree.  
  - Lookup: **O(log n)**

- `std::unordered_map` uses **hashing** and buckets.  
  - Lookup: **O(1)** average

This benchmark helps visualize that difference in a real scenario with a large dataset.

---

## Expected Result

As a rule of thumb:

- `unordered_map` → **much faster lookups**  
- `map` → slower, but maintains order
