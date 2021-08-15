#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <stdio.h>
#include <map>
using namespace std;
#define bufferSize 1000
int main(int argc, char **argv) {

	map<string, int> amount;
	map<string, int>::iterator it;
	ifstream indata;
	char c;
	int i = 0, currLength = 0;
	string buffer;
	string::iterator strIt;
	string currentWord;
	string inputFileName;

	if (argc != 2) {
		printf("\n using: %s <input-file-name> \n", argv[0]);
		return 1;
	}

	inputFileName = argv[1];

	indata.open(inputFileName); // opens the file

	if (!indata) { // file couldn't be opened
		cerr << "Error: file could not be opened" << endl;
		exit(1);
	}
	cout << buffer.length() << endl;
	while (!indata.eof()) {

		indata >> buffer;
		for (i = 0; i < buffer.length();i++) {
			c = buffer[i];
			if (isalpha(c)) {
				currentWord[currLength++] = c;
				cout << currentWord << endl;
			} else {
				it = amount.find(currentWord);
				if (it != amount.end())
					it->second += 1;
				else
					amount.insert( { currentWord, 0 });
				currLength = 0;
				cout<<"ya govno"<<endl;
			}
			i = 0;

		}
	}
	it = amount.find(currentWord);
	if (it != amount.end())
		it->second += 1;
	else
		amount.insert( { currentWord, 0 });
	for(it = amount.begin(); it != amount.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}

	indata.close();
	//cout << "End-of-file reached.." << endl;
	return 0;
}

