/*Дана последовательность на* Лабораторная номер 4. Вариант 4. Пункт 1. Вербицкий Владислав
 *
 * 1.	Дана последовательность натуральных чисел {aj}j=1...n (n<=10000).
 * Если в последовательности нет ни одного простого числа,
 * упорядочить последовательность по невозрастанию. */


#include <iostream>

using namespace std;

bool is_Prime(int n) { // Функция, чтобы узнать, простое ли число.

    int d = 2;
    while (d * d <= n) {
        if (n % d == 0) {
            return false;
        }
        d++;
    }
    return true;
}
void Sort(int arr[], int n) { // Функция сортировки по невозрастанию.
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {

                swap(arr[j], arr[j + 1]);
               
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian"); //подключим русский язык
    int n; // Установим пользовательскую длину массива
    int x; // Переменная для заполнения динамического масства пользовательской длинны n
    cout << "Введите длину массива ";
    cin >> n;
    cout << '\n';
    int *arr= new int[n];
    for (int i = 0; i < n; i++) { // Заполняю массив пользовательскими значениями.
        cout << "Введите значения " << endl;
        cin >> x;
        arr[i] = x;
        cout << '\n';
    }

    bool simple = true; // По умолчанию  устанвоим что простых чисел нет

    for (int i = 0; i < n; i++) { // Пробегаемся по массиву.

        if (is_Prime(arr[i])) {
           simple = false; // При нахождении хотя бы одного простого числа устанавливаем false
        }
        if  (simple == true) {//Если условия выполнены и нет ни одного простого числа выводим отсортированные числа

            Sort(arr, n);
        }
    }
    for (int k = 0; k < n; k++) { // При условии true он отсортируется а при false то останется таким какой был введен пользователем
        cout << arr[k] << " ";
    }
}



