#include <iostream>
#include <map>
#include <string>

int main() {
    int N;
    std::cout << "Enter the number of strings: ";
    std::cin >> N;

    std::map<std::string, float> freqMap;

    std::cout << "Enter the strings:\n";
    for (int i = 0; i < N; ++i) {
        std::string str;
        std::cin >> str;
        freqMap[str]++;
    }

    std::cout << "Unique strings in lexicographical order with their frequency:\n";
    for (auto it = freqMap.begin(); it != freqMap.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}