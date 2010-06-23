#ifndef _BEHAVIOR
#define _BEHAVIOR

/*
 *  Behavior.h
 *  openFrameworks
 *
 *  Created by Joshua Walton on 12/6/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */
 
// #include "ofMain.h"
 #include "ofxVectorMath.h"
 
class Behavior {
public:
	Behavior();
	void apply();
};
 
 
class AddForce : public Behavior {
public:
	float x, y, z;
	ofxVec3f force;
	AddForce(ofxVec3f _force);
	void apply(ofxVec3f * _acc);
};

#endif