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
	char buffer[1000];
	string::iterator strIt;
	char currentWord[1000];
	string word;
	string inputFileName;

	memset(buffer, '\0', 1000);
	memset(currentWord, '\0', 1000);
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

	while (!indata.eof()) {

		indata.getline(buffer, 1000);
		buffer[strlen(buffer)] = ' ';
		for (i = 0; i < strlen(buffer); i++) {
			c = buffer[i];
			if (isalpha(c)) {
				currentWord[currLength++] = toupper(c);
			} else {
				string str((currentWord));
				if ( str.length()>0 ) {
				it = amount.find(str);
				if (it != amount.end())
					it->second += 1;
				else
					amount.insert(it, make_pair(str, 1));
				currLength = 0;
				memset(currentWord, '\0', 1000);
				}
			}
		}
		memset(buffer, '\0', 1000);
	}

	for (it = amount.begin(); it != amount.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	indata.close();
	return 0;
}

