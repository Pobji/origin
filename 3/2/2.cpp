#include <iostream>

class Counter
{
private:
	int count;
public:
	Counter(int count) { this->count = count; }
	Counter() { count = 1; }
	void inc() { count++; }
	void dec() { count--; }
	int show() { return count; }
};

void counter_init(Counter& p)
{
	for (;;)
	{
		std::cout << "Enter your command ('+', '-', '=' or 'x'): ";
		char symb;
		std::cin >> symb;
		if (symb == '+') p.inc();
		if (symb == '-') p.dec();
		if (symb == '=') std::cout << p.show() << std::endl;
		if (symb == 'x') break;
	}
}

int main()
{
	for (;;)
	{
		std::cout << "Do you want to set starting value for counter? (y or n): ";
		std::string choice;
		std::cin >> choice;
		if (choice == "y")
		{
			std::cout << "Enter starting value: ";
			int k = 0;
			std::cin >> k;
			Counter num(k);
			counter_init(num);
			break;
		}
		else if (choice == "n")
		{
			Counter num;
			counter_init(num);
			break;
		}
		else std::cout << "Wrong answer, try again!\n";
	}
}