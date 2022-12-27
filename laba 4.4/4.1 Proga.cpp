/*Дана последовательность натуральных чисел {aj}j=1...n (n<=10000). Вербицкий Владислав
Если в последовательности нет ни одного простого числа, упорядочить последовательность по невозрастанию.)*/
#include <iostream>
using namespace std; 
bool is_Prime(int n) { // Функция, чтобы узнать, простое ли число.
	int d = 2;
	while (d * d <= n) {
		if (n % d == 0) {
			return false;//
		}
		d++;
	}
	return true;
}
	
int main()
{

	int n;
	
	int b;
	int num2 = 2;
	cin >> n;
	int* arr = new int[n]; //задаем массив пользовательской длинны с пользовательскими значениями
	for (int i = 0; i < n; i++)
	{
		cin >> b;
		arr[i] = b;
	}
	for (int i = 0; i < n; i++) {






		if (is_Prime(arr[i]))
		{// простых числа есть и мы выводим в том порядке в котором вводили
			for (int i = 0; i < n; i++) {
				cout << arr[i] << " ";
		
			}
		}
		else
		{
			for (int i = 0; i < n - 1; i++) {
				for (int j = 0; j < n - i - 1; j++)
				{
					if (arr[j] <arr[j+1])
					{

						swap(arr[j], arr[j+1]);
					}
				}

			}
			
		}
	
	}
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";





}
	








			

	






