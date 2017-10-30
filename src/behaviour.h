#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

#include <math.h>
#include <iostream>
#include <thread>
#include <vector>
#include <string>


#include "terms_labels.h"

using namespace std;

class Behaviour
{

private:

public:
	// Constructor
	Behaviour(int lane);

	// Destructor
	virtual ~Behaviour();

	// select lane
	int getLane(vector<vector<double>> &sensor_fusion, vector<double> &car, double &ref_vel, int lane);

	// determine cost
 	int getCost(vector<vector<double>> &sensor_fusion, vector<double> &car, double &ref_vel, int lane);

 	void printCostInfo(vector<int> costs, vector<int> lanes);
};

#endif
