#pragma once
#include "Nodes.h";

class UniformSearch {
	public:
		
		UniformSearch() {

		}
		vector<Nodes> BreadthFirstSearch(Nodes &root) { // find the path that will lead to solution by traverse through all the nodes
			vector<Nodes> PathToSolution;
			vector<Nodes> OpenList;
			vector<Nodes> ClosedList;
			OpenList.push_back(root);
			Nodes currentNode = OpenList[0];
			bool goalfound = false;
			currentNode.ExpandMove();

			currentNode.PrintPuzzle();
		
			while (OpenList.size() > 0 && !goalfound) {
				
				//Nodes currentNode = OpenList[0];
				ClosedList.push_back(currentNode);
				OpenList.erase(OpenList.begin());

				for (int i = 0; i < currentNode.children.size(); i++) {
					
					Nodes currentChild = currentNode.children[i];
					
					if (currentChild.GoalTest()) { // check if the current child is the final solution.
					
						cout << "Goal found.";
						goalfound = true;
						// trace path to root node
						PathTrace(PathToSolution, currentChild);
						
					}

					if (!Contains(OpenList, currentChild) && !Contains(ClosedList, currentChild)) {
						OpenList.push_back(currentChild);
					}

				}
				
			}
		
			return PathToSolution;
		}
		void PathTrace(vector<Nodes> &path, Nodes n) {
			cout << "Tracing path...";
			Nodes current = n;
			path.push_back(current);
			
			while (current.parent != NULL) {
				current = *current.parent;
				path.push_back(current);
			}
		}
		static bool Contains(vector<Nodes> &list, Nodes c) {// check if they are the same puzzle
			bool contains = false;

			for (int i = 0; i < list.size(); i++) {
				if (list[i].IsSamePuzzle(c.puzzle)) {
					contains = true;
				}
			}
			return contains;
		}
};