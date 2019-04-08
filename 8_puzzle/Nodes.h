#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Nodes {
	private:
		
	public:
		
		vector<Nodes> children;
		
		Nodes *parent;
		
		vector<string> puzzle;
		int col = 3;
		
		int x = 0;
		
		Nodes(vector<string> &p) {// Constructor that set the puzzle
			SetPuzzle(p);
			
		}

		void SetPuzzle(vector<string> &p) {//setter
			
			puzzle = p;
		}
		void ExpandMove(){
			
			
			for (int i = 0; i < puzzle.size(); i++) {// set the source node to "E"
				if (puzzle[i] == "E")
					x = i;
				
			}
		
			
			MoveToRight(puzzle, x);
			
			MoveToLeft(puzzle, x);
			
			MoveToUp(puzzle, x);
		
			MoveToDown(puzzle, x);
			
		}
	
		void MoveToRight(vector<string> &p, int i) {// Move source node to right by swapping same to the other move functions
			if (i%col < col - 1) {
				vector<string> pc(9);
				CopyPuzzle(pc, p);
				string temp = pc[i + 1];
				pc[i + 1] = pc[i];
				pc[i] = temp;
				Nodes child = Nodes(pc);
				children.push_back(child);
				
				child.parent = this;
				
				
			}
		
			
			
		}
		void MoveToLeft(vector<string> &p, int i) {
			if (i%col > 0) {
				vector<string> pc(9);
				CopyPuzzle(pc, p);
				string temp = pc[i - 1];
				pc[i - 1] = pc[i];
				pc[i] = temp;

				Nodes child = Nodes(pc);
				children.push_back(child);
				child.parent = this;
				
				
			}
			
			
		}
		void MoveToUp(vector<string> &p, int i) {
			if (i-col >= 0) {
				vector<string> pc(9);
				CopyPuzzle(pc, p);
				string temp = pc[i - 3];
				pc[i - 3] = pc[i];
				pc[i] = temp;

				Nodes child = Nodes(pc);
				children.push_back(child);
				child.parent = this;
				
					
			}
		
			
		}
		void MoveToDown(vector<string> &p, int i) {
			if (i + col < puzzle.size()) {
				vector<string> pc(9);
				CopyPuzzle(pc, p);
				
				string temp = pc[i + 3];
				pc[i + 3] = pc[i];
				pc[i] = temp;

				Nodes child = Nodes(pc);
				children.push_back(child);
				child.parent = this;
				
				
			}
		
			
		}
		
		void PrintPuzzle() {// print out the puzzle in the matrix format
			cout << endl;
			int m = 0;
			for (int i = 0; i < col; i++) {
				for (int j = 0; j < col; j++) {
					cout << puzzle[m] + " ";
					m++;
				}
				
				cout << endl;
			}
		}
		bool IsSamePuzzle(vector<string> &p) {// check if the puzzle is the same
			bool samePuzzle = true;
			for (int i = 0; i < p.size();i++) {
				if (puzzle[i] != p[i]) {
					samePuzzle = false;
				}
			}
			return samePuzzle;
		}
		void CopyPuzzle(vector<string> &a, vector<string> &b) {// copy 
			for (int i = 0; i < b.size(); i++) {

				a[i] = b[i];
			}
		}
		bool GoalTest() {// return true if puzzle == goal
			
			
			vector<string> goal = { "1","2","3","4","5","6","7","8","E" };
			return puzzle == goal;
			
		}



};
