/*Вариант 4.4 Вербицкий Владислав
* 2.    Ввести последовательность натуральных чисел{ Aj }j = 1...n(n <= 1000).
* Упорядочить последовательность понеубыванию первой цифры числа,
*числа с одинаковыми первыми цифрами дополнительно упорядочить по неубыванию наименьшей цифры числа,
* числа с одинаковыми первыми цифрами и одинаковыми наименьшими цифрами дополнительно упорядочить по неубыванию самого числа.*/


#include <iostream>
#include <string>
using namespace std;

void sort_f_n(int arr[], int n) { // Сортировка по неубыванию первой цифры числа.
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (to_string(arr[j])[0] < to_string(arr[i])[0]) { // Проверяем первые цифры чисел, если следующая меньше первой, то меняем их местами.
                swap(arr[i], arr[j]);
            }
        }
    }
}
int min_num(int a) { // Возвращает наименьшее цифру числа.
    string s = to_string(a);
    int min = INT_MAX;
    for (int i = 0; i < s.length(); i++) {// Сравниваем все элементы строки s с большим числом и когда он меньше заменяем
        if (s[i] < min) {
            min = s[i];
        }
    }
    return min;
}


void s_m_n(int arr[], int n) { // Сортировка по неубыванию наименьших цифр чисел.
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (to_string(arr[i])[0] == to_string(arr[j])[0]) { // Т.е если у чисел первые цифры равны, то сортируем их по неубыванию наименьшей цифры числа.
                if (min_num(arr[j]) < min_num(arr[i])) {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
}

void Sort(int arr[], int n) { // Сортировка по неубыванию самих чисел.
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((to_string(arr[i])[0] == to_string(arr[j])[0]) && (min_num(arr[i]) == min_num(arr[j]))) {// первые цифры сторки и минимальные цифры числа и если они равны и стоят не по возрастанию сортируем
                if (arr[j] < arr[i]) {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
}



int main() {
    setlocale(LC_ALL, "Russian");
    int n; // Зададим массив пользовательской длинны.
    int x; // Переменная отвпечающая за пользовательские значения
    cout << "Введите длину ";
    cin >> n;
    int *arr=new int [n];// массив пользовательской длины
    cout << '\n';


    for (int i = 0; i < n; i++) { // Заполним массив пользовательскими значениями.
        cout << "Введите значение " << endl;
        cin >> x;
        arr[i] = x;
        cout << '\n';
    }


   sort_f_n(arr, n);
   s_m_n(arr, n);
   Sort(arr, n);




    for (int q = 0; q < n; q++) { // после выполнения сортировок взглянем на масссив
        cout << arr[q] << " ";
    }
}
