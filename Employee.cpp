#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include "Employee.h"

using namespace std;

struct Employee {
	string id;
	string firstName;
	string lastName;
	string password;
	bool isManager;
};

int isValidEmployee(string id, string firstName, string lastName, string password, string isManager)
{
	if (id.length() > 9)
		return 1;
	if (firstName.length() > 20)
		return 2;
	if (lastName.length() > 20)
		return 3;
	if (password.length() < 10)
	{
		for (int i = 0; i < password.length(); i++)
			if (password[i] < '0' || password[i] > '9')
				return 4;
	}
	else
		return 4;
	if (stoi(isManager) != 0 && stoi(isManager) != 1)
		return 5;
	return 0;
}

void addEmployee(Employee e)
{
	ofstream file;
	file.open("employees.txt", ios::app);

	if (file.is_open())
	{
		file << e.id << " ";
		file << e.firstName << " ";
		file << e.lastName << " ";
		file << e.password << " ";
		file << e.isManager << " ";
		file << "\n";
	}
	file.close();
}


int createEmployee(string id, string firstName, string lastName, string password, string isManager)
{
	Employee e;
	int valid = isValidEmployee(id, firstName, lastName, password, isManager);
	if (valid == 0)
	{
		e.id = id;
		e.firstName = firstName;
		e.lastName = lastName;
		e.password = password;
		e.isManager = stoi(isManager);
		addEmployee(e);
	}
	else
		return valid;
}

void deleteEmployee(string id)
{
	ifstream file;
	ofstream temp;
	string line, idNumber;
	int index;

	file.open("employees.txt");
	temp.open("temp.txt");

	if (file.is_open() && temp.is_open())
	{
		while (!file.eof())
		{
			getline(file, line);
			index = line.find(" ");
			idNumber = line.substr(0, index);
			if (idNumber != id)
				temp << line << endl;
		}

		file.close();
		temp.close();
		remove("employees.txt");
		rename("temp.txt", "employees.txt");
	}
}

int main()
{
	createEmployee("3151515", "omer", "biton", "54848", "0");
	createEmployee("207276452", "shirel", "biton", "12345", "1");
	createEmployee("315845", "omer", "danieli", "48655", "0");

	deleteEmployee("207276452");
}