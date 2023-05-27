#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <chrono>
#include <random>

// Функция генерации случайного числа в заданном диапазоне
int generateRandomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}

// Функция заполнения вектора случайными элементами
void fillContainer(std::vector<int>& collection, int size, int min, int max) {
    for (int i = 0; i < size; ++i) {
        collection.push_back(generateRandomNumber(min, max));
    }
}

// Функция заполнения списка случайными элементами
void fillContainer(std::list<int>& collection, int size, int min, int max) {
    for (int i = 0; i < size; ++i) {
        collection.push_back(generateRandomNumber(min, max));
    }
}

// Функция заполнения мультимножества случайными элементами
void fillContainer(std::multiset<int>& collection, int size, int min, int max) {
    for (int i = 0; i < size; ++i) {
        collection.insert(generateRandomNumber(min, max));
    }
}

// Функция заполнения карты случайными элементами
void fillContainer(std::map<int, int>& collection, int size, int min, int max) {
for (int i = 0; i < size; ++i) {
int key = i; // В качестве ключа используем значение i
int value = generateRandomNumber(min, max);
collection[key] = value;
}
}

// Функция для вывода содержимого контейнера
template <typename Container>
void printContainer(const Container& collection) {
    for (const int& item : collection) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int size = 1000000; // Размер коллекции
    const int minValue = 1; // Минимальное значение элемента
    const int maxValue = 100; // Максимальное значение элемента

    std::vector<int> vec;
    fillContainer(vec, size, minValue, maxValue);

    std::list<int> lst;
    fillContainer(lst, size, minValue, maxValue);

    std::multiset<int> mset;
    fillContainer(mset, size, minValue, maxValue);

    std::map<int, int> mp;
    fillContainer(mp, size, minValue, maxValue);

    int elementToCount = 42;

    auto start = std::chrono::high_resolution_clock::now();
    int vecCount = std::count(vec.begin(), vec.end(), elementToCount);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> vecTime = end - start;

    start = std::chrono::high_resolution_clock::now();
    int lstCount = std::count(lst.begin(), lst.end(), elementToCount);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> lstTime = end - start;

    start = std::chrono::high_resolution_clock::now();
    int msetCount = mset.count(elementToCount);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> msetTime = end - start;

    start = std::chrono::high_resolution_clock::now();
    int mpCount = std::count_if(mp.begin(), mp.end(), [&](const std::pair<const int, int>& pair) { return pair.second == elementToCount; });
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> mpTime = end - start;

    std::cout << "Vector count: " << vecCount << ", Time: " << vecTime.count() << "s" << std::endl;
    std::cout << "List count: " << lstCount << ", Time: " << lstTime.count() << "s" << std::endl;
    std::cout << "Multiset count: " << msetCount << ", Time: " << msetTime.count() << "s" << std::endl;
    std::cout << "Map count: " << mpCount << ", Time: " << mpTime.count() << "s" << std::endl;

    return 0;
}
