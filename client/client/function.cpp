#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>

struct client
{
	string id;
	string name;
	string id_employee;
	string phone_num;
	string email;
	string date;
	int status;
	int num_packages;
	int* packages;
	float sum;
};

void add_client(string id, string name, string id_employee, string phone_num, string email, float sum, int num_packages, int* packages)
{
	ofstream file_AddClient;
	file_AddClient.open("Client.txt", ios::app);
	if (file_AddClient.is_open())
	{
		time_t date;
		time(&date);
		file_AddClient << id << " " << name << " " << id_employee << " " << phone_num << " " << email << " " << "0" << " " << ctime(&date);
		file_AddClient << sum << endl;
		file_AddClient << num_packages << endl;
		file_AddClient << packages << endl;
	}
	else
		cout << "can not open this file" << endl;
	file_AddClient.close();
}

// 1- wrong id, 2- wrong name, 3- wrong fhone_num, 4- wrong email
int check_client(string id, string name, string id_employee, string phone_num, string email, float sum, int num_packages, int* packages)
{
	if (id.length() < 9)
		return 1;
	if (name.length() > 40)
		return 2;
	if (((phone_num.length()) != 10) || (((phone_num).substr(0, 2)) != "05"))
		return 3;
	int index = email.find('@');
	if (index != email.find_last_of('@') || index < 1)
		return 4;
	add_client(id, name, id_employee, phone_num, email, sum, num_packages, packages);
	return 0;
}



int main()
{
	int n;
	string id = "123456789";
	string name = "abc";
	string id_employee;
	string phone_num = "0512345678";
	string email = "abcd@gmail.com";
	float sum = 55.5;
	int num_packages = 1;
	int* packages =  0  ;
	n = check_client(id, name, id_employee, phone_num, email, sum, num_packages, packages);
	cout << n << endl;
	/*add_client(id, name, id_employee, phone_num, email, sum, num_packages, packages);*/
	return 0;
}