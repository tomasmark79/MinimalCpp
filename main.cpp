#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>

// Ukázka třídy s moderním C++
class Example {
private:
    std::string name;
    int value;

public:
    Example(const std::string& n, int v) : name(n), value(v) {
        std::cout << "Example '" << name << "' vytvořen\n";
    }
    
    ~Example() {
        std::cout << "Example '" << name << "' zničen\n";
    }
    
    void print() const {
        std::cout << "  " << name << ": " << value << "\n";
    }
    
    int getValue() const { return value; }
    const std::string& getName() const { return name; }
};

// Ukázka template funkce
template<typename T>
void printVector(const std::vector<T>& vec, const std::string& label) {
    std::cout << label << ": [";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}

// Ukázka lambda funkce a algoritmů
void demonstrateLambdas() {
    std::cout << "\n=== Lambda funkce a algoritmy ===\n";
    std::vector<int> numbers = {5, 2, 8, 1, 9, 3};
    
    printVector(numbers, "Původní");
    
    std::sort(numbers.begin(), numbers.end());
    printVector(numbers, "Seřazené");
    
    auto even = std::count_if(numbers.begin(), numbers.end(), 
                             [](int n) { return n % 2 == 0; });
    std::cout << "Sudá čísla: " << even << "\n";
}

// Ukázka smart pointerů
void demonstrateSmartPointers() {
    std::cout << "\n=== Smart pointery ===\n";
    auto ptr = std::make_unique<Example>("Unique pointer", 42);
    ptr->print();
    
    auto shared1 = std::make_shared<Example>("Shared pointer", 100);
    {
        auto shared2 = shared1; // Sdílená reference
        std::cout << "Use count: " << shared1.use_count() << "\n";
    }
    std::cout << "Use count po scope: " << shared1.use_count() << "\n";
}

int main() {
    std::cout << "=== Minimální C++ Template ===\n";
    std::cout << "C++ standard: " << __cplusplus << "\n";
    
    // Ukázka základních objektů
    std::cout << "\n=== Objekty ===\n";
    Example obj1("První", 10);
    Example obj2("Druhý", 20);
    obj1.print();
    obj2.print();
    
    // Lambdas a STL
    demonstrateLambdas();
    
    // Smart pointers
    demonstrateSmartPointers();
    
    std::cout << "\n=== Konec programu ===\n";
    return 0;
}