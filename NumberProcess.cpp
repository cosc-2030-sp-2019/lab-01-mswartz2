//Lab01.Part1
//Maria Swartz
//COSC2030 - Lab Section 10
//18 Feb 2019
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::ifstream;
using std::string;
using std::endl;
using namespace std;

int main(int argc, char *argv[])
{
	/*
	if (argc != 2)
	{
	return EXIT_FAILURE;
	}
	ifstream file(argv[1]);
	if (!file)
	{
	cout << "File open failure" << endl;
	return EXIT_FAILURE;
	}
	//possible way to run instead
	*/
	string name;

	ifstream file;
	cout << "Enter a file name:";
	cin >> name;

	file.open(name);
	//open the user's file by using the file stream object

	while (!file)
	{
		cout << "Please reenter the file name (ensure that the spelling and file extension are correct):";
		cin >> name;

		file.open(name);
	}
	//Continue prompting the user until they enter a valid file name.

	int count = 0;
	double first = 0, penult = 0, last = 0, val = 0, placeholder = 0;

	int i = 0;
	while (!file.eof())
	{
		penult = placeholder;
		//here the value from the second to last from the last run is held
		placeholder = val;
		//here the value from the last run is held. Because of how the file.eof() loop works we need to use the second from the last from the previous
		//run (what would the third from the last of the current run) becasue the last val loops through twice.
		file >> val;
		//read in the next number in the file
		if (count == 0)
		{
			first = val;
			//set the first vaule to the first value that is read in
		}
		last = val;
		//set the last val to the current value
		count++;
		//increment the counter
	}
	count--;
	//decrease the counter by 1 because of how the file.eof() loop functions

	file.close();
	//close the file

	cout << "Here's some data on the file you entered:\n"
		<< "Count of Numbers: " << count << "\nFirst Number: " << first
		<< "\nPenultimate Number: " << penult << "\nLast Number: " << last << "\n";
	//print the data out to the user

	system("pause");
	return 0;
}
