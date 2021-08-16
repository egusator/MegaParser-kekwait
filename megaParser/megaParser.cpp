#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
#define bufferSize 1000
int main(int argc, char **argv) {

	map<string, int> amount;
	map<string, int>::iterator it;
	vector < pair <string, int> > forSort;
	vector < pair <string, int> >::iterator sortIter;
	ifstream indata;

	struct compareClass1 {
	  bool operator() (pair<string, int> pair1,pair<string, int> pair2) {
		  return pair1.second > pair2.second;
	  }
	} valueComparator;
	struct compareClass2 {
	  bool operator() (pair<string, int> pair1,pair<string, int> pair2) {
		  return pair1.first < pair2.first;
	  }
	} keyComparator;

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
		forSort.push_back(make_pair(it->first, it->second));
	}

	std::sort(forSort.begin(), forSort.end(), valueComparator);


	int prevAmount = 0;
	vector < pair <string, int> >::iterator prevIter;

	for (sortIter = forSort.begin(); sortIter != forSort.end(); sortIter++) {
		if (prevAmount == 0) {
			prevAmount = sortIter->second;
			prevIter = sortIter;
		} else if (sortIter->second != prevAmount) {
			std::sort(prevIter, sortIter, keyComparator);
			prevAmount = sortIter->second;
			prevIter=sortIter;
		}
	}
	std::sort(prevIter, sortIter, keyComparator);

	for (sortIter = forSort.begin(); sortIter != forSort.end(); sortIter++) {
				cout << sortIter->first << " " << sortIter->second << endl;
			}


	indata.close();
	return 0;
}

