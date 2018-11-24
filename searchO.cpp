#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

void search(string input)
{
	ifstream sinput;
	bool found = 0;
	sinput.open("opp.txt");
	if (sinput.is_open())
	{
		while (!sinput.eof())
		{
			string line;
			while (getline(sinput, line)) {
				if (line.find(input, 0) != string::npos)
				{
					cout << line << endl;
					found = 1;
				}
			}
			if (sinput.eof() && (!found))
			{
				cout << "User not found!" << endl;
			}
			sinput.close();
		}
	}
	else
		cout << "File Error." << endl;
}


int main()
{
	search("shay manasherov");
	system("pause");
	return 0;
}