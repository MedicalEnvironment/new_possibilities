#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>

std::unique_ptr<std::vector<int>> removeDuplicates(const std::vector<int>& numbers) {
    std::unordered_set<int> uniqueSet;
    std::unique_ptr<std::vector<int>> result = std::make_unique<std::vector<int>>();

    for (const auto& number : numbers) {
        if (uniqueSet.find(number) == uniqueSet.end()) {
            uniqueSet.insert(number);
            result->push_back(number);
        }
    }

    return result;
}

int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 2, 4, 6, 3, 1 };

    std::unique_ptr<std::vector<int>> uniqueNumbers = removeDuplicates(numbers);

    std::cout << "Unique numbers: ";
    for (const auto& number : *uniqueNumbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}
