#include <iostream>
#include <fstream>
#include <string>

class adress
{
private:
	std::string city;
	std::string street;
	int house_num;
	int apartment_num;
public:
	void set_adress(std::string city, std::string street, int house_num, int apartment_num)
	{
		this->city = city;
		this->street = street;
		this->house_num = house_num;
		this->apartment_num = apartment_num;
	}
	std::string new_format() { return city + ", " + street + ", " + std::to_string(house_num) + ", " + std::to_string(apartment_num); }
	std::string get_city() { return city; }
	std::string get_street() { return street; }
	int get_house_num() { return house_num; }
	int get_apartment_num() { return apartment_num; }
};

void sort(adress* adresses, int size)
{

		for (int i = 0; i < size; i++)
		{
			for (int j = size-1; j > 0 + i; j--)
			{
				std::string city1 = adresses[j].get_city();
				std::string city2 = adresses[j-1].get_city();
				int l = city1.length();
				if (city1.length() > city2.length()) l = city2.length();
				int coun = 0;
				for (int h = 0; h < l; h++)
				{
					if (static_cast<int>(city1[h]) < static_cast<int>(city2[h]))
					{
						adress temp;
						temp.set_adress(adresses[j].get_city(), adresses[j].get_street(), adresses[j].get_house_num(), adresses[j].get_apartment_num());
						adresses[j].set_adress(adresses[j-1].get_city(), adresses[j-1].get_street(), adresses[j-1].get_house_num(), adresses[j-1].get_apartment_num());
						adresses[j-1].set_adress(temp.get_city(), temp.get_street(), temp.get_house_num(), temp.get_apartment_num());

						break;
					}
					else if (static_cast<int>(city1[h]) > static_cast<int>(city2[h])) break;
				}
			}
		}
}

int main()
{
	std::ifstream fin("in.txt");
	if (fin.is_open())
	{
		std::ofstream fout("out.txt");
		int count = 0;
		fin >> count;
		adress* list = new adress[count];
		for (int i = 0; i < count; i++)
		{
			std::string city, street;
			int house_num, apartment_num;
			fin >> city;
			fin >> street;
			fin >> house_num;
			fin >> apartment_num;
			list[i].set_adress(city, street, house_num, apartment_num);
		}
		fin.close();
		sort(list, count);
		for (int i = 0; i < count; i++)
		{
			fout << list[i].new_format() << std::endl;
		}
		fout.close();
		delete[] list;
	}
	else std::cout << "There is no list of adresses, try to create one!";
}