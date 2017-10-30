#include "behaviour.h"

// Constructor
Behaviour::Behaviour(){}

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
	vector<int> costs;
	for(int i=0; i<lanes.size(); i++)
		costs.push_back(getCost(sensor_fusion, car, ref_vel, lanes[i]);

	// det lane with lowest cost
	int cost = 10000000; // very high value
	for(int i=0; i<lanes.size(); i++)
	{
		if(costs[i] < cost)
		{
			int new_lane = lanes[i];
			cost = costs[i];
		}
	}

	return new_lane;
}

// det cost
Behaviour::getCost(vector<vector<double>> &sensor_fusion, vector<double> &car, double &ref_vel, int lane)
{
	// initial cost is zero
	int cost = 0;

	// for every detected car
	for(int i=0; i < sensorfusion.size(); i++)
	{
		// extract position and motion data for current car from sensor fusion
		double d = sensor_fusion[i][SF::d];
		double s = sensor_fusion[i][SF::s];
		double vx = sensor_fusion[i][SF::vx];
		double vy = sensor_fusion[i][SF::vy];

		// check if the current sensed car is in the assumptious lane (to possibly change to)
		if( d < (2+4*lane + 2) && d > (2+4*lane - 2))
      	{
      		// if current sensed car is outside the ego's lane
   			// in d: > 2m
      		if(fabs(car[Ego::d] - d) > 2)
      		{
      			// if ego distance to current sensed car is
      			// in s: < 15m
      			if((fabs(car[Ego::s] - s) < 15))
      			{
      				cost += 500/fabs(car[Ego::s] - s);
      			}
      		}

      		// if current sensed car is inside the ego's lane
      		else if(fabs(car[Ego::d] - d) < 2)
      		{
      			// if ego distance to current sensed car is
      			// in s: < 30m
      			if((fabs(car[Ego::s] - s) < 30))
      			{
      				cost += 500/fabs(car[Ego::s] - s);
      			}
      		}

      		// if outside drivable lanes
      		if(car[Ego::d] < 1 || car[Ego::d] > 12)
      		{
      			cost += 5000
      		}


	}

	return cost;
}

