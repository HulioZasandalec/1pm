/*
Задача учебной практики 6
Изучите основные операции над вектором и продемонстрируйте их работу:
1.	push_back, erase, insert
2.	emplace_back
3.	resize, reserve, shrink_to_fit, capacity
4.	clear
5.	оператор присваивания и []
Узнайте размер вектора и будьте готовы объяснить, почему именно так.
*/

#include <iostream>
#include <vector>

#define PRINT(s) std::cout << s << std::endl

int main() {
    // память под вектор выделяется в стеке но вектор хранит свои элементы хипе
    std::vector<int> vector;

    // метод reserve изменяет вместимость массива
    vector.reserve(16);

    // метод resize изменяет количество элементов
    vector.resize(5);

    // метод capacity возвращает вместимость массива
    PRINT("capacity: " << vector.capacity());

    // метод push_back добавляет элемент в конец
    for (size_t i = 2; i <= 5; i++) {
        vector.push_back(i);
    }

    // метод insert добавляет элемент на определенную позицию,
    // все следующие элементы перемещаются вперед на одну позицию
    vector.insert(vector.begin() + 5, 1);

    // используем метод erase чтобы удалить диапазон элементов
    vector.erase(vector.begin(), vector.begin() + 5);

    // обходим все элементы
    for (size_t i = 0; i < vector.size(); i++) {
        // используем оператор [] чтобы получить элемент по индексу i
        std::cout << vector[i] << std::endl;

        // используем оператор присваивания чтобы изменить значение по индексу i
        vector[i] = -1;
    }

    // метод shrink_to_fit изменяет вместимость под количество элементов
    vector.shrink_to_fit();

    // выводим capacity после вызова метода shrink_to_fit
    PRINT("capacity: " << vector.capacity());

    // метод clear удаляет все элементы
    vector.clear();

    // метод emplace_back делает тоже самое что и push_back,
    // только в отличии от push_back, который добавляет копию объекта
    // emplace_back создает объект непосредственно в конце вектора, без лишнего копирования 
    vector.emplace_back(1);

    // после удаления элементов, при попытке получить элемент получим исключение
    // PRINT(vector[0]);
}