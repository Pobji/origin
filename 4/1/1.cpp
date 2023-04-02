#include <iostream>
#include <fstream>

class adress
{
private:
	std::string city;
	std::string street;
	std::string house_num;
	std::string apartment_num;
public:
	void set_adress(std::string city, std::string street, std::string house_num, std::string apartment_num)
	{
		this->city = city;
		this->street = street;
		this->house_num = house_num;
		this->apartment_num = apartment_num;
	}
	std::string new_format()
	{
		return city + ", " + street + ", " + house_num + ", " + apartment_num;
	}
};

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
			std::string city, street, house_num, apartment_num;
			fin >> city;
			fin >> street;
			fin >> house_num;
			fin >> apartment_num;
			list[i].set_adress(city, street, house_num, apartment_num);
			fout << list[i].new_format() << std::endl;
		}
		fout.close();
		delete[] list;
		fin.close();
	}
	else std::cout << "There is no list of adresses, try to create one!";
}