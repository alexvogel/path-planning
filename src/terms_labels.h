#ifndef TERMS_LABELS_H
#define TERMS_LABELS_H


// Labels for Sensor Fusion
enum SF
{
	SF_id,
	SF_x,
	SF_y,
	SF_vx,
	SF_vy,
	SF_s,
	SF_d,
};

// Labels for Ego Car
enum Ego
{
    Ego_x,
  	Ego_y, 
  	Ego_s,
  	Ego_d,
  	Ego_yaw,
  	Ego_speed,
};


// Possible actions
enum Action
{
    A_CS, 
    A_KL, 
    A_PLCL, 
    A_PLCR, 
    A_LCL, 
    A_LCR, 
};


#endif
