#ifndef TERMS_LABELS_H
#define TERMS_LABELS_H


// indicies are better with proper names

// Sensor Fusion labels
enum SF
{
	id,
	x,
	y,
	vx,
	vy,
	s,
	d,
};

// Car localization Data labels
enum Ego
{
    	x,
  	y, 
  	s,
  	d,
  	yaw,
  	speed,
};


// Actions to be considered
enum Action
{
    CS, 
    KL, 
    PLCL, 
    PLCR, 
    LCL, 
    LCR, 
};


#endif
