/* Лабораторная номер 4. Вариант 4. Пункт 2. Вербицкий Владислав
 *
 * 2.    Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000).
 * Упорядочить последовательность понеубыванию первой цифры числа,
 * числа с одинаковыми первыми цифрами дополнительно упорядочить по неубыванию наименьшей цифры числа,
 * числа с одинаковыми первыми цифрами и одинаковыми наименьшими цифрами дополнительно упорядочить по неубыванию самого числа. */


#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::swap;
using std::to_string;
using std::string;
#include <string>

void Sort_TheFirstNumbers(int arr[], int n) { // Сортировка по неубыванию первой цифры числа.
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (to_string(arr[j])[0] < to_string(arr[i])[0]) { // Проверяем первые цифры чисел, если следующая меньше первой, то меняем их местами.
                swap(arr[i], arr[j]);
            }
        }
    }
}
int MinimalNumber(int a) { // Возвращает наименьшее цифру числа.
    string s = to_string(a);
    int min = INT_MAX;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < min) {
            min = s[i];
        }
    }
    return min;
}


void Sort_TheMinimalNumbers(int arr[], int n) { // Сортировка по неубыванию наименьших цифр чисел.
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (to_string(arr[i])[0] == to_string(arr[j])[0]) { // Т.е если у чисел первые цифры равны, то сортируем их по неубыванию наименьшей цифры числа.
                if (MinimalNumber(arr[j]) < MinimalNumber(arr[i])) {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
}

void SwapSort(int arr[], int n) { // Сортировка по неубыванию самих чисел.
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((to_string(arr[i])[0] == to_string(arr[j])[0]) && (MinimalNumber(arr[i]) == MinimalNumber(arr[j]))) {
                if (arr[j] < arr[i]) {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
}



int main() {
    int n; // Объяляю длинну массива.
    int x; // Объявляю переменную для того, чтобы заполнить массив пользовательскими значениями.
    cout << "Enter the length: ";
    cin >> n;
    int arr[n];
    cout << '\n';


    for (int i = 0; i < n; i++) { // Заполняю массив пользовательскими значениями.
        cout << "Enter the value of the index " << i << endl;
        cin >> x;
        arr[i] = x;
        cout << '\n';
    }


    Sort_TheFirstNumbers(arr, n);
    Sort_TheMinimalNumbers(arr, n);
    SwapSort(arr, n);




    for (int k = 0; k < n; k++) { // Вывожу получившийся список.
        cout << arr[k] << " ";
    }
}