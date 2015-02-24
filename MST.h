#include "common.h"

#pragma once

class MST {
public:
	int** adjacentMatrix;
	int* parent;

	MST(int** adjacentMatrix);
	~MST();

	void makeTree();
	float calMean(int option);
	float calStd(int option);
	void makeTSP2();
	void makeTSP1_5();

private:
	void minimumMatching();
	void combine();

};