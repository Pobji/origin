#include <iostream>
#include <fstream>

struct bank_account
{
	int account;
	std::string name;
	double deposit;
};

void account_change_sum(bank_account& diff, double new_sum)
{
	std::ofstream fout("Account.txt");
	fout << diff.account << " ";
	fout << diff.name << " ";
	fout << new_sum;
	fout.close();
}

void get_account_data(bank_account& base)
{
	std::ifstream fin("Account.txt");
	if (fin.is_open())
	{
		bank_account person;
		fin >> base.account;
		fin >> base.name;
		fin >> base.deposit;
		fin.close();
	}
	else std::cout << "There is no information about your bank account, probably you don't have one!\n";
}

int main()
{
	bank_account person;
	get_account_data(person);
	std::cout << "If you want to change your deposit numbers please, enter your account information\n";
	std::cout << "Enter your account number:\n";
	int account;
	std::cin >> account;
	if (person.account == account)
	{
		std::cout << "Enter deposit holder name:\n";
		std::string name;
		std::cin >> name;
		if (person.name == name)
		{
			std::cout << "Enter deposit sum:\n";
			float deposit;
			std::cin >> deposit;
			if (person.deposit == deposit)
			{
				std::cout << "Enter new deposit:\n";
				std::cin >> deposit;
				account_change_sum(person, deposit);
			}
			else std::cout << "Entered deposit sum is incorrect!\n";
		}
		else std::cout << "Entered holder name is incorrect!\n";
	}
	else std::cout << "Entered account number is incorrect!\n";
	get_account_data(person);
	std::cout << person.account << " " << person.name << " " << person.deposit;
}
