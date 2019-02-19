// RunLengthEncode.cpp : Defines the entry point for the console application.
//Maria Swartz
//Lab01
//Feb 18 2019

#include "stdafx.h"
// CPP program to implement run length encoding
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string line;
	string whitespace(" \t\f\v\n\r");
	vector<string> pix_list;
	int i, count, n;
	ifstream pixf_full;
	pixf_full.open("PixData.txt");
	ofstream pixf_cmpr;
	pixf_cmpr.open("PixCmprsFrank.txt");
	if (pixf_full.is_open()) cout << "Input pixf_full is open.\n";
	// Read into pix_list.
	i = 0;
	while (getline(pixf_full, line))
	{
		cout << line;
		// 2.  (Explain statement below.)
		// Add the current line to the front of the pix_list vector
		pix_list.push_back(line);
		i = i + 1;
	}
	n = pix_list.size();
	cout << "Length of pix_list is " << n << " ; i = " << i << "\n";
	// Go through list, testing whether next pixel is the same.
	for (i = 0; i < n; i++)
	{
		if (pix_list[i] != pix_list[i + 1])
			pixf_cmpr << pix_list[i] << "\n";
		else
		{
			// Pixels same.
			// 1. Write flag character and repeated pixel.  Strip pesky newline at end.
			// I had to add one the second part of the substr function because it was also striping the last char of the string.
			// I also changed the "00000000" to "flag" to reduce confusing it with a hexidecimal character
			pixf_cmpr << "flag " << pix_list[i].substr(0, (pix_list[i].find_last_not_of(whitespace) + 1));
			// 5. (Explain loop below.)
			//While we haven't reached the end of vector and the current and next item in the vector are the same, increment the counter.
			//Then move to the next element of the vector and repeat.
			count = 1;
			while (i < n - 1 && pix_list[i] == pix_list[i + 1])
			{
				count++;
				i++;
			}
			// Different pixel or end of file encountered.
			// Write output to file.
			pixf_cmpr << " " << count << "\n";
		}
	}

	//I also added closing the files even though it isn't included in the original document because
	//skipping this step can have negative impacts on the program's output. 
	pixf_full.close();
	pixf_cmpr.close();

	system("pause");

	return 0;
}
