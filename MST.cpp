#include "MST.h"

MST::MST(int** input) {
	adjacentMatrix = input;
}

MST::~MST() {

}

void MST::makeTree() { //use Prim's algorithm or Kruskal algorithm

}

//calculate mean of all edges in the MST
float MST::calMean(int option) {
	float mean = 0.0;

	if(option == MST_1) {
		//calculate
	}else if(option == TSP2) {

	} else if(option == TSP1_5) {

	}

	return mean;
}

//calculate standard deviation of all edges in the MST
float MST::calStd(int option) {
	float std = 0.0;

	if(option == MST_1) {
		//calculate
	}else if(option == TSP2) {

	} else if(option == TSP1_5) {

	}

	return std;
}

void MST::makeTSP2() {
	//make a Eulerian tour by DFS

	//add shortcuts if a vertex has no detours.

	//calculate heuristic TSP cost
}

void MST::makeTSP1_5() {
	
	//construct minimum-weight-matching for the given MST
	minimumMatching();

	//make all edges has even degree by combining mimimum-weight matching and MST
	combine();

	//calculate heuristic TSP cost 
}

void MST::minimumMatching() { //if you choose O(n^2)
	//find minimum-weight matching for the MST. 
	
	//you should carefully choose a matching algorithm to optimize the TSP cost.
}

void MST::combine() {
	//combine minimum-weight matching with the MST to get a multigraph which has vertices with even degree
}