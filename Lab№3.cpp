/*Лаба №3. Вербицкий Владислав.
Задание на использования оператова "switch"*/
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int N;
	cin >> N;

	switch (N)
	{
	case 0: cout << "Все хорошо";
		break;
	case 1: cout << "Ошибка в чтении файла";
		break;
	case 2: cout << "Ошибка в записи файла";
		break;
	case 3: cout << "Не все поля определены";
		break;
	default: cout << "неверный ввод";
	}











}






















}
