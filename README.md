# MinimalCpp Template

Minimální C++ projekt s moderními praktikami pro rychlý start.

## Funkce

- ✅ CMake build systém
- ✅ C++20 standard
- ✅ Ukázky moderního C++:
  - Smart pointery (`unique_ptr`, `shared_ptr`)
  - Lambda funkce
  - STL algoritmy
  - RAII pattern
  - Template funkce

## Požadavky

- CMake 3.10+
- C++20 kompatibilní kompilátor (GCC 10+, Clang 10+, MSVC 2019+)

## Rychlý start

### Kompilace a spuštění

```bash
./compile.sh
```

### Manuální build

```bash
mkdir build
cd build
cmake ..
make
./MinimalCpp
```

### Debug build

```bash
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
./MinimalCpp
```

## Struktura projektu

```
MinimalCpp/
├── main.cpp          # Hlavní zdrojový soubor s ukázkami
├── CMakeLists.txt    # CMake konfigurace
├── compile.sh        # Build script
└── README.md         # Tento soubor
```

## Přizpůsobení

1. Přejmenujte projekt v `CMakeLists.txt`
2. Přidejte další `.cpp` soubory do `add_executable()`
3. Pro knihovny přidejte `target_link_libraries()`
4. Pro externí závislosti použijte `find_package()`

## Užitečné příkazy

```bash
# Clean build
rm -rf build

# Rebuild
./compile.sh

# Instalace
cd build
sudo make install
```

## Rozšíření

### Přidání více souborů

V `CMakeLists.txt`:
```cmake
add_executable(MinimalCpp 
    main.cpp
    utils.cpp
    another_file.cpp
)
```

### Přidání knihovny

```cmake
find_package(SomeLibrary REQUIRED)
target_link_libraries(MinimalCpp SomeLibrary::SomeLibrary)
```

## Licence

Upravte dle potřeby.
