#include "terms_labels.h"

using namespace std;

class Behaviour
{

private:

public:
	// Constructor
	Behaviour(int lane);

	// select lane
	int get_lane(vector<vector<double>> &sensor_fusion, vector<double> &car, double &ref_vel, int lane);

	// determine cost
 	int get_cost(vector<vector<double>> &sensor_fusion, vector<double> &car, double &ref_vel, int lane);
	
}

