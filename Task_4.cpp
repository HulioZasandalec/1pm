/*
Задача учебной практики 4. Вариант 4.
Как известно, минимальный размер памяти, который мы можем прочитать, составляет 1 байт. Но иногда встречаются задачи, когда данные не такие большие, и даже 1 байта для них может быть много. Придумайте механизм упаковки нескольких значений в 1 байт.
Такой подход позволяет уменьшить размер используемой памяти и может быть полезен, например, при передаче данных по радиосвязи.
Порядок выполнения:
1.	Определите минимальное количество бит на число. Если получается так, что в 1 байт вы можете записать 2.5 числа, например, то задействуйте 2 байта.
2.	Разработайте операции добавления и извлечения чисел.
Целые числа от 0 до 3.
*/

#include <iostream>

// класс, который может хранить в 1 байте 4 значения в диапазоне от 0 до 3 включительно
class Converter {
private:
	// переменная в которую записываются значения
	unsigned char m_value;

	// метод, который устанавливает бит в 1
	void setBit(unsigned char index) {
		m_value |= 1 << index;
	}

	// метод, который устанавливает бит в 0
	void resetBit(unsigned char index) {
		m_value &= ~(1 << index);
	}

	// метод, который возвращает true: если значение в диапазоне от 0 до 3
	bool checkRange(unsigned char value) {
		if (value >= 0 && value <= 3) {
			return true;
		}
		return false;
	}

	// метод, который возвращает индекс бита по индексу значения
	unsigned char getBitIndex(unsigned char index) {
		switch (index) {
		case 1:
			return 2;
		case 2:
			return 4;
		case 3:
			return 6;
		}

		return 0;
	}

public:
	// конструктор, который принимает переменную хранящую все значения, по умолчанию значение 0
	Converter(unsigned char initialValue = 0) : m_value(initialValue) {}

	// метод, который устанавливает значение по индексу
	void setValue(unsigned char value, unsigned char index) {
		if (!checkRange(index)) {
			throw std::runtime_error("index is out of range");
		}
		if (!checkRange(value)) {
			throw std::runtime_error("value is out of range");
		}

		unsigned char bitIndex = getBitIndex(index);

		switch (value) {
		case 0:
			resetBit(bitIndex);
			resetBit(bitIndex + 1);
			break;
		case 1:
			setBit(bitIndex);
			resetBit(bitIndex + 1);
			break;
		case 2:
			resetBit(bitIndex);
			setBit(bitIndex + 1);
			break;
		case 3:
			setBit(bitIndex);
			setBit(bitIndex + 1);
			break;
		}
	}

	// метод, который возвращает значение по индексу
	unsigned char getValue(unsigned char index) {
		if (!checkRange(index)) {
			throw std::runtime_error("index is out of range");
		}

		unsigned char bitIndex = getBitIndex(index);

		unsigned char sign1 = (m_value & (1 << bitIndex));
		unsigned char sign2 = (m_value & (1 << bitIndex + 1));

		if (sign1 == 0 && sign2 == 0) {
			return 0;
		}
		else if (sign1 != 0 && sign2 == 0) {
			return 1;
		}
		else if (sign1 == 0 && sign2 != 0) {
			return 2;
		}
		else if (sign1 != 0 && sign2 != 0) {
			return 3;
		}
	}

	// метод, который возвращает переменную хранящую все значения
	unsigned char getByte() {
		return m_value;
	}
};

int main() {
	Converter converter;

	for (int i = 0; i < 4; i++) {
		converter.setValue(i, i);
	}

	for (int i = 0; i < 4; i++) {
		std::cout << +converter.getValue(i) << std::endl;
	}

	std::cout << std::endl;

	std::cout << +converter.getByte() << std::endl;
}