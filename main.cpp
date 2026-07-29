#include <iostream>
#include <string>
#include "Rot13.h"

using namespace std;

int main()
{
	Rot13 rot13_converter = Rot13(); // Create an instance of the Rot13 class with default shift value of 13
	int choice = NULL;
	bool exit = true;
	string str;

	while (true && exit)
	{
		// Menu of the program
		cout << "This is a console converter with the system of rot13:";
		cout << "\n1. To convert from Text to rot13";
		cout << "\n2. To convert from rot13 to Text";
		cout << "\n3. To convert a txt file to rot13";
		cout << "\n4. To convert a txt file from rot13 to Text";
		cout << "\n0. Exit the program\n";
		cin >> choice;
		cin.ignore(); // Ignore the newline character left in the input buffer

		switch (choice)
		{
		case 0:
			cout << "\nBYE";
			exit = false;
			break;

		case 1:
			cout << "\nInsert the text you want to change: ";
			getline(cin, str);

			if (!str.empty())
			{
				cout << rot13_converter.rot13(str) << "\n\n";
			}
			else cout << "Value chosen is not valid";
			
			break;

		case 2:
			cout << "\nInsert the text you want to convert: ";
			getline(cin, str);

			if (!str.empty())
			{
				cout << rot13_converter.rot13_reverse(str) << "\n\n";
			}
			else cout << "Value chosen is not valid";
			
			break;

		case 3:
			cout << "\nInsert the path of the file you want to convert: ";
			getline(cin, str);

			if (!str.empty())
			{
				rot13_converter.convert_file_to_rot13(str);
				// cout << "File converted successfully\n\n";
			}
			else cout << "Value chosen is not valid";
			
			break;

		case 4:
			cout << "\nInsert the path of the file you want to convert: ";
			getline(cin, str);

			if (!str.empty())
			{
				rot13_converter.convert_file_from_rot13(str);
				// cout << "File converted successfully\n\n";
			}
			else cout << "Value chosen is not valid";
			
			break;
		}
	}

	return 0;
}