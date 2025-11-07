#include <iostream>
#include <chrono>
#include "TreeMap.h"

int main() {
    TreeMap map;

    
    map.insert("keyOne", "valueOne");
    map.insert("keyTwo", "valueTwo");
    map.insert("keyThree", "valueThree");

    std::cout << "Get keyOne: " << map.get("keyOne") << "\n";
    std::cout << "Get keyThree: " << map.get("keyThree") << "\n";
    std::cout << "Get missing key: " << map.get("missingKey") << "\n";

    
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000; ++i)
        map.insert("key" + std::to_string(i), "value" + std::to_string(i));
    auto end = std::chrono::high_resolution_clock::now();

    double seconds = std::chrono::duration<double>(end - start).count();
    std::cout << "Inserted 10,000 keys in " << seconds << " seconds.\n";

    return 0;
}