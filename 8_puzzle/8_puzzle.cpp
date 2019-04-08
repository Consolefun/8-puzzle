//William Hoang
//02/09/2019
// CS 461
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Nodes.h";
#include "UniformSearch.h";
#include<queue>
using namespace std;

bool solvable(vector<string> a) {// Check if the matrices are solvable
	int count = 0;
	for (int i = 0; i < a.size(); i++) {
		for (int j = i+1; j < a.size(); j++) {
			if (a[i] != "E" && a[i] > a[j]) {
				count++;
			}
			
		}

	}
	if (count % 2 == 0) {
		
		return true;
		
	}
	else {
		
		return false;
		
	}
	
}

void main() {

	
	UniformSearch ui = UniformSearch();
	
	vector<string> arr(9);
	ifstream file;
	file.open("prog1_input.txt");
	int data = 0;
	
	if (!file.is_open()) {
		cout << "File can't be open" << endl;

	}
	else {
		file >> data;
		string blank;
		cout << endl;
		int m = 0;// read in the size
		for (int k = 0; k < data; k++) {
			for (int i = 0; i < arr.size(); i++) {

				file >> arr[i];
				
			}
			getline(file, blank);// Read in the empty space between matrices
			Nodes *root;
			root = new Nodes(arr);
			cout << endl;
			
			if (solvable(root->puzzle)) {

				vector<Nodes> solution = ui.BreadthFirstSearch(*root);

				for (int i = 0; i < solution.size(); i++) {

					solution[i].PrintPuzzle();
				}

			}
			else {

				cout << " No solution found" << endl;
			}
			
			
		}	
	}
	file.close();

	system("pause");
}