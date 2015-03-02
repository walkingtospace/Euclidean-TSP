#include "point.h"

Point::Point() {
	pointNum = 0;
}

Point::~Point() {

}

void Point::generatePoint(unsigned int H, unsigned int W, unsigned int N) {
	int row=0, col=0;
	
	if(N > MAX_N || W > MAX_N || H > MAX_N) {
		cout<<"W,H,N should be less than "<<MAX_N<<endl;

		return;
	} else if(N > H && N > W) {
		cout<<"N should be less than H or W"<<endl;

		return;
	}

	pointNum = N;

	//uniform distrubution generation
	std::default_random_engine x_generator;
	std::default_random_engine y_generator;
	std::uniform_int_distribution<int> x_distribution(0,H);
	std::uniform_int_distribution<int> y_distribution(0,W);

	while(pointset.size() <= N-1) {
		pair<int,int> point(x_distribution(x_generator), y_distribution(x_generator));
		pointset.insert(point);
	}
	
	adjacentMatrix = (int**)calloc(N, sizeof(int *));

	for(int i=0; i<N ; ++i) {
		adjacentMatrix[i] = (int*)calloc(N, sizeof(int));
	}

	for(set< pair<int, int> >::iterator it = pointset.begin() ; it != pointset.end() ; ++it, ++row) {
		int x1 = (*it).first;
		int y1 = (*it).second;

		col = 0;
		for(set<pair<int, int>>::iterator that = pointset.begin() ; that != pointset.end() ; ++that, ++col) {
			int x2 = (*that).first;
			int y2 = (*that).second;

			adjacentMatrix[row][col] = getEuclideanDistance(x1, y1, x2, y2);
		}

		if(row % 100 == 0) { //show progress
			cout<<".";
		}
	}

	cout<<endl;
}

void Point::printPointset() {
	 cout<<"Generated pointset list: "<<endl;
	 for(set< pair<int,int> >::iterator it = pointset.begin() ; it != pointset.end() ; ++it) {
		 cout<<(*it).first<<" , "<<(*it).second<<endl;
	 }
	 cout<<endl;

	 cout<<"adjacency matrix: "<<endl;
	 for(int i=0; i<pointNum ; ++i) {
		 for(int j=0; j<pointNum ; ++j) {
			 cout<<adjacentMatrix[i][j]<<"  ";
		 }
		 cout<<endl;
	 }
}

int Point::getEuclideanDistance(int x1, int y1, int x2, int y2) {
	
	return sqrt(pow((double)(x1-x2),2) + pow((double)(y1-y2),2));
}

set< pair<int,int> > Point::getPointset() {

	return pointset;
}

int** Point::getAdjacentMatrix() {

	return adjacentMatrix;
}

int Point::getPointNum() {

	return pointNum;
}
