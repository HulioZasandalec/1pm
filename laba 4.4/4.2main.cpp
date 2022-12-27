/* ������������ ����� 4. ������� 4. ����� 2. ��������� ���������
 *
 * 2.    ������ ������������������ ����������� ����� {Aj}j=1...n (n<=1000).
 * ����������� ������������������ ������������ ������ ����� �����,
 * ����� � ����������� ������� ������� ������������� ����������� �� ���������� ���������� ����� �����,
 * ����� � ����������� ������� ������� � ����������� ����������� ������� ������������� ����������� �� ���������� ������ �����. */


#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::swap;
using std::to_string;
using std::string;
#include <string>

void Sort_TheFirstNumbers(int arr[], int n) { // ���������� �� ���������� ������ ����� �����.
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (to_string(arr[j])[0] < to_string(arr[i])[0]) { // ��������� ������ ����� �����, ���� ��������� ������ ������, �� ������ �� �������.
                swap(arr[i], arr[j]);
            }
        }
    }
}
int MinimalNumber(int a) { // ���������� ���������� ����� �����.
    string s = to_string(a);
    int min = INT_MAX;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < min) {
            min = s[i];
        }
    }
    return min;
}


void Sort_TheMinimalNumbers(int arr[], int n) { // ���������� �� ���������� ���������� ���� �����.
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (to_string(arr[i])[0] == to_string(arr[j])[0]) { // �.� ���� � ����� ������ ����� �����, �� ��������� �� �� ���������� ���������� ����� �����.
                if (MinimalNumber(arr[j]) < MinimalNumber(arr[i])) {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
}

void SwapSort(int arr[], int n) { // ���������� �� ���������� ����� �����.
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
    int n; // ������� ������ �������.
    int x; // �������� ���������� ��� ����, ����� ��������� ������ ����������������� ����������.
    cout << "Enter the length: ";
    cin >> n;
    int arr[n];
    cout << '\n';


    for (int i = 0; i < n; i++) { // �������� ������ ����������������� ����������.
        cout << "Enter the value of the index " << i << endl;
        cin >> x;
        arr[i] = x;
        cout << '\n';
    }


    Sort_TheFirstNumbers(arr, n);
    Sort_TheMinimalNumbers(arr, n);
    SwapSort(arr, n);




    for (int k = 0; k < n; k++) { // ������ ������������ ������.
        cout << arr[k] << " ";
    }
}