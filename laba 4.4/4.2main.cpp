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

void Sort_TheFirstNumbers(int arr[], int n) { // Ñîðòèðîâêà ïî íåóáûâàíèþ ïåðâîé öèôðû ÷èñëà.
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (to_string(arr[j])[0] < to_string(arr[i])[0]) { // Ïðîâåðÿåì ïåðâûå öèôðû ÷èñåë, åñëè ñëåäóþùàÿ ìåíüøå ïåðâîé, òî ìåíÿåì èõ ìåñòàìè.
                swap(arr[i], arr[j]);
            }
        }
    }
}
int MinimalNumber(int a) { // Âîçâðàùàåò íàèìåíüøåå öèôðó ÷èñëà.
    string s = to_string(a);
    int min = INT_MAX;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < min) {
            min = s[i];
        }
    }
    return min;
}


void Sort_TheMinimalNumbers(int arr[], int n) { // Ñîðòèðîâêà ïî íåóáûâàíèþ íàèìåíüøèõ öèôð ÷èñåë.
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (to_string(arr[i])[0] == to_string(arr[j])[0]) { // Ò.å åñëè ó ÷èñåë ïåðâûå öèôðû ðàâíû, òî ñîðòèðóåì èõ ïî íåóáûâàíèþ íàèìåíüøåé öèôðû ÷èñëà.
                if (MinimalNumber(arr[j]) < MinimalNumber(arr[i])) {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
}

void SwapSort(int arr[], int n) { // Ñîðòèðîâêà ïî íåóáûâàíèþ ñàìèõ ÷èñåë.
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
    int n; // Îáúÿëÿþ äëèííó ìàññèâà.
    int x; // Îáúÿâëÿþ ïåðåìåííóþ äëÿ òîãî, ÷òîáû çàïîëíèòü ìàññèâ ïîëüçîâàòåëüñêèìè çíà÷åíèÿìè.
    cout << "Enter the length: ";
    cin >> n;
    int arr[n];
    cout << '\n';


    for (int i = 0; i < n; i++) { // Çàïîëíÿþ ìàññèâ ïîëüçîâàòåëüñêèìè çíà÷åíèÿìè.
        cout << "Enter the value of the index " << i << endl;
        cin >> x;
        arr[i] = x;
        cout << '\n';
    }


    Sort_TheFirstNumbers(arr, n);
    Sort_TheMinimalNumbers(arr, n);
    SwapSort(arr, n);




    for (int k = 0; k < n; k++) { // Âûâîæó ïîëó÷èâøèéñÿ ñïèñîê.
        cout << arr[k] << " ";
    }
}
