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
    int current_number; // Ïåðåìåííàÿ äëÿ çàïîëíåíèÿ ìàòðèöû.
    int min_sum = INT_MAX;// Ïåðåìåííûå äëÿ òîãî, ÷òîáû íàéòè ìèíèìàëüíóþ ñóììó ýëåìåíòîâ ñòðîêè:
    int current_sum = 0;
    int current_i = -1;

    cout << "Enter a number of rows: " << endl;
    cin >> row; // Ïîëüçîâàòåëü ââîäèò êîëè÷åñòâî ñòðîê
    cout << "Enter a number of columns: " << endl;
    cin >> col; // Ïîëüçîâàòåëü ââîäèò êîëè÷åñòâî ñòîëáöîâ

    int arr[row][col]; // Ñîçäà¸ì ìàòðèöó ïîëüçîâàòåëüñêîãî ðàçìåðà

    for (int i = 0; i < row; i++) { // Çàïîëíÿåì ìàòðèöó
        for (int j = 0; j < col; j++) {
            cout << "Enter the value: " << endl;
            cin >> current_number;
            arr[i][j] = current_number;
        }
    }
    for (int i = 0; i < row; i++) { // Íàõîäèì ìèíèìàëüíóþ ñóììó ýëåìåíòîâ ñòðîêè.
        for (int j = 0; j < col; j++) {
            current_sum += arr[i][j];
        }
        if (current_sum < min_sum) {
            min_sum = current_sum;
            current_i = i; // À òàê æå çàïîìèíàåì íîìåð ñàìîé ñòðîêè, â êîòîðîé ñóììà ýëåìåíòîâ ñàìàÿ ìàëåíüêàÿ.
        }
        current_sum = 0;
    }

    for (int j = 0; j < col; j++) { // Ìåíÿåì âñå çíà÷åíèÿ íàéäåííîé ñòðîêè íà ñóììó å¸ ýëåìåíòîâ.
        arr[current_i][j] = min_sum;
    }


    for (int i = 0; i < row; i++) { // Âûâîäèì ìàòðèöó â êîíñîëü
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
            if (j == (col - 1)) {
                cout << '\n';
            }

        }
    }



}

