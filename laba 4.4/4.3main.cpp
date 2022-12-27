/* Лабораторная номер 4. Вариант 4. Пункт 3. Вербицкий Владислав
 *
 * 3.	3.	Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100).
 * Найти строку с наименьшей суммой элементов и заменить все элементы этой строки этой суммой. */


#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>

int main() {
    int row, col;
    int current_number; // Переменная для заполнения матрицы.
    int min_sum = INT_MAX;// Переменные для того, чтобы найти минимальную сумму элементов строки:
    int current_sum = 0;
    int current_i = -1;

    cout << "Enter a number of rows: " << endl;
    cin >> row; // Пользователь вводит количество строк
    cout << "Enter a number of columns: " << endl;
    cin >> col; // Пользователь вводит количество столбцов

    int arr[row][col]; // Создаём матрицу пользовательского размера

    for (int i = 0; i < row; i++) { // Заполняем матрицу
        for (int j = 0; j < col; j++) {
            cout << "Enter the value: " << endl;
            cin >> current_number;
            arr[i][j] = current_number;
        }
    }
    for (int i = 0; i < row; i++) { // Находим минимальную сумму элементов строки.
        for (int j = 0; j < col; j++) {
            current_sum += arr[i][j];
        }
        if (current_sum < min_sum) {
            min_sum = current_sum;
            current_i = i; // А так же запоминаем номер самой строки, в которой сумма элементов самая маленькая.
        }
        current_sum = 0;
    }

    for (int j = 0; j < col; j++) { // Меняем все значения найденной строки на сумму её элементов.
        arr[current_i][j] = min_sum;
    }


    for (int i = 0; i < row; i++) { // Выводим матрицу в консоль
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
            if (j == (col - 1)) {
                cout << '\n';
            }

        }
    }



}

