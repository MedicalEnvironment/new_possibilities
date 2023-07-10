#include <iostream>
#include <initializer_list>

int main() {
    std::initializer_list<int> numbers = {1, 2, 3, 4, 5};
  
    for (auto number : numbers) {
        std::cout << number << " ";
    }
  
    return 0;
}
