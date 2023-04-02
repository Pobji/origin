#include <iostream>

class Calculator
{
public:
	double num1;
	double num2;

	double add()
	{
		return num1 + num2;
	}
	double multiply()
	{
		return num1 * num2;
	}
	double substract_1_2()
	{
		return num1 - num2;
	}
	double substract_2_1()
	{
		return num2 - num1;
	}
	double divide_1_2()
	{
		return num1 / num2;
	}
	double divide_2_1()
	{
		return num2 / num1;
	}
	bool set_num1(double num1)
	{
		if (num1 != 0)
		{
			this->num1 = num1;
			return true;
		}
		else return false;
	}
	bool set_num2(double num2)
	{
		if (num2 != 0)
		{
			this->num2 = num2;
			return true;
		}
		else return false;
	}

};

int main()
{
	Calculator calc;
	for (;;)
	{
		for (;;)
		{
			std::cout << "Enter first number: ";
			double num;
			std::cin >> num;
			if (calc.set_num1(num) == true) break;
			else std::cout << "Incorrect! Number cannot be zero! Try again.\n";
		}
		for (;;)
		{
			std::cout << "Enter second number: ";
			double num;
			std::cin >> num;
			if (calc.set_num2(num) == true) break;
			else std::cout << "Incorrect! Number cannot be zero! Try again.\n";
		}
		std::cout << "num1 + num2 = " << calc.add() << std::endl;
		std::cout << "num1 - num2 = " << calc.substract_1_2() << std::endl;
		std::cout << "num2 - num1 = " << calc.substract_2_1() << std::endl;
		std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
		std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
		std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;
	}
}
