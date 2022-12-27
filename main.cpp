/*
Лабораторная работа 9. Вариант 4. Вербицкий Владислав
Воспользуйтесь первым принципом ООП, абстракцией, и сформируйте класс, включив в него только минимальный набор переменных(полей) для заданного вашим вариантом объекта.
Используйте второй принцип ООП, инкапсуляцию, чтобы не допустить некорректного ввода параметров.
Добавьте в класс функции(методы), которые позволят решить задачу.Продемонстрируйте решение.
Разбивать класс на файлы можете по желанию.

Найти объём конуса (1,3* s * h) */
#include <iostream>
class Pyramid//класс содержащтй информацию о пирамиде
{
private:
	unsigned int p_visota;// высота
	unsigned int p_radius;// Радиус
	unsigned int p_S;// Площадь основания
public:
	Pyramid(unsigned int visota, unsigned int radius, unsigned int S) :
		p_visota(visota), p_radius(radius), p_S(S) {}


	unsigned int getvisota() {

		return p_visota;
	}
	unsigned int getradius() {

		return p_radius;
	}
	unsigned int getS() {  //плошадь основания
		return p_S;
	}
	unsigned int getV() { //объём
		return (p_S * p_visota)/3 ;
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	Pyramid pyramid(20, 10, 10);
	std::cout << "Высота" << pyramid.getvisota() << std::endl;
	std::cout << "Радиус" << pyramid.getradius() << std::endl;
	std::cout << "Площадь" << pyramid.getS() << std::endl;
	std::cout << "Объём" << pyramid.getV() << std::endl;
}




