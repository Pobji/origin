#include <iostream>
#include <fstream>

struct adress
{
	std::string city;
	std::string street;
	int house_num;
	int apartment_num;
	int postal_code;
};

void adress_list_update()
{
	adress new_adress;
	std::ofstream fout("adress.txt");
	std::cout << "Enter a city:\n";
	std::cin >> new_adress.city;
	std::cout << "Enter a street:\n";
	std::cin >> new_adress.street;
	std::cout << "Enter a house number:\n";
	std::cin >> new_adress.house_num;
	std::cout << "Enter an apartment number:\n";
	std::cin >> new_adress.apartment_num;
	std::cout << "Enter postal code:\n";
	std::cin >> new_adress.postal_code;
	fout << new_adress.city << " ";
	fout << new_adress.street << " ";
	fout << new_adress.house_num << " ";
	fout << new_adress.apartment_num << " ";
	fout << new_adress.postal_code << std::endl;
	fout.close();
}

void saved_adresses()
{
	std::ifstream fin("adress.txt");
	if (fin.is_open())
	{
		adress show;
		fin >> show.city;
		fin >> show.street;
		fin >> show.house_num;
		fin >> show.apartment_num;
		fin >> show.postal_code;
		fin.close();
		std::cout << show.city << " " << show.street << " " << show.house_num << " " << show.apartment_num << " " << show.postal_code << std::endl;
	}
	else std::cout << "There is no saved adress, try to enter one!\n";
}

int main()
{
	for (;;)
	{
		std::cout << "Press 1 to enter new adress or 2 to display previously entered adress or anything else to exit:\n";
		std::cout << "Enter your desired number.:\n";
		int num;
		std::cin >> num;
		if (num == 1) adress_list_update();
		else if (num == 2) saved_adresses();
		else
		{
			std::cout << "Bye, have a wonderful time!";
			break;
		}
	}
}