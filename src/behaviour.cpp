#include "behaviour.h"

// Constructor
Behaviour::Behaviour(int lane){}

// Destructor
Behaviour::~Behaviour(){}

// selects lane
int Behaviour::getLane(vector<vector<double>> &sensor_fusion, vector<double> &car, double &ref_vel, int lane)
{
	// Finite State Machine

	// determine lane choices based on car position
	vector<int> lanes{};
	switch(lane)
	{
		case 0:
		{
			lanes = {0, 1};
			break;
		}

		case 1:
		{
			lanes = {0, 1, 2};
			break;
		}

		case 2:
		{
			lanes = {1, 2};
			break;
		}
	}

	// calculate cost based on lane choices
	vector<double> costs;
	for(int i=0; i<lanes.size(); i++)
		costs.push_back(getCost(sensor_fusion, car, ref_vel, lanes[i]));

	// det lane with lowest cost
	double cost = 100000; // very high value
	int new_lane = lane; // current lane
	for(int i=0; i<lanes.size(); i++)
	{
		if(costs[i] < cost)
		{
			new_lane = lanes[i];
			cost = costs[i];
		}
	}

	printCostInfo(costs, lanes);

	return new_lane;
}

// det cost
double Behaviour::getCost(vector<vector<double>> &sensor_fusion, vector<double> &car, double &ref_vel, int lane)
{
	// initial cost is zero
	double cost = 0;

	// for every detected car
	for(int i=0; i < sensor_fusion.size(); i++)
	{
		// extract position and motion data for current car from sensor fusion
		double d = sensor_fusion[i][SF::SF_d];
		double s = sensor_fusion[i][SF::SF_s];
		double vx = sensor_fusion[i][SF::SF_vx];
		double vy = sensor_fusion[i][SF::SF_vy];
        double speed = sqrt(vx*vx+vy*vy) * 2.24;

		// check if the current sensed car is in the assumptious lane (to possibly change to)
		// and if its ahead of ego
		if(( d < (2+4*lane + 2) && d > (2+4*lane - 2)) && (s+7 > car[Ego::Ego_s]) && s < (car[Ego::Ego_s] + 100))
      	{
  			// if s distance to current sensed car is < 30m, then cost is applied
			cost += 1000/fabs(car[Ego::Ego_s] - s);
      	}

      	// if ego lane and assumptious lane are not the same
      	if( !( car[Ego::Ego_d] < (2+4*lane + 2) && car[Ego::Ego_d] > (2+4*lane - 2)))
      	{
      		// if there is a car behind us in the assumptious lane with higher speed than ego
      		if( ( d < (2+4*lane + 2) && d > (2+4*lane - 2)) && (s < car[Ego::Ego_s]) && (s > car[Ego::Ego_s]-30) && speed > ref_vel)
      		{
      			cout << "lane " << lane << ": there is fast traffic from behind " << speed << " vs " << ref_vel << endl;
      			cost += 1000 * (speed - ref_vel) /fabs(car[Ego::Ego_s] - s);
      		}
      	}
	}

	return cost;
}

void Behaviour::printCostInfo(vector<double> costs, vector<int> lanes)
{
	std::cout << "-------------" << std::endl;
	for(int i = 0; i < costs.size(); ++i)
	{
		std::cout << "lane: " << lanes[i] << " | cost: " << costs[i]<< std::endl;	
	}
}

