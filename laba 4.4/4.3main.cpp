/* ������������ ����� 4. ������� 4. ����� 3. ��������� ���������
 *
 * 3.	3.	���� ������������� ������� {Aij}i=1..n,j=1..m (n,m<=100).
 * ����� ������ � ���������� ������ ��������� � �������� ��� �������� ���� ������ ���� ������. */


#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>

int main() {
    int row, col;
    int current_number; // ���������� ��� ���������� �������.
    int min_sum = INT_MAX;// ���������� ��� ����, ����� ����� ����������� ����� ��������� ������:
    int current_sum = 0;
    int current_i = -1;

    cout << "Enter a number of rows: " << endl;
    cin >> row; // ������������ ������ ���������� �����
    cout << "Enter a number of columns: " << endl;
    cin >> col; // ������������ ������ ���������� ��������

    int arr[row][col]; // ������ ������� ����������������� �������

    for (int i = 0; i < row; i++) { // ��������� �������
        for (int j = 0; j < col; j++) {
            cout << "Enter the value: " << endl;
            cin >> current_number;
            arr[i][j] = current_number;
        }
    }
    for (int i = 0; i < row; i++) { // ������� ����������� ����� ��������� ������.
        for (int j = 0; j < col; j++) {
            current_sum += arr[i][j];
        }
        if (current_sum < min_sum) {
            min_sum = current_sum;
            current_i = i; // � ��� �� ���������� ����� ����� ������, � ������� ����� ��������� ����� ���������.
        }
        current_sum = 0;
    }

    for (int j = 0; j < col; j++) { // ������ ��� �������� ��������� ������ �� ����� � ���������.
        arr[current_i][j] = min_sum;
    }


    for (int i = 0; i < row; i++) { // ������� ������� � �������
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
            if (j == (col - 1)) {
                cout << '\n';
            }

        }
    }



}

