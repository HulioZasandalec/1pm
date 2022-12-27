#include <iostream> 
using namespace std;
/*Дана последовательность натуральных чисел {aj}j=1...n (n<=10000). Вербицкий Владислав
Если в последовательности нет ни одного простого числа, упорядочить последовательность по невозрастанию.)*/


int main()
{




	int n;
	int a;
	int b;
	int x;
	int y;

	int min_j = 9;

	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> b;
		arr[i] = b;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] % 100 > arr[j + 1] % 100) {

				swap(arr[j], arr[j + 1]);
			}


		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {


			x = arr[j];
			y = arr[j + 1];
			if (x % 100 == y % 100) {

				while (x != 0)
				{

					a = x % 10;
					cout << a << "";
					x = x / 10;


				}
			}





		}
	}for (int i = 0; i < n - 1; i++)
		std::cout << arr[i];
}






