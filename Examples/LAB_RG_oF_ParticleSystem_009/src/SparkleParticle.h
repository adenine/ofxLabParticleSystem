#ifndef _SPARKLEPARTICLE
#define _SPARKLEPARTICLE

/*
 *  SparkleParticle.h
 *  openFrameworks
 *
 *  Created by Joshua Walton on 12/5/08.
 *  Copyright 2008 Lab at Rockwell Group. All rights reserved.
 *
 */

#include "Agent.h"

class SparkleParticle : public Agent {
public:
	SparkleParticle(ofxVec3f pos, int _timeToLive);
	virtual ~SparkleParticle(){};
	void update();
	void draw();
	void recycle();
};

#endif