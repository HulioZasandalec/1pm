#include <iostream>
#include <string>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

// класс, который может складывать и умножать большие числа
class BigInteger {
private:
	std::string m_number;

	BigInteger() {}

	std::string add(std::string left, std::string right) {
		int length = MAX(left.size(), right.size());
		int carry = 0;
		int sumCol;
		std::string result;

		while (left.size() < length) {
			left.insert(0, "0");
		}

		while (right.size() < length) {
			right.insert(0, "0");
		}

		for (int i = length - 1; i >= 0; i--) {
			sumCol = (left[i] - '0') + (right[i] - '0') + carry;
			carry = sumCol / 10;
			result.insert(0, std::to_string(sumCol % 10));
		}

		if (carry) {
			result.insert(0, std::to_string(carry));
		}

		return result.erase(0, std::min(result.find_first_not_of('0'), result.size() - 1));
	}

	std::string subtract(std::string left, std::string right) {
		int length = MAX(left.size(), right.size());
		int diff;
		std::string result;

		while (left.size() < length) {
			left.insert(0, "0");
		}

		while (right.size() < length) {
			right.insert(0, "0");
		}

		for (int i = length - 1; i >= 0; i--) {
			diff = (left[i] - '0') - (right[i] - '0');
			if (diff >= 0) {
				result.insert(0, std::to_string(diff));
			}
			else {
				int j = i - 1;
				while (j >= 0) {
					left[j] = ((left[j] - '0') - 1) % 10 + '0';
					if (left[j] != '9') {
						break;
					}
					else {
						j--;
					}
				}
				result.insert(0, std::to_string(diff + 10));
			}
		}

		return result.erase(0, std::min(result.find_first_not_of('0'), result.size() - 1));
	}

	std::string multiply(std::string left, std::string right) {
		int length = MAX(left.size(), right.size());

		if (length == 1) {
			return std::to_string((left[0] - '0') * (right[0] - '0'));
		}

		while (left.size() < length) {
			left.insert(0, "0");
		}

		while (right.size() < length) {
			right.insert(0, "0");
		}

		std::string left0 = left.substr(0, length / 2);
		std::string left1 = left.substr(length / 2, length - length / 2);
		std::string right0 = right.substr(0, length / 2);
		std::string right1 = right.substr(length / 2, length - length / 2);

		std::string p0 = multiply(left0, right0);
		std::string p1 = multiply(left1, right1);
		std::string p2 = multiply(add(left0, left1), add(right0, right1));
		std::string p3 = subtract(p2, add(p0, p1));

		for (int i = 0; i < 2 * (length - length / 2); i++) {
			p0.append("0");
		}

		for (int i = 0; i < length - length / 2; i++) {
			p3.append("0");
		}

		std::string result = add(add(p0, p1), p3);

		return result.erase(0, std::min(result.find_first_not_of('0'), result.size() - 1));
	}
public:
	BigInteger(std::string number) {
		if (number.size() == 0) {
			throw std::runtime_error("string should not be empty");
		}

		for (size_t i = 0; i < number.size(); i++) {
			char digit = number[i] - '0';
			if (!(digit >= 0 && digit <= 9)) {
				throw std::runtime_error("string should contain only digits");
			}
		}

		m_number = number;
	}

	std::string number() {
		return m_number;
	}

	BigInteger operator + (const BigInteger& b) {
		BigInteger bi;
		bi.m_number = add(m_number, b.m_number);
		return bi;
	}

	BigInteger operator * (const BigInteger& b) {
		BigInteger bi;
		bi.m_number = multiply(m_number, b.m_number);
		return bi;
	}
};

int main() {
	std::string s1;
	std::string s2;

	while (true) {
		std::cin >> s1;

		if (s1 == "exit") {
			break;
		}

		std::cin >> s2;

		BigInteger a(s1);
		BigInteger b(s2);

		std::cout << (a * b).number() << std::endl << std::endl;
	}

	return 0;
}