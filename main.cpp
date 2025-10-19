#include <iostream>

// Jednoduchá typová reprezentace seznamu typů
template <typename...>
struct list {};

// Funkce pro vytvoření prázdného typového seznamu
template <typename... Ts>
constexpr inline list<> make_empty() { return {}; }

// "Customization point" šablona, která bude volána při destrukci Bar
template <typename... Ts>
struct customization_point {
    static void foo() {
        std::cout << "customization_point<";
        ((std::cout << typeid(Ts).name() << " "), ...);
        std::cout << ">::foo() called\n";
    }
};

// Třída Bar, která při destrukci volá "customization point"
template <typename... Ts>
struct Bar {
    ~Bar() {
        // Volání "customization point" s typovým seznamem
        []<typename... E>(list<E...>) {
            customization_point<E...>::foo();
        }(make_empty<Ts...>());
    }
};

int main() {
    Bar<int, double, char> b;
    return 0;
}