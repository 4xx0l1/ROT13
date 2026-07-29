#include "Rot13.h"

Rot13::Rot13()
{
	// Default constructor
	this->shift = 13; // Set the default shift value to 13 for rot13
}

Rot13::Rot13(int shift)
{
	// Constructor with parameter 
	// This constructor can be used to set a custom shift value if needed
	// However, in this implementation, we are using a fixed shift of 13 for rot13
	this->shift = shift;
}

void Rot13::set_shift(int shift)
{
	this->shift = shift; // Set the shift value
}

int Rot13::get_shift()
{
	return this->shift; // Return the shift value
}

// Function to convert text in rot13 to normal text
string Rot13::rot13(const std::string& str)
{
	string s = str;

	for (int i = 0; i < s.size(); i++)
	{
		if (s.at(i) >= 'a' && s.at(i) <= 'm' || s.at(i) >= 'A' && s.at(i) <= 'M')
		{
			char c = char(int(s.at(i)) + 13);
			s.at(i) = c;
		}
		else if (s.at(i) >= 'n' && s.at(i) <= 'z' || s.at(i) >= 'N' && s.at(i) <= 'Z')
		{
			char c = char(int(s.at(i)) - 13);
			s.at(i) = c;
		}
	}

	return s;
}

// Function to convert a text to rot13
string Rot13::rot13_reverse(const string& str)
{
	string s = str;

	for (int i = 0; i < s.size(); i++)
	{
		if (s.at(i) >= 'a' && s.at(i) <= 'm' || s.at(i) >= 'A' && s.at(i) <= 'M')
		{
			char c = char(int(s.at(i)) + 13);
			s.at(i) = c;
		}
		else if (s.at(i) >= 'n' && s.at(i) <= 'z' || s.at(i) >= 'N' && s.at(i) <= 'Z')
		{
			char c = char(int(s.at(i)) - 13);
			s.at(i) = c;
		}
		
		if (s.at(i) == ' ')
		{
			s.at(i) = ' ';
		}
	}

	return s;
}

string Rot13::rot_shift(const string& str, int shift)
{
	this->shift = shift; // Set the shift value
	string s = str;

	for (int i = 0; i < s.size(); i++)
	{
		if (s.at(i) >= 'a' && s.at(i) <= 'm' || s.at(i) >= 'A' && s.at(i) <= 'M')
		{
			char c = char(int(s.at(i)) + shift);
			s.at(i) = c;
		}
		else if (s.at(i) >= 'n' && s.at(i) <= 'z' || s.at(i) >= 'N' && s.at(i) <= 'Z')
		{
			char c = char(int(s.at(i)) - shift);
			s.at(i) = c;
		}
	}

	return s;
}

string Rot13::rot_shift_reverse(const string& str, int shift)
{
	this->shift = shift; // Set the shift value
	string s = str;

	for (int i = 0; i < s.size(); i++)
	{
		if (s.at(i) >= 'a' && s.at(i) <= 'm' || s.at(i) >= 'A' && s.at(i) <= 'M')
		{
			char c = char(int(s.at(i)) - shift);
			s.at(i) = c;
		}
		else if (s.at(i) >= 'n' && s.at(i) <= 'z' || s.at(i) >= 'N' && s.at(i) <= 'Z')
		{
			char c = char(int(s.at(i)) + shift);
			s.at(i) = c;
		}
	}

	return s;
}

void Rot13::convert_file_to_rot13(const string& input_file)
{
	ifstream file(input_file); // Open the input file

	if (!file.is_open())
	{
		cout << "Error opening file: " << input_file << endl;
		return;
	}

	while (!file.eof())
	{
		string line;
		getline(file, line); // Read each line from the file
		string converted_line = rot13(line); // Convert the line to rot13
		ofstream output_file("output.txt", ios::app); // Open the output file in append mode
		output_file << converted_line << endl; // Print the converted line to the output file
		output_file.close(); // Close the output file
	}
}

void Rot13::convert_file_from_rot13(const string& input_file)
{
	ifstream file(input_file); // Open the input file

	if (!file.is_open())
	{
		cout << "Error opening file: " << input_file << endl;
		return;
	}

	while (!file.eof())
	{
		string line;
		getline(file, line); // Read each line from the file
		string converted_line = rot13_reverse(line); // Convert the line from rot13 to normal text
		ofstream output_file("output.txt", ios::app); // Open the output file in append mode
		output_file << converted_line << endl; // Print the converted line to the output file
		output_file.close(); // Close the output file
	}
}

void Rot13::convert_file_with_shift(const std::string& input_file, int shift)
{

}

void Rot13::convert_file_from_shift(const std::string & input_file, int shift)
{}
