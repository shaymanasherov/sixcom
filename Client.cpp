#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

struct client {
	string id;
	string firstName;
	string lastName;
	string phoneNum;
	string email;
	bool activation;
	int * saleOpportunities;
};

client inputClient()
{
	client c;
	cout << "Enter id" << endl;
	cin >> c.id;
	cout << "Enter first name" << endl;
	cin >> c.firstName;
	cout << "Enter last name" << endl;
	cin >> c.lastName;
	cout << "Enter phone num" << endl;
	cin >> c.phoneNum;
	cout << "Enter email" << endl;
	cin >> c.email;
	cout << "Enter activation" << endl;
	cin >> c.activation;
	
	return c;
}

bool isValid(client temp, int * arr)
{
	bool valid;
	int index;
	string phone;

	if ((temp.id).length() > 9)
	{
		cout << "Id is not valid";
		valid = false;
		arr[0] = 1;
	}

	if ((temp.firstName).length() > 20)
	{
		cout << "First name is not valid";
		valid = false;
		arr[1] = 1;
	}

	if ((temp.id).length() > 9)
	{
		cout << "Last name is not valid";
		valid = false;
		arr[2] = 1;
	}

	if ((temp.phoneNum).length() != 10 || (temp.phoneNum).substr(0, 2) != "05")
	{
		cout << "Phone num is not valid";
		valid = false;
		arr[3] = 1;
	}

	index = (temp.email).find('@');
	if (index != (temp.email).find_last_of('@') || index < 1)
	{
		cout << "Email is not valid";
		valid = false;
		arr[4] = 1;
	}

	return valid;
}

bool createClient(client c)
{
	int * arr = new int[5];
	while (!isValid(c, arr))
	{
		if (arr[0] == 1)
			cin >> c.id;
		if (arr[1] == 1)
			cin >> c.firstName;
		if (arr[2] == 1)
			cin >> c.lastName;
		if (arr[3] == 1)
			cin >> c.phoneNum;
		if (arr[4] == 1)
			cin >> c.email;
	}

	ofstream file;
	file.open("clients.txt");
	file << "id: " << c.id;
	file << "first name: " << c.firstName;
	file << "last name: " << c.lastName;
	file << "phone num: " << c.phoneNum;
	file << "email: " << c.email;
	file << "activation: " << c.activation;
	file << "\n";
	file.close();
}

 
