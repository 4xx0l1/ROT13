#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

static class Rot13
{
private:
	int shift;

public:
	Rot13();
	Rot13(int shift); // costruttore 

	void set_shift(int shift); // set shift value
	int get_shift(); // get shift value

	// Function to convert text in rot13 
	string rot13(const std::string& str);

	// Function to convert a text wtitten in rot13 to a normal text
	string rot13_reverse(const string& str);

	// Function to shift a character by the specified shift value
	string rot_shift(const string& str, int shift);

	// Function to shift a character by the specified shift value in reverse
	string rot_shift_reverse(const string& str, int shift);

	// Function to convert a text to rot47
	string rot47(const string& str);

	// Function to convert a text written in rot47 to a normal text
	string rot47_reverse(const string& str);

	// Function to convert a text file to rot13, it rewrites the file with the converted text
	void convert_file_to_rot13(const std::string& input_file);

	// Function to convert a text file from rot13 to normal text, it rewrites the file with the converted text
	void convert_file_from_rot13(const std::string& input_file);
};