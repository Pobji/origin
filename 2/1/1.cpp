#include <iostream>

enum class monthes
{
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December,
};

int main()
{
	for (;;)
	{
		std::cout << "Please, enter month number: \n";
		int month_num = 0;
		std::cin >> month_num;
		if ((month_num > 0) && (month_num < 13))
		{
			monthes month = static_cast<monthes>(month_num);
			switch (month)
			{
			case monthes::January:
				std::cout << "January!\n";
				break;
			case monthes::February:
				std::cout << "February!\n";
				break;
			case monthes::March:
				std::cout << "March!\n";
				break;
			case monthes::April:
				std::cout << "April!\n";
				break;
			case monthes::May:
				std::cout << "May!\n";
				break;
			case monthes::June:
				std::cout << "June!\n";
				break;
			case monthes::July:
				std::cout << "July!\n";
				break;
			case monthes::August:
				std::cout << "August!\n";
				break;
			case monthes::September:
				std::cout << "September!\n";
				break;
			case monthes::October:
				std::cout << "October!\n";
				break;
			case monthes::November:
				std::cout << "November!\n";
				break;
			case monthes::December:
				std::cout << "December!\n";
				break;
			}
		}
		else if (month_num == 0)
		{
			std::cout << "Have a nice day!";
			break;
		}
		else std::cout << "Sadly there is only twelve monthes, you should know that! Please enter correctly this time.\n\n";
	}
}