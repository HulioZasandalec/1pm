// 6_task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec;
	vec.push_back(3); //Добавляет в КОНЕЦ вектора новый элемент
	vec.push_back(5);
	for (int i = 0; i < vec.size(); i++)// изначально элементов не было и они добавляются друг за другом
	{
		cout << vec[i] << ' ';
	}
	vec.clear();
	cout << '\n' << vec.size(); // вектор очищен


	vec.reserve(9);//указываем количетво ячеек

	vec.insert(vec.begin(), 1);  // добавили элемент в начало
	vec.insert(vec.end(), 4);  // добавили элемент в конец

	vector<int> numbers1 = { 1, 2, 3, 4, 5 };
	numbers1.emplace_back(8);   // numbers1 = { 1, 2, 3, 4, 5, 8 }; функция добавляет элемент в конец контейнера


	std::vector<int> numbers1 = { 1, 2, 3, 4, 5, 6 };//resize изменяет размер вектора
	numbers1.resize(4); // оставляем первые четыре элемента - numbers1 = {1, 2, 3, 4}

	// используем метод erase чтобы удалить диапазон элементов
	vec.erase(vec.begin(), vec.begin() + 5);


	// метод shrink_to_fit изменяет вместимость под количество элементов
	vec.shrink_to_fit();

	//Метод capacity() возвращает количество элементов, выделенное для массива.

	// обходим все элементы
	vector<int>vector;
	for ( int c = 0; c < vector.size(); c++) {
		// используем оператор [] чтобы получить элемент по индексу i
		std::cout << vector[i] << std::endl;

		// используем оператор присваивания чтобы изменить значение по индексу i
		vector[i] = -1;
	

	
}
	
	
	

	
	



		

	
