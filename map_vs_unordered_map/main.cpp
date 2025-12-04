// Compare the lookup performance between map and unordered_map
// with large datasets

#include <iostream>
#include <map>
#include <unordered_map>
#include <chrono>
#include <random>
#include <vector>

int main() {
    // Number of random keys to generate
    const int N = 1000000;

    // Create a  vector to store random keys
    std::vector<int> keys;

    // Ordered map and unordered_map
    std::map<int, int> map;
    std::unordered_map<int, int> un_map;

    // Random number generator initialization using a non-deterministic seed
    std::mt19937 rng{std::random_device{}()};

    // Generate random integers between 1 and 1,000,000
    std::uniform_int_distribution<int> dist(1, 1000000);

    // Generate N random keys and insert them into both maps
    for (int i=0; i < N; ++i) {
        int key = dist(rng); // Generate a random key
        keys.push_back(key); // Saving the key
        map[key] = i;
        un_map[key] = i;
    }

    // Benchmark lookup time in ordered map (std::map)
    auto start = std::chrono::high_resolution_clock::now();
    // Lookup 1000 keys in the ordered map
    for (int i = 0; i < 1000; ++i) {
        // Use volatile to prevent compiler optimizations that could remove this code
        volatile int val = map[keys[i]];
    }
    auto end = std::chrono::high_resolution_clock::now();
    // Calculate and print the duration of lookups in microseconds
    std::cout << "map lookup time: "
        << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
        << " μs\n";

    // Benchmark lookup time in unordered map (std::unordered_map)
    start = std::chrono::high_resolution_clock::now();
    // Lookup 1000 keys in the unordered map
    for (int i = 0; i < 1000; ++i) {
        volatile int val = un_map[keys[i]];
    }
    end = std::chrono::high_resolution_clock::now();
    // Calculate and print the duration of lookups in microseconds
    std::cout << "unordered_map lookup time: "
        << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
        << " μs\n";

    return 0;
}
